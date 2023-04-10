using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class ExperimentInteractionHandler : MonoBehaviour
{

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

    public void Restart()
    {
        
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
