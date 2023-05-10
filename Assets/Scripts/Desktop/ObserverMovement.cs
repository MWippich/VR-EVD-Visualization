using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/*
  Script which enables full 3D movement of the observer in the desktop setting
  using the WASD keys.
  Adjust moveSpeed in Unity to change the movement speed.
*/

public class ObserverMovement : MonoBehaviour
{
    public float moveSpeed;

    public Transform initialTransform;
    public Button resetButton;

    // Start is called before the first frame update
    void Start()
    {
        resetButton.onClick.AddListener(ResetView);
        ResetView();
    }

    public void Restart()
    {
        ResetView();
        GetComponent<LookDirection>().ResetView();
    }

    // Update is called once per frame
    void Update()
    {
        float speed = 1.0f;

        if (Input.GetKey(KeyCode.LeftShift))
        {
            speed = 2.0f;
        }

        if (Input.GetKey(KeyCode.W))
        {
            transform.position += transform.forward * moveSpeed * Time.deltaTime * speed;
        }
        if (Input.GetKey(KeyCode.S))
        {
            transform.position -= transform.forward * moveSpeed * Time.deltaTime * speed;
        }
        if (Input.GetKey(KeyCode.A))
        {
            transform.position -= transform.right * moveSpeed * Time.deltaTime * speed;
        }
        if (Input.GetKey(KeyCode.D))
        {
            transform.position += transform.right * moveSpeed * Time.deltaTime * speed;
        }
        if (Input.GetKey(KeyCode.Q))
        {
            transform.position -= transform.up * moveSpeed * Time.deltaTime * speed;
        }
        if (Input.GetKey(KeyCode.E))
        {
            transform.position += transform.up * moveSpeed * Time.deltaTime * speed;
        }

        if (Input.GetKey(KeyCode.Return))
        {
            ResetView();
        }

    }

    private void ResetView()
    {
        transform.position = initialTransform.position;
        transform.rotation = initialTransform.rotation;
    }
}
