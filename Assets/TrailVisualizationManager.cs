using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TrailVisualizationManager : MonoBehaviour
{
    private List<float> recordedSpeed;

    private Vector3 previousPosition;
    private Vector3 velocity;
    private float framesPerSec;
    public float trailLength = 5; // in seconds

    private bool forward = true;

    // Start is called before the first frame update
    void Start()
    {
        previousPosition = transform.position;
        framesPerSec = 1.0f / Time.fixedDeltaTime;
    }

    void FixedUpdate()
    {
        velocity = (transform.position - previousPosition) / Time.fixedDeltaTime;
        previousPosition = transform.position;
        float speed = velocity.magnitude;
        //recordedSpeed.Add(speed);
    }
}
