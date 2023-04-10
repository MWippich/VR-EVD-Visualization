using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class VRExperimentInteractionHanlder : ExperimentInteractionHandler
{

    public Transform markerPosition;

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
        marker.SetActive(viewSphere);
        marker.transform.localScale = new Vector3(markerSize, markerSize, markerSize);
        ToggleTransparency();
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
        ToggleTransparency();
    }
}
