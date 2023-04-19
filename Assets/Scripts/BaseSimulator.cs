using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System;
using UnityEngine.UI;
using JetBrains.Annotations;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;
using UnityEditor;
using UnityVolumeRendering;
using TMPro;
using UnityEngine.Events;

using static VoxelGrid;

/*
    Base script for running the simulation.
    Offers functionality for reading in data, animating the data and toggling the transparency of
    the brain and skull. Adapted from the VRSimulator written by Marcus Holmberg, M�ns Nyman, L�a Pr�mont
    and Mahmoud Sherzad.
*/
public class BaseSimulator : MonoBehaviour
{
    [Serializable]
    public class GroundTruth
    {
        const string savePath = "/GroundTruth.json";

        public List<string> trajectories = new List<string>();
        public List<Quaternion> angleGT = new List<Quaternion>();
        public List<Vector3> densityGT = new List<Vector3>();
        public List<Vector3> POIGT = new List<Vector3>();

        public void save()
        {
            string data = JsonUtility.ToJson(this);
            System.IO.File.WriteAllText(Application.dataPath + savePath, data);
            Debug.Log(data);
        }

        public static GroundTruth load()
        {
            string text = File.ReadAllText(Application.dataPath + savePath);
            Debug.Log(text);
            GroundTruth gt = JsonUtility.FromJson<GroundTruth>(text);
            Debug.Log(JsonUtility.ToJson(gt));
            return gt;
        }

        public void setDensityGT(string trajectory, Vector3 pos)
        {
            int i = trajectories.IndexOf(trajectory);
            if (i != -1)
            {
                densityGT[i] = pos;
            } else
            {
                densityGT.Add(pos);
                angleGT.Add(Quaternion.identity);
                POIGT.Add(Vector3.zero);
            }

        }

        public Quaternion getAngleGT(string trajectory)
        {
            int i = trajectories.IndexOf(trajectory);
            if (i != -1 && angleGT[i] != Quaternion.identity)
            {
                return angleGT[i];
            }
            Debug.LogWarning("No angle Ground Truth for trajectory " + trajectory);
            return Quaternion.identity;
        }
        public Vector3 getDensityGT(string trajectory)
        {
            int i = trajectories.IndexOf(trajectory);
            if (i != -1 && densityGT[i] != Vector3.zero)
            {
                return densityGT[i];
            }
            Debug.LogWarning("No density Ground Truth for trajectory " + trajectory);
            return Vector3.zero;
        }
    }

    protected  class Data
    {
        // The path to the tsv file the data was loaded from
        public string path;

        // size of data
        public int fileSize;

        public GameObject markers;

        // The reference markers instantiated for this data
        public GameObject cathTop;
        public GameObject cathTL;
        public GameObject cathTR;
        public GameObject cathBL;
        public GameObject cathBR;
        public GameObject skullTL;
        public GameObject skullTR;
        public GameObject skullBL;
        public GameObject skullBR;
        public GameObject skullBrow;

        // References to the barycenters of all of the markers
        public GameObject cathCenter;
        public GameObject skullCenter;
        public Vector3 cathTipOffset;
        public Quaternion cathCenterRot;
        public Quaternion skullCenterRot;

        public GameObject testTip;

        // The line renderer of the data
        public LineRenderer lineRenderer;

        public Vector3 cathRight = Vector3.one;
        public Vector3 cathUp = Vector3.one;

        //arrays with data from each row
        public float[] field, time;
        public float[,] headTopLeft, headTopRight, headBottomLeft, headBottomRight, headHole, headBrow,
                cathTip, cathTopLeft, cathTopRight, cathBottomLeft, cathBottomRight, cathEnd;
        public Vector3[] modelTip; // Calculated from the data by pre-runing the simulation
        public float[] modelTipSpeed; // Calculated from the data by pre-runing the simulation
        public Color[] modelTipCol; // Calculated from the data by pre-runing the simulation

        public Vector3 tipHighestDensityPos;

        //coordinates for 3D objects transform update
        public float x1, x2, x3, x4, x5, x6, x7, x8, x9, x10,
            y1, y2, y3, y4, y5, y6, y7, y8, y9, y10,
            z1, z2, z3, z4, z5, z6, z7, z8, z9, z10;

        public bool moreData;
    }

    public enum TASK
    {
        DENSITY,
        ANGLE,
        POI,
    }
    public enum VIZ
    {
        NONE,
        TRAIL,
        DENSITY,
    }

    public UnityEvent simulationStarted;

    [Header("Reference Markers Prefab")]
    public GameObject markers;
    public Transform skullPosition;
    public Transform world;

    [Header("GUI")]
    public Text[] FrameStuff;
    public Slider slider; //slider to control the animation speed
    public bool sliderSelected;
    public Button playButton; //play&pause button
    public Button directionButton;
    public bool fastForward;
    public Button forwardButton;
    public bool fastBackward;
    public Button backwardButton;
    public Button restartButton;
    public GameObject observer;
    public TMP_Text stateText;

    [Header("Experiment")]
    public bool showGroundTruth;
    public TASK task = TASK.DENSITY;
    public GameObject groundTruthMarker;

    [Header("Visualization")]
    public bool applyWarpData = true;
    public bool applyPathTrace = true;
    public bool applySpaceTimeDensity = false;
    public bool normalize = true;
    public bool applyAlign = true;
    public bool keepSkullStill = false;
    public int numberOfPoints;
    public float normalizationFactor = 1000.0f;
    public string transferFunction = "Assets/TransferFunctions/greyscale.tf";

    [Header("Path Trace")]
    public Gradient speedGradient;
    public float maxSpeed = 0.1f;

    [Header("4D-Time Density")]
    public int voxelsPerDim = 1000;
    public float gridLength = 10.0f;
    public float kernelSize = 1.0f;
    private VoxelGrid voxelGrid;
    protected VolumeRenderedObject volObjScript;
    protected GameObject volGO;
    private Vector3 minTip, maxTip, rangeTip, squareRangeTip, scaleTip;

    [Header("Simulation")]
    public bool enableSimulation = true;
    public string[] paths; //"Assets/Recordings/catheter005.txt"; // List of paths to be loaded
    public float maxPlaybackSpeed = 50f;
    protected float timeToCall;
    protected float timeDelay = 1.0f; //the code will be run every 2 seconds
    protected const string separator = "\t"; //tab separation string
    protected int index = 0, prevIndex = 0;
    protected int maxFileSize = -1;
    protected bool moreData;
    protected bool paused;
    protected bool rewind;
    protected float playBackSpeed = 20f;
    protected float timer = 0;
    protected bool transparencyEnabled;
    protected List<Data> dataList;
    protected Vector3 tipOffset = new Vector3(0.0f, -0.22304f, -0.002f); // Constant for the length from cathCenter to the bottom tip of the catheter
    

    [Header("Rendered Representation")]
    private GameObject phantomSkull;
    private GameObject phantomBrain;
    protected Material solidSkullMat;
    protected Material solidBrainMat;

    public Material transparentSkullMat;
    public Material transparentBrainMat;

    //Custom transform coordinates for the skull
    protected Dictionary<String, Vector3> skullOffsetPos = new Dictionary<String, Vector3> {
        {"catheter001",new Vector3(-0.939999998f,-14.1099997f,5.55000019f)}, //file : cathether001 NOT WELL ALIGNED
        {"catheter002", new Vector3(-1.88f,-13.8599997f,4.67000008f) }, //file : cathether002 NOT WELL ALIGNED
        {"catheter003", new Vector3(-1.10000002f,-14.1099997f,6.32000017f)}, //file : cathether003
        {"catheter004",new Vector3(-1.28999996f,-13.4799995f,6.07999992f) }, //file : cathether004 NOT WELL ALIGNED
        {"catheter005",new Vector3(-1.08000004f,-13.6199999f,6.5f) }, //file : cathether005
        {"catheter006",new Vector3(-0.639999986f,-12.6899996f,5.57000017f) }, //file : cathether006
        {"catheter007",new Vector3(-0.850000024f,-14.1099997f,5.6500001f) } //file : cathether007
        };
    protected Dictionary<String, Vector3> skullOffsetRot = new Dictionary<String, Vector3> {
        {"catheter001",new Vector3(38.116478f,177.862823f,358.404968f)}, //file : cathether001
        {"catheter002", new Vector3(42.3742065f,181.589996f,3.92515182f) }, //file : cathether002
        {"catheter003", new Vector3(43.9130974f,177.666306f,358.909271f) }, //file : cathether003
        {"catheter004",new Vector3(42.3742065f,181.589996f,3.92515182f) }, //file : cathether004
        {"catheter005",new Vector3(42.3742065f,181.589996f,3.92515182f) }, //file : cathether005
        {"catheter006",new Vector3(42.3742104f,181.589996f,5.4209547f) }, //file : cathether006
        {"catheter007",new Vector3(41.510006f,177.755005f,359.040009f) } //file : cathether007
        };
    protected Dictionary<String, Vector3> offsetPos = new Dictionary<String, Vector3> {
        {"catheter001", new Vector3(0.036f, 0.866f, -0.283f)}, 
        {"catheter002", new Vector3(0.034f, 0.864f, -0.283f)},
        {"catheter003", new Vector3(0.038f, 0.866f, -0.288f)},
        {"catheter004", new Vector3(0.035f, 0.861f, -0.293f)},
        {"catheter005", new Vector3(0.030f, 0.860f, -0.294f)}, 
        {"catheter006", new Vector3(0.006f, 0.868f, -0.252f)},
        {"catheter007", new Vector3(0.007f, 0.866f, -0.252f)} 
        };

    private Dictionary<string, int> anglePivotFrameIndex = new Dictionary<string, int>
    {
        { "trajectory003", 125 },
    };

    public GroundTruth groundTruth;

    protected virtual void init()
    {
        // Should be overriden if a specific implementation needs to initialise something
    }

    public void StartSimulation(String[] paths, TASK task, VIZ visualization)
    {
        applyPathTrace = false;
        applySpaceTimeDensity = false;
        if(visualization == VIZ.TRAIL)
            applyPathTrace = true;
        else if(visualization == VIZ.DENSITY)
            applySpaceTimeDensity = true;

        this.task = task;


        if (dataList != null)
        {
            foreach (Data data in dataList)
            {
                Destroy(data.markers);
            }
        }
        if(volGO != null)
        {
            Destroy(volGO);
        }
        if(volObjScript != null)
        {
            Destroy(volObjScript);
        }

        this.paths = paths;

        paused = false;

        timeToCall = timeDelay;

        // Read in all specified data
        dataList = new List<Data>();
        foreach (String path in paths)
        {
            dataList.Add(extractData(path));
        }
        maxFileSize = warpData(dataList);
        slider.maxValue = maxFileSize;
        foreach (Data data in dataList)
        {
            findTrueTip(data);
        }
        findMinMax(dataList);
        foreach (Data data in dataList)
        {
            //findHighestDensity(data, observer.GetComponent<ExperimentInteractionHandler>().markerSize / 2);
        }
        moreData = true;

        // Sets the skull and brain to have the solid material
        SetInitialColors();

        SkullTransparent();
        BrainTransparent();
        transparencyEnabled = true;

        if (applySpaceTimeDensity)
        {
            calculateSpaceTimeDensity(dataList);
            visualizeDensity();
        }

        simulationStarted.Invoke();
    }

    // Start is called before the first frame update
    void Start()
    {
        groundTruth = GroundTruth.load();

        groundTruthMarker.SetActive(showGroundTruth);

        //Button btn = playButton.GetComponent<Button>();
        if(playButton != null)
            playButton.onClick.AddListener(playPause);
        if (directionButton != null)
            directionButton.onClick.AddListener(ChangeDirection);
        if (restartButton != null)
            restartButton.onClick.AddListener(RestartScene);


        // Initialize Simulation parameters
        paused = true;
        rewind = false;

        init();
    }

    protected virtual void handleInput()
    {
        // Should be overriden with the implementation specific controlls
    }

    protected void Update()
    {

        /*if (Input.GetKey(KeyCode.Escape))
        {
            Debug.Log("Quit");
            UnityEditor.EditorApplication.isPlaying = false;
        }*/

        handleInput();

        // The slider visible in the scene displays current playback speed

        if (slider && !sliderSelected)
        {
            slider.value = index;
        }
        else
        {
            index = Mathf.RoundToInt(slider.value);
            
        }
        // Update the GUI
        if (FrameStuff[0])
        {
            FrameStuff[0].text = "Frame: " + index + " / " + maxFileSize;
        }

        if (sliderSelected)
        {
            foreach (Data data in dataList)
            {
                simulateData(data);
            }
        }
        SetStateText();
    }
    public void SliderSelected()
    {

        /*paused = true;
        Debug.Log("EA");
        sliderSelected = true;*/
    }

    public void SliderDeselect()
    {
        /*Debug.Log("Unity");
        sliderSelected = false;*/
    }

    protected void findTrueTip(Data data)
    {
        data.modelTip = new Vector3[data.fileSize];
        data.modelTipSpeed = new float[data.fileSize];
        data.modelTipCol = new Color[data.fileSize];

        // Pre-run the simulation and sample the position of the tip at each index
        for (int i = 0; i < data.fileSize; i++)
        {
            //x coordinate
            float x1 = data.cathTip[i, 0];
            float x2 = data.cathTopLeft[i, 0];
            float x3 = data.cathTopRight[i, 0];
            float x4 = data.cathBottomLeft[i, 0];  
            float x5 = data.cathBottomRight[i, 0];  
            float x6 = data.headTopLeft[i, 0];  
            float x7 = data.headTopRight[i, 0];  
            float x8 = data.headBottomLeft[i, 0];  
            float x9 = data.headBottomRight[i, 0];  
            float x10 = data.headBrow[i, 0];  

            //y coordinate
            float y1 = data.cathTip[i, 1];  
            float y2 = data.cathTopLeft[i, 1];  
            float y3 = data.cathTopRight[i, 1];  
            float y4 = data.cathBottomLeft[i, 1];  
            float y5 = data.cathBottomRight[i, 1];  
            float y6 = data.headTopLeft[i, 1];  
            float y7 = data.headTopRight[i, 1];  
            float y8 = data.headBottomLeft[i, 1];  
            float y9 = data.headBottomRight[i, 1];  
            float y10 = data.headBrow[i, 1];  

            //z coordinate
            float z1 = data.cathTip[i, 2];  
            float z2 = data.cathTopLeft[i, 2];  
            float z3 = data.cathTopRight[i, 2];  
            float z4 = data.cathBottomLeft[i, 2];  
            float z5 = data.cathBottomRight[i, 2];  
            float z6 = data.headTopLeft[i, 2];  
            float z7 = data.headTopRight[i, 2];  
            float z8 = data.headBottomLeft[i, 2];  
            float z9 = data.headBottomRight[i, 2];  
            float z10 = data.headBrow[i, 2];  

            Vector3 cathTL = new Vector3(x2, y2, z2);
            Vector3 cathTR = new Vector3(x3, y3, z3);
            Vector3 cathBR = new Vector3(x5, y5, z5);


            //Align orientation of the catheter
            Vector3 cathRight = cathTL - cathTR;
            Vector3 cathUp = cathTR - cathBR - Vector3.Project(cathTR - cathBR, cathRight);
            Quaternion cathCenterRot = Quaternion.LookRotation(cathRight, cathUp);

            Vector3 cathCenter = new Vector3((x1 + x2 + x3 + x4 + x5) / 5.0f, (y1 + y2 + y3 + y4 + y5) / 5.0f, (z1 + z2 + z3 + z4 + z5) / 5.0f);

            if (keepSkullStill)
            {
                Vector3 skullPos = new Vector3((x6 + x7 + x8 + x9 + x10) / 5.0f, (y6 + y7 + y8 + y9 + y10) / 5.0f, (z6 + z7 + z8 + z9 + z10) / 5.0f);
                data.modelTip[i] = cathCenter + cathCenterRot * data.cathTipOffset - skullPos + skullPosition.position;
            } else
            {
                data.modelTip[i] = cathCenter + cathCenterRot * data.cathTipOffset;
            }

        }

        for (int i = 0; i < data.fileSize; i++)
        {
            const float timeBetweenMeasures = 0.05f;

            Vector3 pos = data.modelTip[i];
            Vector3 prevPos = pos;
            Vector3 nextPos = pos;

            if(i > 0)
            {
                prevPos = data.modelTip[i - 1];
            }
            if(i < data.fileSize - 1)
            {
                nextPos = data.modelTip[i + 1];
            }

            float speed = (Vector3.Distance(pos, prevPos) + Vector3.Distance(pos, nextPos)) / (2 * timeBetweenMeasures);
            data.modelTipSpeed[i] = speed;
            data.modelTipCol[i] = speedGradient.Evaluate(Math.Min(speed, maxSpeed)/maxSpeed);
        }

    }

    //Good enough. Should be no ambigous points, and just make sure the scale measuring participants isn't finer than this.
    private void findHighestDensity(Data data, float sphereRadius)
    {
        float stepSize = sphereRadius / 10;
        float sqrRadius = sphereRadius * sphereRadius; //Used instead of radius to speed up distance calculations

        Vector3Int numSteps = Vector3Int.CeilToInt(rangeTip / stepSize);

        List<Vector3> highestDensityPoses = new List<Vector3>();
        int maxNumPoints = 0;

        for (int x = 0; x < numSteps.x; x++)
        {
            for (int y = 0; y < numSteps.y; y++)
            {
                for (int z = 0; z < numSteps.z; z++)
                {
                    Vector3 pos = new Vector3(minTip.x + stepSize * x, minTip.y + stepSize * y, minTip.z + stepSize * z);

                    int numPoints = 0;
                    foreach(Vector3 point in data.modelTip)
                    {
                        if ((pos - point).sqrMagnitude < sqrRadius)
                        {
                            numPoints++;
                        }
                    }
                    if(numPoints == 0)
                    {
                        //Tiny optimization
                        continue;
                    }
                    if(numPoints > maxNumPoints)
                    {
                        highestDensityPoses.Clear();
                        maxNumPoints = numPoints;
                    } 
                    if(numPoints >= maxNumPoints)
                    {
                        highestDensityPoses.Add(pos);
                    }
                }
            }
        }


        groundTruthMarker.transform.position = highestDensityPoses[0];
        data.tipHighestDensityPos = highestDensityPoses[0];

    }

    protected void calculateSpaceTimeDensity(List<Data> dataList)
    {
        //Debug.Log("Calculating space time density");
        voxelGrid = new VoxelGrid(voxelsPerDim + 2, gridLength); // Set all voxels in the result to have 0 density
        VoxelGrid trajectoryDensity = new VoxelGrid(voxelsPerDim + 2, gridLength); // Create a temporary grid with all densities initialized to 0

        //float center = gridLength / 2.0f; // We the origin of the data to be at the center of our cube

        const float deltaTime = 1.0f / 20.0f;
        const float voxelVol = 1f;

        foreach(Data data in dataList)
        {
            trajectoryDensity.setDensities(0);
            //Iterate over each point in the dataset
            foreach(Vector3 point in data.modelTip)
            {

                // Point is scaled such that all coordinates are in the range [0, 1]
                Vector3 scaledPoint = (point - minTip);
                scaledPoint.x = scaledPoint.x / rangeTip.x * scaleTip.x;
                scaledPoint.y = scaledPoint.y / rangeTip.y * scaleTip.y;
                scaledPoint.z = scaledPoint.z / rangeTip.z * scaleTip.z;

                Vector3Int va = getVoxelIndexAtPosition(scaledPoint, gridLength / (float) voxelsPerDim);
                va = Vector3Int.Max(va, Vector3Int.zero);
               
                trajectoryDensity.voxels[va.x + 1, va.y + 1, va.z + 1].density += 1f;
            }
            voxelGrid.add(trajectoryDensity);
        }
        
        //voxelGrid.normalizeDensities(dataList.Count); // Normalize by the number of trajectories to get values between 0 and 1
        // Debug.Log("About to print grid!");
        //voxelGrid.print();
        
        //Debug.Log("Done calculating the space time density!");
    }

    private Vector3Int getVoxelIndexAtPosition(Vector3 pos, float voxelSideLength)
    {
        int x = (int)Mathf.Ceil(pos.x / voxelSideLength) - 1;
        int y = (int)Mathf.Ceil(pos.y / voxelSideLength) - 1;
        int z = (int)Mathf.Ceil(pos.z / voxelSideLength) - 1;

        return new Vector3Int(x, y, z);
    }

    protected void visualizeDensity()
    {
        // Convert our result to the format expected by Matias Lavik's Volume Rendering Code
        VolumeDataset dataset = new VolumeDataset();

        dataset.datasetName = string.Join(",", paths);
        //dataset.filePath = filePath;

        int voxels = voxelsPerDim + 2;
        dataset.dimX = voxels;
        dataset.dimY = voxels;
        dataset.dimZ = voxels;
        int uDimension = voxels * voxels * voxels;
        dataset.data = new float[uDimension];

        // Copy the data
        for (int x = 0; x < voxels; x++)
        {
            for (int y = 0; y < voxels; y++)
            {
                for (int z = 0; z < voxels; z++)
                {
                    /*
                     * Based on the code for creating a texture for the data set the one dimensional array
                     * stores data so that idx = x + y * dimX + z * (dimX * dimY)
                     */
                    int idx = x + y * voxels + z * (voxels * voxels);
                    dataset.data[idx] = voxelGrid.voxels[x, y, z].density;
                }
            }
        }
        Debug.Log("Loaded dataset in range: " + dataset.GetMinDataValue() + "  -  " + dataset.GetMaxDataValue());
        
        dataset.FixDimensions();
        
        // Spawn the object
        if (dataset != null)
        {
            volObjScript = VolumeObjectFactory.CreateObject(dataset);
            

            // Set the transfer function
            TransferFunction tf = TransferFunctionDatabase.LoadTransferFunction(transferFunction);
            volObjScript.transferFunction = tf;

            // Rotate the visualization object back to the default rotation (it is rotated 90 degrees for some reason)
            volGO = GameObject.Find("VolumeRenderedObject_" + dataset.datasetName);
            Debug.Log(volGO);
            Vector3 maxLen = Vector3.one * Mathf.Max(rangeTip.x, rangeTip.y, rangeTip.z);
            Vector3 scale = maxLen + (gridLength / (float)voxelsPerDim) * 2 * maxLen;
            volGO.transform.localRotation = Quaternion.Euler(0.0f, 0.0f, 0.0f);
            volGO.transform.position = scale * 0.5f + minTip - (gridLength / (float)voxelsPerDim) * maxLen;
            volGO.transform.localScale = scale;
        }
    }

    protected void visualizePathTrace(Data data)
    {
        if(data.lineRenderer == null)
        {
            Debug.LogError("No Line Renderer assigned to the simulation script!\nNo motion trace visualized.");
            return;
        }

        // Render half the points behind, and half the point ahead of the current index, or as far as possible if near the begining/end of the data
        int numPastPoints = (index - (numberOfPoints) >= 0) ? numberOfPoints : index;
        //int numFuturePoints = (index + (numberOfPoints / 2) < data.fileSize) ? numberOfPoints / 2 : data.fileSize - index; // Includes the current point
        //Debug.Log("# past points: " + numPastPoints + " # future points: " + numFuturePoints);
        data.lineRenderer.positionCount = numPastPoints;// + numFuturePoints;
        
        Vector3[] points = new Vector3[numPastPoints];
        Array.Copy(data.modelTip, index - numPastPoints + 1, points, 0, numPastPoints);
        /*for(int i = 0; i < numPastPoints; i++)
        {
            int current = index - (numPastPoints - i);
            points[i] = data.modelTip[current];
        }*/
        /*for (int i = 0; i < numFuturePoints; i++)
        {
            int current = index + i;
            points[numPastPoints + i] = data.modelTip[current];
        }*/
        data.lineRenderer.SetPositions(points);

        //Set color
        data.lineRenderer.endColor = data.modelTipCol[index];
    }

    // Simulate the data in specific data set. Should only be called after checking externaly that we have a new simulation frame and aren't paused!
    protected void simulateData(Data data)
    {
        // If the markers are set, we have data, we still have more data
        if (MarkerCheck(data) && data.fileSize > 0 && data.moreData)
        {
            //normalize positions
            Normalize(data);

            //update marker positions
            data.cathTop.transform.position = new Vector3(data.x1, data.y1, data.z1);
            data.cathTL.transform.position = new Vector3(data.x2, data.y2, data.z2);
            data.cathTR.transform.position = new Vector3(data.x3, data.y3, data.z3);
            data.cathBL.transform.position = new Vector3(data.x4, data.y4, data.z4);
            data.cathBR.transform.position = new Vector3(data.x5, data.y5, data.z5);
            data.skullTL.transform.position = new Vector3(data.x6, data.y6, data.z6);
            data.skullTR.transform.position = new Vector3(data.x7, data.y7, data.z7);
            data.skullBL.transform.position = new Vector3(data.x8, data.y8, data.z8);
            data.skullBR.transform.position = new Vector3(data.x9, data.y9, data.z9);
            data.skullBrow.transform.position = new Vector3(data.x10, data.y10, data.z10);
          
            if (index >= data.fileSize)
            {
                data.moreData = false; //stop simulation if eod is reached
                //Invoke(nameof(RestartScene), 1f); // Soft restart the scene (method in this script)
            }

            // Update timer for the next frame
            timer = 0f;
            timeToCall = timeDelay / playBackSpeed;

            // Place the reference model by the markers
            AlignModels(data);
        }
    }

    // Update is called once per frame
    protected void FixedUpdate()
    {
        timer += Time.deltaTime;

        // If it's the next simulation frame, and we are not paused
        if (timer >= timeToCall && !paused && moreData && enableSimulation)
        {
            //Debug.Log("\t Index: " + dataList[1].index);
            //Debug.Log("\t HeadTopLeft Last: (" + dataList[1].headTopLeft[dataList[1].index, 0] + ", " + dataList[1].headTopLeft[dataList[1].index, 1] + ", " + dataList[1].headTopLeft[dataList[1].index, 2] + ")");

            // Simulate each data series
            foreach (Data data in dataList)
            {
                simulateData(data);
                if(applyPathTrace) visualizePathTrace(data);
            }




            if (rewind)
            {
                if (index > 0)
                    index--;
            }
            else
                index++;

            // Update the GUI
            if (FrameStuff[0])
            {
            FrameStuff[0].text = "Frame: " + index +" / " + maxFileSize;
            }
            //Debug.Log("index" + index);

            if (index >= maxFileSize)
            {
                moreData = false;
                Invoke(nameof(RestartScene), 1f); // Soft restart the scene (method in this script)
            }
        }
    }

    private void extractDataMarkersHelper(Data data, GameObject ourMarkers)
    {
        data.lineRenderer = GetComponent<LineRenderer>();
        int numChildren = ourMarkers.transform.childCount;
        for (int i = 0; i < numChildren; i++) {
            GameObject child = ourMarkers.transform.GetChild(i).gameObject;

            switch (child.name)
            {
                case "CathTop":
                    data.cathTop = child;
                    break;
                case "CathTL":
                    data.cathTL = child;
                    break;
                case "CathTR":
                    data.cathTR = child;
                    break;
                case "CathBL":
                    data.cathBL = child;
                    break;
                case "CathBR":
                    data.cathBR = child;
                    break;
                case "SkullTL":
                    data.skullTL = child;
                    break;
                case "SkullTR":
                    data.skullTR = child;
                    break;
                case "SkullBL":
                    data.skullBL = child;
                    break;
                case "SkullBR":
                    data.skullBR = child;
                    break;
                case "SkullBrow":
                    data.skullBrow = child;
                    break;
                case "CathCenter":
                    data.cathCenter = child;
                    //initialize offset for 3dmodels
                    data.cathCenterRot = child.transform.rotation;
                    data.cathTipOffset = child.transform.GetChild(1).localPosition/100;
                    break;
                case "SkullCenter":
                    data.skullCenter = child;
                    //initialize offset for 3dmodels
                    data.skullCenterRot = data.skullCenter.transform.rotation;

                    int nc = child.transform.childCount;
                    for (int j = 0; j < nc; j++)
                    {
                        GameObject c = child.transform.GetChild(j).gameObject;
                        if (c.name.Equals("Skull_phantom"))
                        {
                            phantomSkull = c;
                            phantomBrain = c.transform.GetChild(0).gameObject;
                        }
                    }
                        break;
                case "TestTip":
                    data.testTip = child;
                    break;
                default:
                    Debug.Log("When reading " + data.path + ": Instantiated marker contained unknown child " + child.name);
                    break;
            }
        }
    }

    // Make sure that all data sets are of equal length
    protected int warpData(List<Data> dataList)
    {
        // Find the data set with most data points
        int maxSize = -1;
        foreach(Data data in dataList)
        {
            //Debug.Log("Data size: " + data.fileSize);
            maxSize = Math.Max(maxSize, data.fileSize);
        }

        // Check if we should warp the data for this visualization
        if (!applyWarpData) return maxSize;

        // Warp all data sets so they are of equal length
        foreach(Data data in dataList)
        {
            if (data.fileSize != maxSize) warpData(data, maxSize);
        }

        return maxSize;
    }

    private void warpDataCopyHelper(float[,] newArray, float[,] oldArray, int iNew, int iOld, int secondN)
    {
        for (int j = 0; j < secondN; j++) newArray[iNew, j] = oldArray[iOld, j];
    }

    private void warpDataInterpolateHelper(float[,] newArray, float[,] oldArray, int iNew, int iOld, int secondN, float t)
    {
        for (int j = 0; j < secondN; j++) newArray[iNew, j] = Mathf.Lerp(oldArray[iOld, j], oldArray[iOld + 1, j], t);
    }

    // Warp the initialize data to a new length through piecwise interpolation
    protected void warpData(Data data, int newSize)
    {
        // Remember the original length
        int oldSize = data.fileSize;

        Debug.Log("Warping " + data.path + " of size " + oldSize + " to size " + newSize);
        /*Debug.Log("\t Original HeadTopLeft Last: (" + data.headTopLeft[oldSize - 5, 0] + ", " + data.headTopLeft[oldSize - 5, 1] + ", " + data.headTopLeft[oldSize - 5, 2] + ")");
        Debug.Log("\t Original HeadTopLeft 5: (" + data.headTopLeft[5, 0] + ", " + data.headTopLeft[5, 1] + ", " + data.headTopLeft[5, 2] + ")");*/

        // Update to the new length
        data.fileSize = newSize;

        // Alocate new arrays
        float[] field = new float[data.fileSize];
        float[] time = new float[data.fileSize];
        float[,] headTopLeft = new float[data.fileSize, 3];
        float[,] headTopRight = new float[data.fileSize, 3];
        float[,] headBottomLeft = new float[data.fileSize, 3];
        float[,] headBottomRight = new float[data.fileSize, 3];
        float[,] headHole = new float[data.fileSize, 3];
        float[,] headBrow = new float[data.fileSize, 3];
        float[,] cathTip = new float[data.fileSize, 3];
        float[,] cathTopLeft = new float[data.fileSize, 3];
        float[,] cathTopRight = new float[data.fileSize, 3];
        float[,] cathBottomLeft = new float[data.fileSize, 3];
        float[,] cathBottomRight = new float[data.fileSize, 3];
        float[,] cathEnd = new float[data.fileSize, 3];

        // The last point should be the same
        field[newSize - 1] = data.field[oldSize - 1];        
        time[newSize - 1] = data.time[oldSize - 1];
        warpDataCopyHelper(headTopLeft, data.headTopLeft        , newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(headTopRight, data.headTopRight      , newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(headBottomLeft, data.headBottomLeft  , newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(headBottomRight, data.headBottomRight, newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(headHole, data.headHole              , newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(headBrow, data.headBrow              , newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(cathTip, data.cathTip                , newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(cathTopLeft, data.cathTopLeft        , newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(cathTopRight, data.cathTopRight      , newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(cathBottomLeft, data.cathBottomLeft  , newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(cathBottomRight, data.cathBottomRight, newSize - 1, oldSize - 1, 3);
        warpDataCopyHelper(cathEnd, data.cathEnd                , newSize - 1, oldSize - 1, 3);

        // Interpolate the new points inbetween the first and last point
        float stride = (float) (oldSize - 1) / (float) (newSize - 1); // Subtract by 1 because of 0 indexing
        float growthFactor = newSize / oldSize;
        float currentStep = stride;
        for (int i = 0; i < newSize - 1; i++)
        {
            // Find the closest smaller point in the original array and the offset from it to the currentStep
            int current = (int) currentStep;
            float offset = currentStep - (float) current;

            //Debug.Log("i " + i + " Current " + current + " Current Step" + currentStep);

            // Create a point in the new array with values interpolated from the two closest points in the original array
            field[i]           = i;
            time[i]            = Mathf.Lerp(time[current], time[current + 1], offset);
            warpDataInterpolateHelper(headTopLeft, data.headTopLeft        , i, current, 3, offset);
            warpDataInterpolateHelper(headTopRight, data.headTopRight      , i, current, 3, offset);
            warpDataInterpolateHelper(headBottomLeft, data.headBottomLeft  , i, current, 3, offset);
            warpDataInterpolateHelper(headBottomRight, data.headBottomRight, i, current, 3, offset);
            warpDataInterpolateHelper(headHole, data.headHole              , i, current, 3, offset);
            warpDataInterpolateHelper(headBrow, data.headBrow              , i, current, 3, offset);
            warpDataInterpolateHelper(cathTip, data.cathTip                , i, current, 3, offset);
            warpDataInterpolateHelper(cathTopLeft, data.cathTopLeft        , i, current, 3, offset);
            warpDataInterpolateHelper(cathTopRight, data.cathTopRight      , i, current, 3, offset);
            warpDataInterpolateHelper(cathBottomLeft, data.cathBottomLeft  , i, current, 3, offset);
            warpDataInterpolateHelper(cathBottomRight, data.cathBottomRight, i, current, 3, offset);
            warpDataInterpolateHelper(cathEnd, data.cathEnd                , i, current, 3, offset);

            currentStep = stride * (float) (i + 1);
        }

        //Debug.Log("\t HeadTopLeft 5: (" + headTopLeft[5, 0] + ", " + headTopLeft[5, 1] + ", " + headTopLeft[5, 2] + ")");

        // Update data to use the new arrays
        data.field           = field;
        data.headTopLeft     = headTopLeft;
        data.headTopRight    = headTopRight;
        data.headBottomLeft  = headBottomLeft;
        data.headBottomRight = headBottomRight;
        data.headHole        = headHole;
        data.headBrow        = headBrow;
        data.cathTip         = cathTip;
        data.cathTopLeft     = cathTopLeft;
        data.cathTopRight    = cathTopRight;
        data.cathBottomLeft  = cathBottomLeft;
        data.cathBottomRight = cathBottomRight;
        data.cathEnd         = cathEnd;
    }

    /*
     * Reads in the data available at path and returns an object holding the data
     * which can be used for playback.
     */
    protected Data extractData(string path)
    {
        Data data = new Data();
        TextAsset txtAsset = Resources.Load<TextAsset>("Recordings/" + path);
        string text = txtAsset.text;
        string[] lines = text.Split("\n");

        data.path = path;
        index = 0;
        data.fileSize = 0;

        // Buffer the data at path in memory
        //StreamReader sr = ReadFile(data.path); //read from file

        data.fileSize = FindSize(lines); //find size of file


        // Initialize the markers for this data
        GameObject ourMarkers = Instantiate(markers);
        if (world != null)
        {
            ourMarkers.transform.parent = world;
        }
        ourMarkers.transform.position = Vector3.zero;
        if (keepSkullStill)
        {
            ourMarkers.transform.position = skullPosition.position;
        }
        data.markers = ourMarkers;
        //ourMarkers.transform.parent = ;
        ourMarkers.name = "markers_" + path;
        extractDataMarkersHelper(data, ourMarkers);

        //initialize arrays
        data.field = data.time = new float[data.fileSize];
        data.headTopLeft = new float[data.fileSize, 3];
        data.headTopRight = new float[data.fileSize, 3];
        data.headBottomLeft = new float[data.fileSize, 3];
        data.headBottomRight = new float[data.fileSize, 3];
        data.headHole = new float[data.fileSize, 3];
        data.headBrow = new float[data.fileSize, 3];
        data.cathTip = new float[data.fileSize, 3];
        data.cathTopLeft = new float[data.fileSize, 3];
        data.cathTopRight = new float[data.fileSize, 3];
        data.cathBottomLeft = new float[data.fileSize, 3];
        data.cathBottomRight = new float[data.fileSize, 3];
        data.cathEnd = new float[data.fileSize, 3];

        //extract and distribute info
        Extract(lines, data); // Reads in all data and places it in the relevant arrays
        data.moreData = true;

        //set offset of skull depending on recording
        data.skullCenter.gameObject.transform.GetChild(0).transform.localPosition = skullOffsetPos[path];
        data.skullCenter.gameObject.transform.GetChild(0).transform.localEulerAngles = skullOffsetRot[path];
        
        // Normalize the data
        for (int i = 0; i < data.fileSize; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                 data.cathTip[i, j] = data.cathTip[i, j] / normalizationFactor;
                 data.cathTopLeft[i, j] = data.cathTopLeft[i, j] / normalizationFactor;
                 data.cathTopRight[i, j] = data.cathTopRight[i, j] / normalizationFactor;
                 data.cathBottomLeft[i, j] = data.cathBottomLeft[i, j] / normalizationFactor;
                 data.cathBottomRight[i, j] = data.cathBottomRight[i, j] / normalizationFactor;
                 data.headTopLeft[i, j] = data.headTopLeft[i, j] / normalizationFactor;
                 data.headTopRight[i, j] = data.headTopRight[i, j] / normalizationFactor;
                 data.headBottomLeft[i, j] = data.headBottomLeft[i, j] / normalizationFactor;
                 data.headBottomRight[i, j] = data.headBottomRight[i, j] / normalizationFactor;
                 data.headBrow[i, j] = data.headBrow[i, j] / normalizationFactor;
                
            }
        }

        // Align the data so that the skulls brow is centered on the origin
        if(applyAlign) Align(data);

        return data;
    }

    //Method to display the models of catheter and skull according to the markers positions
    private void AlignModels(Data data)
    {
        //Align orientation of the catheter
        data.cathRight = data.cathTL.transform.position - data.cathTR.transform.position;
        data.cathUp = data.cathTR.transform.position - data.cathBR.transform.position - Vector3.Project(data.cathTR.transform.position - data.cathBR.transform.position, data.cathRight);
        data.cathCenter.transform.rotation = Quaternion.LookRotation(data.cathRight, data.cathUp);

        //Align positions at the barycenter
        Vector3 cathPos = new Vector3((data.x1 + data.x2 + data.x3 + data.x4 + data.x5) / 5.0f, (data.y1 + data.y2 + data.y3 + data.y4 + data.y5) / 5.0f, (data.z1 + data.z2 + data.z3 + data.z4 + data.z5) / 5.0f);
        Vector3 skullPos = new Vector3((data.x6 + data.x7 + data.x8 + data.x9 + data.x10) / 5.0f, (data.y6 + data.y7 + data.y8 + data.y9 + data.y10) / 5.0f, (data.z6 + data.z7 + data.z8 + data.z9 + data.z10) / 5.0f);

        if (keepSkullStill)
        {
            data.markers.transform.position = -skullPos + skullPosition.position;
        }
        data.cathCenter.transform.localPosition = cathPos;
        data.skullCenter.transform.localPosition = skullPos;
        

        //data.testTip.transform.position = data.cathCenter.transform.position + data.cathCenter.transform.rotation * data.cathTipOffset;
        data.testTip.transform.position = data.modelTip[index];
    }

    private void findMinMax(List<Data> dataList)
    {
        Vector3 min = new Vector3(float.MaxValue, float.MaxValue, float.MaxValue);
        Vector3 max = new Vector3(float.MinValue, float.MinValue, float.MinValue);
        
        foreach (Data data in dataList)
        {
            for (int i = 0; i < data.fileSize; i++)
            {
                min = Vector3.Min(min, data.modelTip[i]);
                max = Vector3.Max(max, data.modelTip[i]);
            }
        }
        minTip = min;
        maxTip = max;
        rangeTip = max - min;

        squareRangeTip = Vector3.one * Mathf.Max(max.x, max.y, max.z) - Vector3.one * Mathf.Min(min.x, min.y, min.z);

        float xLen = (max.x - min.x);
        float yLen = (max.y - min.y);
        float zLen = (max.z - min.z);
        float maxLen = Mathf.Max(xLen, yLen, zLen);

        scaleTip = new Vector3(xLen/maxLen, yLen/maxLen, zLen/maxLen);
    }

    private void Align(Data data)
    {
        Vector3 align = offsetPos[data.path];
        
        for (int i = 0; i < data.fileSize; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                data.cathTip[i, j] -= align[j];
                data.cathTopLeft[i, j] -= align[j];
                data.cathTopRight[i, j] -= align[j];
                data.cathBottomLeft[i, j] -= align[j];
                data.cathBottomRight[i, j] -= align[j];
                data.headTopLeft[i, j] -= align[j];
                data.headTopRight[i, j] -= align[j];
                data.headBottomLeft[i, j] -= align[j];
                data.headBottomRight[i, j] -= align[j];
                data.headBrow[i, j] -= align[j];
            }
        }
    }

    //method to normalize coordinates in Unity scene
    private void Normalize(Data data)
    {

        //x coordinate
        data.x1 = data.cathTip[index, 0];      
        data.x2 = data.cathTopLeft[index, 0];
        data.x3 = data.cathTopRight[index, 0];  
        data.x4 = data.cathBottomLeft[index, 0];  
        data.x5 = data.cathBottomRight[index, 0];  
        data.x6 = data.headTopLeft[index, 0];  
        data.x7 = data.headTopRight[index, 0];  
        data.x8 = data.headBottomLeft[index, 0];  
        data.x9 = data.headBottomRight[index, 0];  
        data.x10 = data.headBrow[index, 0];  

        //y coordinate
        data.y1 = data.cathTip[index, 1];  
        data.y2 = data.cathTopLeft[index, 1];  
        data.y3 = data.cathTopRight[index, 1];  
        data.y4 = data.cathBottomLeft[index, 1];  
        data.y5 = data.cathBottomRight[index, 1];  
        data.y6 = data.headTopLeft[index, 1];  
        data.y7 = data.headTopRight[index, 1];  
        data.y8 = data.headBottomLeft[index, 1];  
        data.y9 = data.headBottomRight[index, 1];  
        data.y10 = data.headBrow[index, 1];  

        //z coordinate
        data.z1 = data.cathTip[index, 2];  
        data.z2 = data.cathTopLeft[index, 2];  
        data.z3 = data.cathTopRight[index, 2];  
        data.z4 = data.cathBottomLeft[index, 2];  
        data.z5 = data.cathBottomRight[index, 2];  
        data.z6 = data.headTopLeft[index, 2];  
        data.z7 = data.headTopRight[index, 2];  
        data.z8 = data.headBottomLeft[index, 2];  
        data.z9 = data.headBottomRight[index, 2];  
        data.z10 = data.headBrow[index, 2];  
    }

    //function to check if objects assigned to markers are not null
    private bool MarkerCheck(Data data)
    {
        if (data.cathTop != null && data.cathTL != null && data.cathTR != null && data.cathBL != null && data.cathBR != null
            && data.skullBL != null && data.skullBR != null && data.skullTL != null && data.skullTR != null && data.skullBrow != null)
            return true;
        else return false;
    }

    //function to read the file with recorded MoCap data
    private StreamReader ReadFile(string path)
    {
        StreamReader reader = new StreamReader(path);
        
        string line = reader.ReadLine(); //first line = headers
        return reader;
    }

    //function to find the total number of lines in the file being read
    private int FindSize(String[] lines)
    {
        int i = 0;
        string line = lines[i + 1]; // Don't count the header line
        while (!String.IsNullOrWhiteSpace(line))
        {
            i++;

            line = lines[i + 1];
        }

        return i;
    }

    private void Extract(String[] lines, Data data)
    {
        int i = 1;
        string line;
        line = lines[i]; //first line
        //extract info and distribute
        while (!String.IsNullOrWhiteSpace(line)) //interrupt at empty line or end of file
        {
            string[] temp = line.Split(separator.ToCharArray());
            //string[] temp = line.Split("\t");
            int runtimeField = Int32.Parse(temp[0]) - 1; //current array id

            //Debug.Log(runtimeField);

            //populate arrays
            data.field[runtimeField] = runtimeField + 1.0f;
            data.time[runtimeField] = runtimeField / 100.0f;


            //marker tree attached to the skull

            data.headTopLeft[runtimeField, 0] = float.Parse(temp[2], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 1 x
            data.headTopLeft[runtimeField, 1] = float.Parse(temp[4], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 1 y
            data.headTopLeft[runtimeField, 2] = float.Parse(temp[3], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 1 z
            data.headTopRight[runtimeField, 0] = float.Parse(temp[5], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 2 x
            data.headTopRight[runtimeField, 1] = float.Parse(temp[7], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 2 y
            data.headTopRight[runtimeField, 2] = float.Parse(temp[6], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 2 z
            data.headBottomLeft[runtimeField, 0] = float.Parse(temp[8], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 3 x
            data.headBottomLeft[runtimeField, 1] = float.Parse(temp[10], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 3 y
            data.headBottomLeft[runtimeField, 2] = float.Parse(temp[9], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 3 z
            data.headBottomRight[runtimeField, 0] = float.Parse(temp[11], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 4 x
            data.headBottomRight[runtimeField, 1] = float.Parse(temp[13], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 4 y
            data.headBottomRight[runtimeField, 2] = float.Parse(temp[12], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull 4 z

            /* calibration marker on burr hole is always 0
            headHole[runtimeField, 0] = float.Parse(temp[14]); //burr hole x
            headHole[runtimeField, 1] = float.Parse(temp[16]); //burr hole y
            headHole[runtimeField, 2] = float.Parse(temp[15]); //burr hole z
            */

            //marker attached to the skull brow
            /* headBrow[runtimeField, 0] = float.Parse(temp[17], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull brow x
            headBrow[runtimeField, 1] = float.Parse(temp[19], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull brow y
            headBrow[runtimeField, 2] = float.Parse(temp[18], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull brow z

            //marker tree attached to the catheter
            cathTip[runtimeField, 0] = float.Parse(temp[20], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 1 x
            cathTip[runtimeField, 1] = float.Parse(temp[22], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 1 y
            cathTip[runtimeField, 2] = float.Parse(temp[21], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 1 z
            cathTopLeft[runtimeField, 0] = float.Parse(temp[23], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 2 x
            cathTopLeft[runtimeField, 1] = float.Parse(temp[25], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 2 y
            cathTopLeft[runtimeField, 2] = float.Parse(temp[24], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 2 z
            cathTopRight[runtimeField, 0] = float.Parse(temp[26], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 3 x
            cathTopRight[runtimeField, 1] = float.Parse(temp[28], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 3 y
            cathTopRight[runtimeField, 2] = float.Parse(temp[27], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 3 z
            cathBottomLeft[runtimeField, 0] = float.Parse(temp[29], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 4 x
            cathBottomLeft[runtimeField, 1] = float.Parse(temp[31], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 4 y
            cathBottomLeft[runtimeField, 2] = float.Parse(temp[30], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 4 z
            cathBottomRight[runtimeField, 0] = float.Parse(temp[32], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 5 x
            cathBottomRight[runtimeField, 1] = float.Parse(temp[34], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 5 y
            cathBottomRight[runtimeField, 2] = float.Parse(temp[33], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 5 z
            */
            data.headBrow[runtimeField, 0] = float.Parse(temp[14], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull brow x
            data.headBrow[runtimeField, 1] = float.Parse(temp[16], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull brow y
            data.headBrow[runtimeField, 2] = float.Parse(temp[15], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //skull brow z

            //marker tree attached to the catheter
            data.cathTip[runtimeField, 0] = float.Parse(temp[17], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 1 x
            data.cathTip[runtimeField, 1] = float.Parse(temp[19], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 1 y
            data.cathTip[runtimeField, 2] = float.Parse(temp[18], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 1 z
            data.cathTopLeft[runtimeField, 0] = float.Parse(temp[20], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 2 x
            data.cathTopLeft[runtimeField, 1] = float.Parse(temp[22], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 2 y
            data.cathTopLeft[runtimeField, 2] = float.Parse(temp[21], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 2 z
            data.cathTopRight[runtimeField, 0] = float.Parse(temp[23], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 3 x
            data.cathTopRight[runtimeField, 1] = float.Parse(temp[25], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 3 y
            data.cathTopRight[runtimeField, 2] = float.Parse(temp[24], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 3 z
            data.cathBottomLeft[runtimeField, 0] = float.Parse(temp[26], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 4 x
            data.cathBottomLeft[runtimeField, 1] = float.Parse(temp[28], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 4 y
            data.cathBottomLeft[runtimeField, 2] = float.Parse(temp[27], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 4 z
            data.cathBottomRight[runtimeField, 0] = float.Parse(temp[29], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 5 x
            data.cathBottomRight[runtimeField, 1] = float.Parse(temp[31], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 5 y
            data.cathBottomRight[runtimeField, 2] = float.Parse(temp[30], System.Globalization.CultureInfo.InvariantCulture.NumberFormat); //catheter 5 z

            /* calibration marker on catheter tip is always 0
            cathEnd[runtimeField, 0] = float.Parse(temp[32]); //catheter tip x
            cathEnd[runtimeField, 1] = float.Parse(temp[34]); //catheter tip y
            cathEnd[runtimeField, 2] = float.Parse(temp[33]); //catheter tip z
            */

            i++;
            if (i >= lines.Length)
            {
                break;
            }
            line = lines[i];
        }
    }

    protected void SetStateText()
    {
        if ((Input.GetKey(KeyCode.RightArrow) || fastForward))
        {
            stateText.text = "Fast Forward";
        }
        else if ((Input.GetKey(KeyCode.LeftArrow) || fastBackward))
        {
            stateText.text = "Fast Backward";
        }
        else 
        {
            stateText.text = paused ? "Paused" : "Playing";
            if (rewind)
            {
                stateText.text += " (Rewind)";
            }
        }
    }

    protected void playPause()
    {
        paused = !paused;
    }

    protected void ChangeDirection()
    {
        rewind = !rewind;
    }

    public void FastForward(bool val)
    {
        fastForward = val;
    }

    public void FastBackward(bool val)
    {
        fastBackward = val;
    }

    protected void RestartScene()
    {
        //Debug.Log("Restart");
        //SceneManager.LoadScene(SceneManager.GetActiveScene().name);

        foreach(Data data in dataList)
        {
            index = 0;
            data.moreData = true;
        }
        index = 0;

        timer = 0;

        moreData = true;
    }

    protected void ToggleTransparency()
    {
        Debug.Log("Transparency Enabled: " + transparencyEnabled);
        Renderer skullRenderer = phantomSkull.GetComponent<Renderer>();
        if (!transparencyEnabled)
        {
            SkullTransparent();
            BrainTransparent();
            transparencyEnabled = true;
        }
        else if (transparencyEnabled)
        {
            SkullSolid();
            BrainSolid();
            transparencyEnabled = false;
        }
    }
    protected void SetInitialColors()
    {
        Renderer skullRenderer = phantomSkull.GetComponent<Renderer>();
        solidSkullMat = skullRenderer.material;
        Renderer brainRenderer = phantomBrain.GetComponent<Renderer>();
        solidBrainMat = brainRenderer.material;
    }
    private void SkullTransparent()
    {
        Renderer skullRenderer = phantomSkull.GetComponent<Renderer>();
        skullRenderer.material = transparentSkullMat;
    }
    private void BrainTransparent()
    {
        Renderer brainRenderer = phantomBrain.GetComponent<Renderer>();
        brainRenderer.material = transparentBrainMat;
    }

    private void SkullSolid()
    {
        Renderer skullRenderer = phantomSkull.GetComponent<Renderer>();
        skullRenderer.material = solidSkullMat;
    }

    private void BrainSolid()
    {
        Renderer brainRenderer = phantomBrain.GetComponent<Renderer>();
        brainRenderer.material = solidBrainMat;
    }

    public int GetCurrentIndex()
    {
        return index;
    }
}
