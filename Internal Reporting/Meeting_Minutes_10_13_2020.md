U.A.V. Team Members:
-   Nathan Madsen -  [nathan.madsen1@louisiana.edu](mailto:nathan.madsen1@louisiana.edu)
-   Brennan Moeller -  [brennan.moeller1@louisiana.edu](mailto:brennan.moeller1@louisiana.edu) 
-   Joseph Stevens -  [joseph.stevens1@louisiana.edu](mailto:joseph.stevens1@louisiana.edu)
-   Benjamin Willis-  [benjamin.willis1@louisiana.edu](mailto:benjamin.willis1@louisiana.edu)

# Meeting Minutes from 10/13/2020
 Scope of Project: Complete UAV task, know locations on where to go, and UAV must be autonomous

1. Are we mapping a whole course (Course A is a whole course)? 
    * a. Thought is no.
    * b. If we decided to do that how high will the UV need to be and what is the resolution needed?
        * Distance - 150 feet in the air OR ~ 47 meters for whole map
        * Does the resolution matter?
        * Is the ZED efficient at what we want to use?
        * Will we need to see colors?
    * c. Should we position UAV in middle of the course and turn 360° to map?
    * d. Stereo Camera? With Laser?
        * Laser is $5k
        * Can we find one the has sensing of 40 meters OR ~ 100 ft?
    * e. Should we stay 15-20 meters up and map in sections? Would circle mapping be the right technique?
    * i. How fast are these images processed?
    * f. The thought is it might work with the ZED.

2. Possibility - We can do task to task mapping. We can also piece it together at the end to create a map. 
    * a. The idea is the UAV would aid the boat to the start of the course. 
        * Object recognition will be needed? 
        * After it maps this one task, it will move to the next one. Are RTK capabilities needed? 
    * b. The thought is we would never get high enough to map the whole course accurately. If we go task by task we would have the potential to piece it together, but piecing the map together is not needed for the UAV. 
    * c. Battery life – Will it be able to hold enough power?
        * If we are up in the air for 30 minutes can we map for 20 minutes.
    * d. UAV will AID the boat. It will not tell the boat where to go, but it will help in guiding the boat.
    * e. Drone could just collect data.
    * f. Are we just an extended sensor or are we mapping onboard?
    * g. Will we need a TX2 Jetson?
        * The extra computing power might mean a new Jetson should be added.
        * One Jetson can handle a stereo camera or whatever (LiDAR, Stereo, Laser)
        * Note - Ben A. is sending Joe information on a guy who can help determine the computing power needed for the UAV.

3. Biggest thing is Flying Autonomously and completing a task
    * a. We should not shy away from mapping
    * b. We should have Object recognition and capabilities of making waypoints. The UAV can map waypoints. 

4. TOMORROW (10/14/20) - Revise House of Quality and Specification Sheet.
    * a. At the LAB - One person should have the HOQ open, one person should have the Spec Sheet open, and one person should have the Function Tree open. All of these should be up all simultaneously to make the meeting go smoother. 

