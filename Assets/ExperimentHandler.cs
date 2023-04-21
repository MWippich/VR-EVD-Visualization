using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

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
    public Canvas startMenu, doneMenu;
    public GameObject speedHelper, densityHelper;
    public Button startButton, doneButton;
    public TMP_Text description;

    private bool inStartMenu = true;
    private bool inConfidenceMenu = false;
    private int currentSimulation = -1;

    private float currentTrialTime = .0f;
    private float doneTimer = -1f; //Used for timing double click

    private string currTrajectory;
    private BaseSimulator.TASK currTask = BaseSimulator.TASK.POI;
    private BaseSimulator.VIZ currVisualization = BaseSimulator.VIZ.TRAIL;

    private List<(BaseSimulator.VIZ, string)> trajVizCombos;

    


    private Dictionary<BaseSimulator.TASK, string> descriptions = new Dictionary<BaseSimulator.TASK, string>
    {
        {BaseSimulator.TASK.DENSITY, "Place the sphere such that it contains the tip of the catheter in as many frames as possible" },
        {BaseSimulator.TASK.POI, "Place the marker such that it is as close as possible to the point where the tip of the catheter reaches the deepest point in the brain" },
        {BaseSimulator.TASK.ANGLE, "Align the arrow such that it it corresponds to the tangent of the trajectory at the indicated point" },
    };

    private void Awake()
    {
        if (visualization == BaseSimulator.VIZ.NONE) {
            Debug.LogError("visualization of ExperimentHandler shouldn't be 'NONE' and will thus not create proper experiment.");
            return;
        }

        trajVizCombos = new List<(BaseSimulator.VIZ, string)>();
        int i = 0;
        while(i < trajectoryPaths.Count*2)
        {
            foreach (string traj in trajectoryPaths)
            {
                BaseSimulator.VIZ viz = i % 2 == 0 ? BaseSimulator.VIZ.NONE : visualization;

                trajVizCombos.Add((viz, traj));

                i++;
            }
        }
        foreach((BaseSimulator.VIZ, string) comb in trajVizCombos)
        {
            Debug.Log(comb);
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

            StartTrial();
        });
    }

    //Sets task, trajectory and viz for the current task, given the index and the participant number
    private void SetTrial(int i)
    {
        // Set Task
        int taskIndex = i / trajVizCombos.Count;
        Debug.Log(i);
        Debug.Log(trajVizCombos.Count);
        Debug.Log(taskIndex);

        currTask = tasks[taskIndex];

        int trajVizIndex = i % trajVizCombos.Count;
        currVisualization = trajVizCombos[trajVizIndex].Item1;
        currTrajectory = trajVizCombos[trajVizIndex].Item2;
    }

    private void StartTrial()
    {
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
        string[] paths = { currTrajectory };
        simulator.StartSimulation(paths, currTask, currVisualization);
        interactionHandler.SetTask(currTask);
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
