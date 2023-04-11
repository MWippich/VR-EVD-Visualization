using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public abstract class ExperimentInteractionHandler : MonoBehaviour
{
    public UnityEvent<bool> markerPlaced;

    public Material transparentMat;
    public Material solidMat;

    protected bool transparencyEnabled;

    public bool viewSphere = true;

    public GameObject marker;
    public float markerSize = 0.01f;
    protected void ToggleTransparency()
    {
        if (!transparencyEnabled)
        {
            markerTransparent();
            transparencyEnabled = true;
        }
        else if (transparencyEnabled)
        {
            markerSolid();
            transparencyEnabled = false;

        }
    }

    public void HideMarker()
    {
        marker.SetActive(false);
    }

    public virtual void Restart()
    {
        marker.SetActive(true);
    }

    protected void markerTransparent()
    {
        Renderer skullRenderer = marker.GetComponent<Renderer>();
        skullRenderer.material = transparentMat;
    }
    protected void markerSolid()
    {
        Renderer skullRenderer = marker.GetComponent<Renderer>();
        skullRenderer.material = solidMat;
    }
}
