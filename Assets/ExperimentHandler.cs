using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

using System.IO;

public class ExperimentHandler : MonoBehaviour
{
    [Header("Experiment Variables")]
    public int participantNumber;
    public List<string> trajectoryPaths;
    public BaseSimulator.VIZ visualization;
    public List<BaseSimulator.TASK> tasks = new List<BaseSimulator.TASK> { BaseSimulator.TASK.DENSITY, BaseSimulator.TASK.POI, BaseSimulator.TASK.ANGLE };
    public bool doneDoublePress = false;

    [Header("Setup")]
    public ConfidenceMenu confidenceMenu;
    public BaseSimulator simulator;
    public ExperimentInteractionHandler interactionHandler;
    public VRNavigation VRNavigator;
    public ObserverMovement desktopNavigatior;
    public Canvas startMenu, doneMenu, finishedMenu;
    public GameObject speedHelper, densityHelper;
    public Button startButton, doneButton;
    public TMP_Text description;

    [Header("Testing")]
    public bool testing = false;
    public string testTrajectroy = "catheter001";
    public BaseSimulator.TASK testTask;
    public BaseSimulator.VIZ testViz;

    private bool inStartMenu = true;
    private bool inConfidenceMenu = false;
    public int currentSimulation = -1;

    private float currentTrialTime = .0f;
    private float doneTimer = -1f; //Used for timing double click

    private string currTrajectory;
    private BaseSimulator.TASK currTask = BaseSimulator.TASK.POI;
    private BaseSimulator.VIZ currVisualization = BaseSimulator.VIZ.TRAIL;

    private List<List<(BaseSimulator.VIZ, string)>> trajVizCombos;
    private List<List<string>> taskTrajectories;
    private Vector3 trialPosition, trialAngle;

    private Dictionary<BaseSimulator.TASK, string> descriptions = new Dictionary<BaseSimulator.TASK, string>
    {
        {BaseSimulator.TASK.DENSITY, "Place the sphere such that it contains the tip of the catheter for as long time as possible" },
        {BaseSimulator.TASK.POI, "Place the marker such that it is as close as possible to the point where the tip of the catheter reaches the deepest point in the brain" },
        {BaseSimulator.TASK.ANGLE, "Rotate the line such that it aligns with the direction of motion of the tip of the catheter at the instant when moving through the indicated point" },
    };

    private float offset;

    private List<Dictionary<string, dynamic>> experimentData = new List<Dictionary<string, dynamic>>();

    private void Awake()
    {
        Random.InitState(participantNumber);

        if (visualization == BaseSimulator.VIZ.NONE) {
            Debug.LogError("visualization of ExperimentHandler shouldn't be 'NONE' and will thus not create proper experiment.");
            return;
        }

        taskTrajectories = new List<List<string>> { GetTrajectorySubset(participantNumber, 0), GetTrajectorySubset(participantNumber, 1)};


        trajVizCombos = new List<List<(BaseSimulator.VIZ, string)>>();
        
        int taskIndex = 0;
        if((participantNumber/2) % 2 == 1 )
        {
            //Every two participants, reverse task order (only works when there are two tasks)
            tasks.Reverse();
        }


        foreach (BaseSimulator.TASK task in tasks)
        {
            List<(BaseSimulator.VIZ, string)> lst = new List<(BaseSimulator.VIZ, string)>();
            int i = 0;
            while (i < taskTrajectories[taskIndex].Count * 2)
            {
                foreach (string traj in taskTrajectories[taskIndex])
                {
                    BaseSimulator.VIZ viz = (i + participantNumber/4) % 2 == 1 ? BaseSimulator.VIZ.NONE : visualization;

                    lst.Add((viz, traj));

                    i++;
                }
            }
            trajVizCombos.Add(lst);
            taskIndex++;
        }
        int j = 0;
        foreach (List<(BaseSimulator.VIZ, string)> lst in trajVizCombos)
        {
            foreach ((BaseSimulator.VIZ, string) comb in lst)
            {
                Debug.Log("Task " + j + ": " +  comb);
            }
            j++;
        }
    }

    private void Start()
    {
        if (description != null)
        {
            description.gameObject.SetActive(false);
        }
        if (doneMenu != null)
        {
            doneMenu.gameObject.SetActive(false);
        }
        if (speedHelper != null)
        {
            speedHelper.SetActive(false);
        }
        if (densityHelper != null)
        {
            densityHelper.SetActive(false);
        }

        interactionHandler.HideMarker();

        doneButton.interactable = false;
        interactionHandler.markerPlaced.AddListener(delegate
        (bool placed) {
            doneButton.interactable = placed;
        });

        confidenceMenu.gameObject.SetActive(false);
        finishedMenu.gameObject.SetActive(false);
        startMenu.gameObject.SetActive(true);
        startButton.onClick.AddListener(() => {
            StartTrial();
            startMenu.gameObject.SetActive(false);
            inStartMenu = false;
        });
               
        doneButton.onClick.AddListener(RateConfidence);
        confidenceMenu.OnContinue.AddListener(delegate (int confidence) {

            Debug.Log("Trial time: " + currentTrialTime);
            Debug.Log("Trial confidence: " + confidence);
            Debug.Log("Trial offset: " + offset);
            Debug.Log("Trial position: " + trialPosition);
            Dictionary<string, dynamic> trialData = new Dictionary<string, dynamic>()
            {
                { "trial", currentSimulation },
                { "task", TaskName(currTask) },
                { "trajectory", currTrajectory },
                { "viz", VizName(currVisualization) },
                { "time", currentTrialTime },
                { "confidence", confidence },
                { "offset", offset },
                { "posx", trialPosition.x },
                { "posy", trialPosition.y },
                { "posz", trialPosition.z },
            };
            experimentData.Add(trialData);

            SaveData();
            StartTrial();
        });
    }

    private string TaskName(BaseSimulator.TASK task)
    {
        switch (task)
        {
            case BaseSimulator.TASK.DENSITY:
                return "density";
            case BaseSimulator.TASK.POI:
                return "poi";
            case BaseSimulator.TASK.ANGLE:
                return "angle";
            default:
                return "";
        }
    }

    private string VizName(BaseSimulator.VIZ viz)
    {
        switch (viz)
        {
            case BaseSimulator.VIZ.DENSITY:
                return "density";
            case BaseSimulator.VIZ.TRAIL:
                return "trail";
            case BaseSimulator.VIZ.NONE:
                return "none";
            default:
                return "";
        }
    }

    public void Shuffle(List<string> list)
    {
        int n = list.Count;
        while (n > 1)
        {
            n--;
            int k = (int) (Random.value * (n + 1));
            string value = list[k];
            list[k] = list[n];
            list[n] = value;
        }
    }

    private List<string> GetTrajectorySubset(int participant, int taskNum)
    {
        int partNum = participant / 2; //2 participants in a row get the same ordering.
        int offset = taskNum * 3 + partNum;
        List<string> lst = new List<string>();
        for(int i = 0; i < 3; i++)
        {
            lst.Add(trajectoryPaths[(i + offset) % 6]);
        }
        return lst;
    }

    //Sets task, trajectory and viz for the current task, given the index and the participant number
    private void SetTrial(int i)
    {
        // Set Task
        int taskIndex = i / trajVizCombos[0].Count;
        currTask = tasks[taskIndex];

        int trajVizIndex = i % trajVizCombos.Count;
        currVisualization = trajVizCombos[taskIndex][trajVizIndex].Item1;
        currTrajectory = trajVizCombos[taskIndex][trajVizIndex].Item2;
    }

    private void SaveData(bool intermediate = true)
    {

        System.DateTime time = System.DateTime.Now;
        string filePath;
        if (intermediate)
            filePath = Application.dataPath + "/Data/Intermediate/" + "trialData_Part_" + participantNumber + "_group_" + VizName(visualization) + "_" + time.Year + "-" + time.Month + "-" + time.Day + "_" +  time.Hour + "_" + time.Minute + "_" + time.Second +  ".csv";
        else
        {
            filePath = Application.dataPath + "/Data/" + "trialData_Part_" + participantNumber + "_group_" + VizName(visualization) + ".csv";
        }

        StreamWriter writer = new StreamWriter(filePath);

        writer.WriteLine("trial, task, trajectory, viz, time, confidence, offset, posx, posy, posz, anglex, angley, anglez");

        foreach(Dictionary<string, dynamic> dat in experimentData)
        {
            writer.Write(dat["trial"]);
            writer.Write(", ");
            writer.Write(dat["task"]);
            writer.Write(", ");
            writer.Write(dat["trajectory"]);
            writer.Write(", ");
            writer.Write(dat["viz"]);
            writer.Write(", ");
            writer.Write(dat["time"].ToString());
            writer.Write(", ");
            writer.Write(dat["confidence"].ToString());
            writer.Write(", ");
            writer.Write(dat["offset"].ToString());
            writer.Write(", ");
            writer.Write(dat["posx"].ToString());
            writer.Write(", ");
            writer.Write(dat["posy"].ToString());
            writer.Write(", ");
            writer.Write(dat["posz"].ToString());
            writer.Write(", ");
            writer.WriteLine();

        }

        writer.Flush();
        writer.Close();
    }

    private void StartTrial()
    {
       

        if (!testing && currentSimulation + 1 >= tasks.Count * 2 * 3 )
        {
            confidenceMenu.gameObject.SetActive(false);
            finishedMenu.gameObject.SetActive(true);
            SaveData(false);
            return;
        }

        if(!testing)
            SetTrial(++currentSimulation);

        if (description != null)
        {
            description.gameObject.SetActive(true);
        }
        interactionHandler.Restart();
        if(VRNavigator != null)
        {
            VRNavigator.Restart();
            VRNavigator.SetBlockMovement(false);
        }
        if (desktopNavigatior != null)
        {
            desktopNavigatior.Restart();
        }
        if (doneMenu != null)
        {
            doneMenu.gameObject.SetActive(true);
        }

        doneButton.interactable = false;
        inConfidenceMenu = false;
        confidenceMenu.gameObject.SetActive(false);
        if (testing)
        {
            currTrajectory = testTrajectroy;
            currTask = testTask;
            currVisualization = testViz;
        }
        string[] paths = { currTrajectory };
        simulator.StartSimulation(paths, currTask, currVisualization);
        interactionHandler.SetTask(currTask, simulator.anglePosition);
        
        if (speedHelper != null)
        {
            speedHelper.SetActive(currVisualization == BaseSimulator.VIZ.TRAIL);
        }
        if (densityHelper != null)
        {
            densityHelper.SetActive(currVisualization == BaseSimulator.VIZ.DENSITY);
        }
        if(description != null)
        {
            description.text = descriptions[currTask];
        }

        currentTrialTime = Time.unscaledTime;
    }

    private void RateConfidence()
    {
        if (doneDoublePress)
        {
            float timeSincePress = Time.unscaledTime - doneTimer;
            if (timeSincePress > 1f)
            {
                doneTimer = Time.unscaledTime;
                return;
            }
        }

        currentTrialTime = Time.unscaledTime - currentTrialTime;

        //Find precision
        if (currTask == BaseSimulator.TASK.ANGLE)
        {
            Vector3 GT = simulator.groundTruth.getAngleGT(currTrajectory);
            Quaternion markerRot = interactionHandler.angleMarker.transform.rotation;
            offset = Quaternion.Angle(Quaternion.FromToRotation(Vector3.up, GT), markerRot);

            trialAngle = markerRot.eulerAngles;
        }
        else
        {
            Vector3 GT = currTask == BaseSimulator.TASK.DENSITY ? simulator.groundTruth.getDensityGT(currTrajectory) : simulator.groundTruth.getPOIGT(currTrajectory);

            Vector3 placedPos = interactionHandler.marker.transform.position;

            trialPosition = placedPos;
            offset = Vector3.Distance(GT, placedPos);
        }



        if (description != null)
        {
            description.gameObject.SetActive(false);
        }

        interactionHandler.HideMarker();
        inConfidenceMenu = true;
        confidenceMenu.gameObject.SetActive(true);
        if (doneMenu != null)
        {
            doneMenu.gameObject.SetActive(false);
        }

        if (VRNavigator != null)
        {
            VRNavigator.Restart();
            VRNavigator.SetBlockMovement(true);
        }

        if (desktopNavigatior != null)
        {
            desktopNavigatior.Restart();
        }
    }
}
