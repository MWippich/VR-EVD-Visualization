using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class ConfidenceMenu : MonoBehaviour
{

    public UnityEvent<int> OnContinue;

    private int confidence = 3;

    public void SetConfidence(int confidence)
    {
        this.confidence = confidence;
    }

    public void ContinuePressed()
    {
        OnContinue.Invoke(confidence);
    }


}
