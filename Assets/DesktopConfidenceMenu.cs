using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class DesktopConfidenceMenu : ConfidenceMenu
{

    public Button continueButton;
    public List<Toggle> toggleButtons;

    private void OnEnable()
    {
        SetConfidence(3);
        for (int i = 0; i < 5; i++)
        {
            Toggle toggle = toggleButtons[i];
            int toggleVal = i + 1;
            toggle.isOn = toggleVal == 3;
        }
        continueButton.interactable = false;
        StartCoroutine(EnableButtonDelay());
    }

    IEnumerator EnableButtonDelay()
    {
        yield return new WaitForSeconds(2);

        continueButton.interactable = true;
    }

    private void Start()
    {
        continueButton.onClick.AddListener(ContinuePressed);
        for(int i = 0; i < 5; i++)
        {
            Toggle toggle = toggleButtons[i];
            int toggleVal = i + 1;
            toggle.onValueChanged.AddListener(delegate {
                if(toggle.isOn)
                    SetConfidence(toggleVal);
            });
        }
    }

}
