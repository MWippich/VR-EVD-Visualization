using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ExperimentHandler : MonoBehaviour
{
    [Header("Experiment Variables")]
    public List<string> trajectoryPaths;
    public bool useDensityTask, usePOITask, useAngleTask;

    [Header("Setup")]
    public ConfidenceMenu confidenceMenu;
    public BaseSimulator simulator;
    public ExperimentInteractionHandler interactionHandler;
    public VRNavigation VRNavigator;
    public ObserverMovement desktopNavigatior;
    public Canvas startMenu;
    public Button startButton, doneButton;

    private bool inStartMenu = true;
    private bool inConfidenceMenu = false;
    private int currentSimulation = -1;

    private float currentTrialTime = .0f;

    private void Start()
    {
        confidenceMenu.gameObject.SetActive(false);
        startMenu.gameObject.SetActive(true);
        startButton.onClick.AddListener(() => {
            StartTrial();
            startMenu.gameObject.SetActive(false);
            inStartMenu = false;
        });
               
        doneButton.onClick.AddListener(RateConfidence);
        confidenceMenu.OnContinue.AddListener(delegate {
            StartTrial();
        });
    }

    //Gets task and trajectory for the current task, given the index and the participant number
    private void GetTrial(int i, int participantNum)
    {

    }

    private void StartTrial()
    {
        currentSimulation++;

        interactionHandler.Restart();
        if(VRNavigator != null)
        {
            VRNavigator.Restart();
        }
        if (desktopNavigatior != null)
        {
            desktopNavigatior.Restart();
        }

        inConfidenceMenu = false;
        confidenceMenu.gameObject.SetActive(false);
        string[] paths = { trajectoryPaths[currentSimulation] };
        simulator.StartSimulation(paths);

    }

    private void RateConfidence()
    {
        inConfidenceMenu = true;
        confidenceMenu.gameObject.SetActive(true);

    }
}
