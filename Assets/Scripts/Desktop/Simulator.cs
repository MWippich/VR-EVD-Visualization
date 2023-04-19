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
  (up and down arrow keys), rewinding/playing (left and right arrows keys) and
  for toggling the transparency of the brain and skull on and off (Q key). Some
  additional functions exist in the script but were not working as intended
  before user tests were held and therefore not used.
*/


public class Simulator : BaseSimulator
{
    override protected void handleInput()
    {

        //Debug.Log("PC index= " + index);
        // Toggle transparency on and off with the Q key
        /*if (Input.GetKeyDown(KeyCode.T))
        {
            ToggleTransparency();
        }*/
        if (transparencyEnabled) // Check if we want to adjust the transparency (Disabled?)
        {
            if (Input.GetKey(KeyCode.Mouse0))
            {
                // AdjustTransparency(10);
            }
            if (Input.GetKey(KeyCode.Mouse1))
            {
                //AdjustTransparency(-10);
            }
        }

        if (Input.GetKeyDown(KeyCode.Space))
        {
            playPause();
        }

        if (Input.GetKeyDown(KeyCode.R))
        {
            ChangeDirection();
        }

        

        /*
        // Left arrow key decreases the cut of value of the visibility window
        if (Input.GetKey(KeyCode.LeftArrow) && applySpaceTimeDensity)
        {
            Vector2 visWindow = volObjScript.GetVisibilityWindow();
            visWindow.x -= densityVisSpeed * Time.deltaTime;
            if (visWindow.x < 0.0f) visWindow.x = 0;
            volObjScript.SetVisibilityWindow(visWindow);
        }
        // Right arrow key increases the cut of value of the visibility window
        else if (Input.GetKey(KeyCode.RightArrow) && applySpaceTimeDensity)
        {
            Vector2 visWindow = volObjScript.GetVisibilityWindow();
            visWindow.x += densityVisSpeed * Time.deltaTime;
            if (visWindow.x > visWindow.y) visWindow.x = visWindow.y;
            volObjScript.SetVisibilityWindow(visWindow);
        }*/

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
            index++;
            if (FrameStuff[0])
            {
                FrameStuff[0].text = "Frame: " + index + " / " + maxFileSize;
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
            index--;
            if (FrameStuff[0])
            {
                FrameStuff[0].text = "Frame: " + index + " / " + maxFileSize;
            }
        }
    }

}
