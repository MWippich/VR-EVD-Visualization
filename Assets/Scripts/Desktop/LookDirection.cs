using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

/*
  Script which enables changing orientation of the observer (rotates camera
  around itself) using the mouse in the desktop setting. Adjust xSens and ySens
  inside Unity to change the sensitivity (how much the camera rotates based on
  mouse movements).
*/

public class LookDirection : ExperimentInteractionHandler
{

    public float xSens;
    public float ySens;
    public float rotSpeed;
    Vector2 rot;

    public float markerDist = 0.05f;
    public GameObject cameraLineStart;
    public GameObject cameraLineEnd;
    public Transform initialTransform;
    public Button resetButton;
    
    private Vector3 prevMousePos;

    void Start()
    {
        resetButton.onClick.AddListener(ResetView);
        marker.transform.position = this.transform.position + transform.rotation * Vector3.forward * markerDist;
        marker.transform.localScale = new Vector3(markerSize, markerSize, markerSize);
        markerTransparent();
        rot = initialTransform.eulerAngles;
    }

    void Update()
    {
        if (drawPositionHelpers)
        {
            DrawHelper();
        }

        //RIGHTMOUSEBUTTON
        if (Input.GetMouseButton(1))
        {
            Cursor.lockState = CursorLockMode.Locked;
            Cursor.visible = false;
            // mouse input
            float mouseX = Input.GetAxisRaw("Mouse X") * xSens * 0.01f;
            float mouseY = Input.GetAxisRaw("Mouse Y") * ySens * 0.01f;

            rot.x -= mouseY;
            rot.y += mouseX;

            // limits PoV up/down
            rot.x = Mathf.Clamp(rot.x, -90f, 90f);

            // rotate cam
            transform.rotation = Quaternion.Euler(rot.x, rot.y, 0);
        }
        else if (Input.GetMouseButtonUp(1))
        {

            Cursor.visible = true;
            Cursor.lockState = CursorLockMode.None;
        }

        if (currentTask != BaseSimulator.TASK.ANGLE)
        {
            if (Input.GetMouseButtonDown(0) && !EventSystem.current.IsPointerOverGameObject() && !Input.GetKey(KeyCode.LeftControl))
            {
                if (!marker.activeSelf)
                {
                    transparencyEnabled = false;
                }
                ToggleTransparency();
                markerPlaced.Invoke(!transparencyEnabled);
                if (transparencyEnabled)
                {
                    //set marker dist to current distance


                    markerDist = Mathf.Clamp(markerDist, 0.015f, 0.1f);
                }
            }
            else if (!transparencyEnabled && Input.GetKey(KeyCode.LeftControl))
            {

                if (Input.GetMouseButton(0) && !EventSystem.current.IsPointerOverGameObject())
                {
                    Vector3 mousePos = Input.mousePosition;
                    Vector3 prevPos = prevMousePos;
                    mousePos.z = 1;
                    prevPos.z = 1;

                    Vector3 mousePosDelta = GetComponent<Camera>().ScreenToWorldPoint(mousePos)
                        - GetComponent<Camera>().ScreenToWorldPoint(prevPos);

                    marker.transform.position += mousePosDelta * 0.025f;
                }
                if (Input.mouseScrollDelta.y != 0)
                {
                    marker.transform.position += Input.mouseScrollDelta.y * GetComponent<Camera>().transform.forward * 0.0005f;
                }
            }

            if (transparencyEnabled)
            {
                marker.transform.position = this.transform.position + transform.rotation * Vector3.forward * markerDist;
            }

            var scrollSpeed = 0.001f;
            if (Input.GetKey(KeyCode.LeftShift))
            {
                scrollSpeed *= 2;
            }

            markerDist += Input.mouseScrollDelta.y * scrollSpeed;
            markerDist = Mathf.Clamp(markerDist, 0.015f, 0.1f);

            if (transparencyEnabled)
            {
                Vector3 mousePos = Input.mousePosition;
                mousePos.z = markerDist;

                marker.transform.position = GetComponent<Camera>().ScreenToWorldPoint(mousePos);
            }
        } else
        {
            // Angle Task
            UpdateAngle();
        }
        if (Input.GetKey(KeyCode.Return))
        {
            ResetView();
        }

        prevMousePos = Input.mousePosition;
    }

    private void UpdateAngle()
    {
        if (Input.GetMouseButtonDown(0) && !EventSystem.current.IsPointerOverGameObject())
        {
            markerPlaced.Invoke(true);
        }

        if (Input.GetMouseButton(0))
        {
            float rotX = Input.GetAxis("Mouse X") * rotSpeed * Mathf.Deg2Rad;
            float rotY = Input.GetAxis("Mouse Y") * rotSpeed * Mathf.Deg2Rad;

            marker.transform.Rotate(GetComponent<Camera>().transform.up, -rotX, Space.World);
            marker.transform.Rotate(GetComponent<Camera>().transform.right, rotY, Space.World);
        }
    }

    public void ResetView()
    {
        rot = initialTransform.eulerAngles;
    }
}
