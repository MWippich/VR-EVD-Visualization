using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.XR.Interaction.Toolkit;

public class VRExperimentInteractionHanlder : ExperimentInteractionHandler
{

    public Transform markerPosition, rightHand;
    public XRRayInteractor rayInteractor;

    [SerializeField] private InputActionReference placeMarker = null;

    private float heldTime = -1f;
    private bool holding = false;
    private Vector3 prevMarkerPos;

    private void Awake()
    {
        placeMarker.action.started += PlaceDown;
        placeMarker.action.canceled += Place;
    }

    private void OnDestroy()
    {
        placeMarker.action.started -= PlaceDown;
        placeMarker.action.canceled -= Place;
    }

    private void Start()
    {
        marker.transform.localScale = new Vector3(markerSize, markerSize, markerSize);
        markerTransparent();
    }

    public override void Restart()
    {
        if (!transparencyEnabled)
        {
            ToggleTransparency();
        }
        base.Restart();
    }

    private void Update()
    {
        if (transparencyEnabled)
        {
            marker.transform.position = markerPosition.position;
        }

        if (currentTask != BaseSimulator.TASK.ANGLE)
        {

            if(heldTime > -0.5f)
            {
                heldTime += Time.deltaTime;
            }

            if(!transparencyEnabled && holding && !rayInteractor.IsOverUIGameObject())
            {
                Vector3 markerPos = rightHand.position;
                Vector3 prevPos = prevMarkerPos;

                Vector3 posDelta = markerPos - prevPos;

                marker.transform.position += posDelta * 0.25f;
            }
        }
        else
        {
            if (holding && !rayInteractor.IsOverUIGameObject())
            {
                Quaternion rot = Quaternion.FromToRotation(prevMarkerPos - marker.transform.position, rightHand.position - marker.transform.position);

                marker.transform.rotation = rot * marker.transform.rotation;
            }
        }

        prevMarkerPos = rightHand.position;
    }

    private void PlaceDown(InputAction.CallbackContext context)
    {
        holding = true;
        if (!transparencyEnabled)
            heldTime = 0f;
    }

    private void Place(InputAction.CallbackContext context)
    {

        if(currentTask == BaseSimulator.TASK.ANGLE)
        {
            markerPlaced.Invoke(true);
        }
        else if (!rayInteractor.IsOverUIGameObject() && heldTime < 0.5f)
        {
            ToggleTransparency();
            markerPlaced.Invoke(!transparencyEnabled);
        }
        heldTime = -1f;
        holding = false;
    }
}
