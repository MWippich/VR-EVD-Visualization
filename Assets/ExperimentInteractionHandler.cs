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

    public bool drawPositionHelpers = true;
    public bool viewSphere = true;
    public BaseSimulator.TASK currentTask = BaseSimulator.TASK.DENSITY;

    public GameObject marker;

    public GameObject sphereMarker;
    public GameObject posMarker;
    public GameObject angleMarker;
    public float markerSize = 0.01f;

    protected void ToggleTransparency()
    {
        if (!transparencyEnabled)
        {
            markerTransparent();
        }
        else if (transparencyEnabled)
        {
            markerSolid();

        }
    }

    protected void DrawHelper()
    {
        Debug.Log(marker.transform.position);

        RaycastHit hitUp;
        Physics.Raycast(marker.transform.position, Vector3.up, out hitUp);
        RaycastHit hitDown;
        Physics.Raycast(marker.transform.position, Vector3.down, out hitDown);
        Debug.DrawLine(hitDown.point, hitUp.point, Color.red, 0.0f, true);

        RaycastHit hitLeft;
        Physics.Raycast(marker.transform.position, Vector3.left, out hitLeft);
        RaycastHit hitRight;
        Physics.Raycast(marker.transform.position, Vector3.right, out hitRight);
        Debug.DrawLine(hitLeft.point, hitRight.point, Color.red, 0.0f, true);

        RaycastHit hitForw;
        Physics.Raycast(marker.transform.position, Vector3.forward, out hitForw);
        RaycastHit hitBack;
        Physics.Raycast(marker.transform.position, Vector3.back, out hitBack);
        Debug.DrawLine(hitForw.point, hitBack.point, Color.red, 0.0f, true);
    }

    public void SetTask(BaseSimulator.TASK task)
    {
        currentTask = task;
        sphereMarker.SetActive(false);
        posMarker.SetActive(false);
        //angleMarker.SetActive(false);
        switch (task)
        {
            case BaseSimulator.TASK.DENSITY:
                marker = sphereMarker;
                break;
            case BaseSimulator.TASK.POI:
                marker = posMarker;
                break;
            case BaseSimulator.TASK.ANGLE:
                marker = angleMarker;
                break;
            default:
                marker = sphereMarker;
                break;
        }
        marker.SetActive(true);
        markerTransparent();
    }

    public void HideMarker()
    {
        marker.SetActive(false);
    }

    public virtual void Restart()
    {
        marker.SetActive(viewSphere);
    }

    protected void markerTransparent()
    {
        transparencyEnabled = true;
        if (currentTask == BaseSimulator.TASK.DENSITY)
        {
            Renderer skullRenderer = marker.GetComponent<Renderer>();
            skullRenderer.material = transparentMat;
        } else if(currentTask == BaseSimulator.TASK.POI)
        {
            foreach (Renderer r in marker.GetComponentsInChildren<Renderer>())
            {
                r.material = transparentMat;
            }
        }
    }
    protected void markerSolid()
    {
        transparencyEnabled = false;
        if (currentTask == BaseSimulator.TASK.DENSITY)
        {
            Renderer skullRenderer = marker.GetComponent<Renderer>();
            skullRenderer.material = solidMat;
        }
        else if (currentTask == BaseSimulator.TASK.POI)
        {
            foreach (Renderer r in marker.GetComponentsInChildren<Renderer>())
            {
                r.material = solidMat;
            }
        }
    }
}
