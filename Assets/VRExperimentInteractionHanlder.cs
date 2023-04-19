using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.XR.Interaction.Toolkit;

public class VRExperimentInteractionHanlder : ExperimentInteractionHandler
{

    public Transform markerPosition;
    public XRRayInteractor rayInteractor;

    [SerializeField] private InputActionReference placeMarker = null;

    private void Awake()
    {
        placeMarker.action.performed += Place;
    }

    private void OnDestroy()
    {
        placeMarker.action.performed -= Place;
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
    }


    private void Place(InputAction.CallbackContext context)
    {
        if (!rayInteractor.IsOverUIGameObject())
        {
            ToggleTransparency();
            markerPlaced.Invoke(!transparencyEnabled);
        }
            
    }
}
