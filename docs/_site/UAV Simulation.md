
<center>
  <a href="https://crawlab.github.io/RoboBoat-2021/"><img src="images/Buttons/Home.png" title="UAV" width="110px" /></a>
  <a href="https://crawlab.github.io/RoboBoat-2021/Simulation"><img src="images/Buttons/Simulations.png" title="Simulations" width="110px" /></a>
</center>

<p><center>
  <a href="https://crawlab.github.io/RoboBoat-2021/UAV Simulation"><img src="images/Buttons/UAV.png" title="UAV Simulation" width="110px" /></a>
  <a href="https://crawlab.github.io/RoboBoat-2021/ASV Simulation"><img src="images/Buttons/ASV.png" title="ASV Simulation" width="110px" /></a>
  <a href="https://crawlab.github.io/RoboBoat-2021/Blender"><img src="images/Buttons/Blender.png" title="Blender" width="110px" /></a>
  <a href="https://crawlab.github.io/RoboBoat-2021/Labelbox"><img src="images/Buttons/Labelbox.png" title="Labelbox" width="110px" /></a>
</center>
</p>


## 2021 UL Lafayette Ragin' Cajuns UAV Simulation

- Insert a clip: UAV moving in simulation

### The Basics

- This UAV was created in simulation to show the comparison of how the UAV will act in simulation verus in the real world. The simulation that was used in this experiment was based off from [RotorS](http://wiki.ros.org/rotors_simulator), which was developed by the [Autonomous Systems Lab](https://asl.ethz.ch/) at [ETH Zurich](https://ethz.ch/en.html). The perk of using [RotorS](http://wiki.ros.org/rotors_simulator) for this experiment is due to it being a MAV gazebo simulator. 
    - Gazebo simulator is useful in adding real world forces to the simulation. This helps with making sure that the UAV will be able to counteract these forces as well as move like it should be.

- Fail: Tuning the two PD controllers for the f450 simulation



<center> <img src="images/Failure_in_Sim.png" title="Failure_in_Sim" width="500px" /> <center>


- In the tuning of the PD controller, the UAV proportional and derivative gains were not corrrect. In this picutre the goal was to get the UAV to hover in a single spot. Clearly this did not happen. What happened in this photo was the forces acted on the UAV making the UAV unbalanced, which made the UAV fail to hover.


<center> <img src="images/Wrong Scale.png" title="Wrong Scale" width="500px" /> <center> 


- Here when imorting the STL's for the drone, this was just a simple mishap that occured. Sometimes when importing STL or DAE files the scaling can become off from what one would expect it to be. This is just part of the process of actually importing objects into xacro files, which in this case, on would just scale down the file.  


<center> <img src="images/UAV-Test_World-Collisions.png" title="UAV-Test_World-Collisions" width="500px" /> <center> 


- This image is to show the collsion dimensions on this UAV. The collisions shown are in the propellers, main body, and each of the sensors on the UAV. What can be clearly seen are the collision dimensions for the propellers, it's the circles shown on each propeller.


<center> <img src="images/RViz.png" title="RViz" width="500px" /> <center> 

- This image shows the cameras up and operational in RViz. Basically what this means is in simulation we can attempt to start to map out designated areas and see excalty what the UAV sees in the process. In the left hand side, this is displaying a depth image from the OAK-D cameras. In the right top side, this is displaying what the OAK-D camera views with its stereo cameras. In the bottom right side, this is displaying the raspberry pi's image, as well as the lidar's laser. 


### Other topics:

- We can show of how this UAV failed many times and we can talk about why it failed and how we worked to fix this issue
- Show clips of failures and then a successful launch



*More Coming soon...*