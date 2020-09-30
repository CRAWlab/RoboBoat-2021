Team Lead: Joseph Stevens - joseph.stevens1@louisiana.edu

Members:
* Nathan Madsen   - nathan.madsen1@louisiana.edu
* Brennan Moeller - Brennan.moeller1@louisiana.edu
* Benjamin Willis - benjamin.willis1@louisiana.edu




# Integration of a UAV to the RoboBoat to aid in task completion and navigation

## Long-term Project Goal
Integrate a drone to the RoboBoat to increase the points gained while completing certain tasks and aid in navigating the courses more efficiently.

## Short-term Goal
To define specific metrics for success.
To complete a working draft of design tools.

## Recent Results Overview

1. QR code and Barcode localization
    * Localization processes can be used to identify QR codes or Barcodes in an image. This may be a useful way to detect the distance between the UAV and ASV. During the localization process a geometric square, "code candidate box", is overlaid the detected QR or Bar code. I believe a distance model could be constructed through machine learning using a simple regression formula. This model could be used to calculate distance depending on the pixel count of the "code candidate box". There are many localization algorithms that are available. - JS


2. ArUco Marker Detection
	* OpenCV has a ton of information on this. These ArUco Markers can be used for pose estimation in navigation. To me, from what I've read so far, it seems that this this would be a solid way to go if we are going to have a camera on the UAV. - JS


3. The [House of Quality, Gantt chart, and function tree](http://crawlab.org/owncloud/index.php/apps/files/?dir=%2Fshared%2FRoboBoat%2FRoboBoat2021%2FSeniorProjects_Design_Tools) are ready for review. The specification sheet is being worked on, but is not complete. We are still determining bounds for some aspects of the UAV and the required components.

4. Compiled a list of potential UAVs
	* The potential UAVs have been put on a list on the GitHub Project board for us to reference as the project develops. The UAVs vary in size, price, and included parts such as sensors, gps, and controllers. Some of the UAVs come ready-to-fly while others are near-ready-to-fly. 

## Questions/Comments
Would one way to achieve our end goal of aiding the boat in navigating the course be to use the drone as "pin" for the boat to follow like humans do when someone drops a pin on their location?


## Plan for the next two weeks
1. We are still waiting to register with RoboNation.
2. Finish the specification sheet.
3. Start compiling a morphological chart, and begin determining the "best" setup for our specific tasks.


### What are your next steps?
1. I (Brennan) plan to continue diving into ROS, specifically mavros, to learn how to control a UAV. I have found some files for the px4 vision (our UAV is not determined), but the knowledge gained by using it as the model will be able to apply to the UAV that we choose.  
2. I (Nathan) plan to work on an online course which will include learning the basic control of a drone, drone exploration, and drone navigation. 

### What work do you expect to have done by next report? What results to you expect?


### Are we on schedule with respect to the GitHub Project and/or Gantt Chart?


# Long-term planning
 As a team we would like to be able to have the success of this project defined in the next few weeks. We want to have the final design concept decided by mid October. We would like to have the drone flying autonomously with a camera attached to the bottom of it within a pre-defined area by the begging of next semester. We want to fully test this design by late February, early March to have time to correct the flaws in the coding and design. We are looking to have the UAV fly autonomously with a camera attached to it, map the course, raise/deliver an object, and have the UAV integrated with ASV by the end of next semester.

## Up coming Paper Deadlines
### Senior projects progress report due every other Thursday starting September 16, 2020.

## Administrative Deadlines
### None yet. Waiting on rules form RoboNation to be released.
