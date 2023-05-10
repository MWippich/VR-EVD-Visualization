using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.XR.Interaction.Toolkit;

public class VRNavigation : MonoBehaviour
{
    public InputActionReference fly;
    public InputActionReference flyBackwards;
    public InputActionReference resetView;
    public InputActionReference LGrab;
    public InputActionReference RGrab;
    public XRRayInteractor rayInteractor;

    public GameObject rightHand;
    public GameObject leftHand;
    public Camera cam;
    public Transform initialPosition;
    public float initialScale = 0.25f;

    private bool blockFly = false;
    public float flySpeed = 0.1f;
    public float scaleSpeed = 0.1f;
    public float scalePosOffsetSpeed = 0.1f;

    private float resetTimer = 0.0f;

    private float grabDistance = 0.0f;
    private float grabScale = 0.1f;
    private bool grabbingL = false, grabbingR = false;

    private void Awake()
    {
        cam.nearClipPlane = 0.0001f;
        LGrab.action.started += LeftGrab;
        LGrab.action.canceled += LeftGrab;
        RGrab.action.started += RightGrab;
        RGrab.action.canceled += RightGrab;
    }

    private void OnDestroy()
    {
        LGrab.action.started -= LeftGrab;
        LGrab.action.canceled -= LeftGrab;
        RGrab.action.started -= RightGrab;
        RGrab.action.canceled -= RightGrab;
    }

    public void SetBlockMovement(bool block)
    {
        blockFly = block;
    }

    public void Restart()
    {
        ResetView();
    }

    private void Start()
    {
        ResetView();
    }

    private void Update()
    {
        if (!blockFly && !rayInteractor.IsOverUIGameObject()) {
            float flyValue = fly.action.ReadValue<float>();
            float negativeFlyValue = flyBackwards.action.ReadValue<float>();
            Vector3 flyVelocity = 60 * Time.deltaTime * flySpeed * (flyValue - negativeFlyValue) * (rightHand.transform.rotation * Vector3.forward);
            transform.position += flyVelocity;
        }

        if (resetView.action.triggered && resetTimer < 0f)
        {
            // Reset timer
            resetTimer = 0f;
        }

        if (resetView.action.inProgress && resetTimer >= 0f)
        {
            resetTimer += Time.deltaTime;
            if(resetTimer > 1f)
            {
                ResetView();
                //Prevent firing multiple times, if button kept held
                resetTimer = -1f;
            }
        }

        if (grabbingL && grabbingR)
        {
            float currGrabDistance = Vector3.Distance(leftHand.transform.position, rightHand.transform.position) * scaleSpeed / transform.localScale.x;

            float distFrac = grabDistance / currGrabDistance;

            float newScale = Mathf.Clamp(grabScale * distFrac, 0.2f, 0.5f);

            //Offset scael position, so that it seems we're scaling with the camera at the center, since the camera is offset from this GO
            Vector3 camPos = cam.transform.position;
            Vector3 diff = transform.position - camPos;
            float scaleFactor = newScale / transform.localScale.x;
            Vector3 newPos = camPos + diff * scaleFactor;
            //Also move camera a bit forward/backward when scaling, to avoid jarring effect on eyes, that occurs otherwise.
            newPos = newPos + scalePosOffsetSpeed * (1 - scaleFactor) * (cam.transform.rotation * Vector3.forward);

            transform.localScale = Vector3.one * newScale;
            transform.localPosition = newPos;
        }

    }

    private void ResetView()
    {
        transform.position = initialPosition.position - transform.localRotation * cam.transform.localPosition * transform.localScale.x;
        transform.RotateAround(cam.transform.position, Vector3.up, - transform.rotation.eulerAngles.y + initialPosition.rotation.eulerAngles.y - cam.transform.localRotation.eulerAngles.y);
        //transform.rotation = Quaternion.Euler(0, initialPosition.rotation.eulerAngles.y - cam.transform.localRotation.eulerAngles.y, 0);
    }

    void LeftGrab(InputAction.CallbackContext context)
    {
        grabbingL = context.started;
        GrabbingStarted();
    }

    void RightGrab(InputAction.CallbackContext context)
    {
        grabbingR = context.started;
        GrabbingStarted();
    }

    void GrabbingStarted()
    {
        grabDistance = Vector3.Distance(leftHand.transform.position, rightHand.transform.position) * scaleSpeed / transform.localScale.x;
        grabScale = transform.localScale.x;
    }
}
