using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System;
using UnityEngine.UI;
using JetBrains.Annotations;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;

/*
  VR version of script for running the simulation and manipulating certain
  aspects of it. Added functions for controlling playback speed of animation
  (left and right on the touchpad of the right controller), rewinding/playing
  (up and down on the touchpad of the right controller) and for toggling the
  transparency of the brain and skull on and off (trigger on the back of the
  left controller). Some additional functions exist in the script but were not
  working as intended before user tests were held and therefore not used.
*/

public class VRSimulator : BaseSimulator
{
    public GameObject XROrigin;

    [Header("VR Settings")]
    public GameObject leftController;
    public GameObject rightController;

    [SerializeField] private InputActionReference togglePlay = null;
    [SerializeField] private InputActionReference toggleReverse = null;
    [SerializeField] private InputActionReference scrolling = null;
    [SerializeField] private InputActionReference restartPlayback = null;

    private float restartTimer = 0.0f;

    private void Awake()
    {
        togglePlay.action.performed += OnTogglePlay;
        toggleReverse.action.performed += OnToggleReverse;
        scrolling.action.performed += OnScrolling;
    }

    private void OnDestroy()
    {
        togglePlay.action.performed -= OnTogglePlay;
        toggleReverse.action.performed -= OnToggleReverse;
        scrolling.action.performed -= OnScrolling;
    }


    override protected void handleInput()
    {
        if (fastForward && index < maxFileSize - 1)
        {
            foreach (Data data in dataList)
            {
                simulateData(data);
                if (applyPathTrace) visualizePathTrace(data);
            }
            index++;
        }

        // Right arrow key plays the animation forward in time
        if (fastBackward && index > 0)
        {
            foreach (Data data in dataList)
            {
                simulateData(data);
                if (applyPathTrace) visualizePathTrace(data);
            }
            index--;
        }

        if (restartPlayback.action.triggered && restartTimer < 0f)
        {
            // Reset timer
            restartTimer = 0f;
        }

        if (restartPlayback.action.inProgress && restartTimer >= 0f)
        {
            restartTimer += Time.deltaTime;
            if (restartTimer > 1f)
            {
                RestartScene();
                //Prevent firing multiple times, if button kept held
                restartTimer = -1f;
            }
        }
    }

    private void OnTogglePlay(InputAction.CallbackContext context)
    {
        playPause();
    }

    private void OnToggleReverse(InputAction.CallbackContext context)
    {
        ChangeDirection();
    }
    private void OnScrolling(InputAction.CallbackContext context)
    {
        Vector2 val = context.ReadValue<Vector2>();
        if (val.x < -0.5f)
        {
            fastBackward = true;
        } else
        {
            fastBackward = false;
        }

        if(val.x > 0.5f)
        {
            fastForward = true;
        }
        else
        {
            fastForward = false;
        }
    }

}
