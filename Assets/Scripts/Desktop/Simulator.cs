using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System;
using UnityEngine.UI;
using JetBrains.Annotations;

/*
  Desktop version of script for running the simulation and manipulating certain
  aspects of it. Added functions for controlling playback speed of animation
  (up and down arrow keys) and rewinding/playing (left and right arrows keys).
*/


public class Simulator : BaseSimulator
{
    override protected void handleInput()
    {

        if (Input.GetKeyDown(KeyCode.Space))
        {
            playPause();
        }

        if (Input.GetKeyDown(KeyCode.R))
        {
            ChangeDirection();
        }


        // T key restarts scene
        if (Input.GetKeyDown(KeyCode.T))
        {
            RestartScene(); // restart the scene 
        }
    }

    new private void FixedUpdate()
    {
        base.FixedUpdate();
        // Right arrow key plays the animation forward in time
        if ((Input.GetKey(KeyCode.RightArrow) || fastForward) && index < maxFileSize - 1)
        {
            foreach (Data data in dataList)
            {
                simulateData(data);
                if (applyPathTrace) visualizePathTrace(data);
            }
            index += 2;
            index = Math.Clamp(index, 0, maxFileSize - 1);

            if (debugFrameNmbr != null)
            {
                debugFrameNmbr.text = "Frame: " + index + " / " + maxFileSize;
            }
        }

        // Right arrow key plays the animation forward in time
        if ((Input.GetKey(KeyCode.LeftArrow) || fastBackward) && index > 0)
        {
            foreach (Data data in dataList)
            {

                simulateData(data);
                if (applyPathTrace) visualizePathTrace(data);
            }
            index -= 2;
            index = Math.Clamp(index, 0, maxFileSize - 1);

            if (debugFrameNmbr != null)
            {
                debugFrameNmbr.text = "Frame: " + index + " / " + maxFileSize;
            }
        }
    }

}
