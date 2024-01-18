# VR-EVD Visualization
This project aims to facilitate teaching resident neurosurgens the procedure of Extra Ventricular Drain (EVD) placement, by allowing them to view Motion Capture (MoCap) recordings of this procedure, using different visualizations. This code was used to perform an experiment to test and compare the usefulness of this system with different visualization techniques and environments (VR & Desktop). A short demonstration of the experiment can be seen [here](https://kth-my.sharepoint.com/:v:/g/personal/wippich_ug_kth_se/EQRoA5jcFNxPuD-yZ6D811MBCxt6gteWxJK_rwc9sEiP0Q?e=xfcqlh).

This project was part of my master thesis, for which the complete report can be found [here](https://github.com/MWippich/VR-EVD-Visualization/files/13471523/Degree_Project_Report.pdf).

## Contents
This project has two main scenes: ```Assets/DesktopScene``` and ```Assets/VRScene``` for running the project in the respective environments. Each of the scenes has the exact same contents and differ only in which environment it is used and thus, how the input works. Each of these scenes contain a model of a catheter, a skull and the ventricles. The experiment contains a number of trials in a certain order (depending on participant), where a certain visualization technique (or no visualization) is shown, a certain task is performed and a certain catheter trajectory is used. The participant can finish the task by placing a marker and then continuing to the next task. After each task the paricipant must rate their confidence in their answer, after which a new combination of visualization, trajectory and task is shown.

In order to run an experiment the variables of the "ExperimentHandler" GameObject must be edited from the editor. Here the trial ordering can be changed depending on which participant is currently doing the experiment as well as which visualization should be used. For testing a single combination of visualization, task & trajectory. The following variables are edited to alter the experiment:<br />
- **Participant Number**: Changes the trial ordering according to figure 3.9, in the report<br />
- **Visualization**: Changes which visualization should be used for the current participant (4D-Time Density or Trail)<br />
- **Testing**: If true, does not follow normal experiment protocol, instead sets task, trajectory and visualization depending on the following three variables. (and disregards the settings in **Participant Number** and **Visualization**)<br />
- **Test Trajectory**: Sets which trajectory to use, choose among the recordings in ```Assets/Resources/Recordings``` (only when **Testing** is true)<br />
- **Test Task**: Sets which task to use (only when **Testing** is true)<br />
- **Test Viz**: Sets which visualization to use (only when **Testing** is true)<br />
- **Current Simulation**: When running an experiment, this variable can be set to skip a number of trials and start from the indicated trial instead. Otherwise, should always be set to -1.

Additional settings can be found in the ´´´SimulationManager´´´ GameObject, however note that some of these settings are overriden by the settings of the ExperimentHandler.

In order to run the scenes, simply run the scene from the editor, for running the project in VR see the section *Environment & Running* below. 

Results (answer coordinates, time-to-completion and confidence) after a finished experiment are stored in ```Data/Done```. If for some reason the experiment didn't finsih any results for the so far completed trials is found in ```Data/Intermediate```.

## Controls
Controls in each environment can be seen below. For a more thorough explanation of the controls, see [section 3.2 in the report](https://github.com/MWippich/VR-EVD-Visualization/files/13471523/Degree_Project_Report.pdf).
![VRControlScheme](https://github.com/MWippich/VR-EVD-Visualization/assets/42743154/45e4ad6e-f385-429b-a066-44fde20f0e43)
![desktopControlSchemeBW](https://github.com/MWippich/VR-EVD-Visualization/assets/42743154/185d3a89-1567-42e4-be46-46c081b081c3)

## Visualizations
The project uses two visualization techniques, 4D-time Density visualization, which is a type of volume rendering, and a simple trail visualization, which simply draws a trail coloured according to the speed of the catheter. More information on the visualization techniques can be found in the [report](https://github.com/MWippich/VR-EVD-Visualization/files/13471523/Degree_Project_Report.pdf). The visualizations can be seen below.
<p float="left">
  <img src="https://github.com/MWippich/VR-EVD-Visualization/assets/42743154/04c2fffd-d92b-40ab-8270-722133480156" width="500" />
  <img src="https://github.com/MWippich/VR-EVD-Visualization/assets/42743154/14beae87-a532-4a1a-8c18-e6e8a37dfd1b" width="500" /> 
</p> 

## Environment & Running
The project is written in Unity version 2021.3.9f1. Run the project in the unity editor, with your VR headset connected. In the case of the META Quest 2, use Quest Link, either through Wi-Fi or with a cable. When using Quest link, first connect to the computer, then launch quest link with that computer, entering the quest link environment. With the correct settings, Unity should launch the VR project in the VR headset, when run from the editor.  

In order to run the project in fullscreen/windowed mode, edit the script ```Assets/Editor/fullscreen.cs``` and change the variable ```private static readonly bool fullscreen = true;``` to true/false. In fullscreen mode the project can be exited using ```ctrl + p```.

## Hardware
The project is made for the META Quest 2, however it should not be too difficult to extend the project (change input mappings etc.) to work on a different VR Headset.

## Credits
This project is inspired by the previous work of Alexander Danielsson (https://github.com/Oriaf/visualisationProject) & Andreas Wrife (https://github.com/glas444/Neuro) for the course Advanced Topics in Visualization and Computer Graphics DD2470, as well as using the code for the basic Motion Capture replay system by Team Dream for the course Advanced Projects in Interactive Media Technology, HT2022, KTH. The group consisted of four KTH Students: Marcus Holmberg, Måns Nyman, Léa Prémont, Mahmoud Sherzad. Their original code can be found at: https://github.com/MarcusHolmbrg/TeamDreamMocapProject
