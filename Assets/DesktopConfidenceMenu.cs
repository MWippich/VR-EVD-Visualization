using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class DesktopConfidenceMenu : ConfidenceMenu
{

    public Button continueButton;
    public List<Toggle> toggleButtons;

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
