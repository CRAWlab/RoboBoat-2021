---
layout: page
title: The Journey
permalink: /The Jouney/
---
<!-- There will need to be a vimeo account set up for videos to take place -->
<!-- Currently Flickr Account one can use to import content is:
Username: C00023498@louisiana.edu
Pas: CF2Yh66XURUUbzr
-->

<a ><img style="float: right;" src="https://live.staticflickr.com/65535/48135447492_981e7ced31_o.jpg" height="260" alt="2019 International RoboBoat Competition - 109"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script> In August of 2018, a group of 4 undergraduate students set out to compete in the RoboBoat 2019 Competition with the help from their advisor, Dr. Vaughan. This team developed the Autonomous Surface Vessel (ASV) from scratch. This ASV had to follow specific [guidelines](https://robonation.org/app/uploads/sites/3/2019/10/RoboBoat-2019-Rules-and-Task-Description_v2.pdf) given by [RoboNation](https://robonation.org/) and a few items to note from these guidelines is that the ASV must be autonomous, configured with an E-Stop, and have the electronics protected from water. It must float in water and be propelled by the teams choice of actuation. The UL Lafayette 2019 RoboBoat Team decided to go a different route than most other teams, which was to create a pontoon boat with thrusters in an "X"-configuration enabling holonomic motion. The materials used to build the hull for the ASV was foam, adhesive, epoxy, fiberglass, and paint. The foam was cut into planar shapes by hand with a hot wire foam cutter, which were then glued together and sanded to form a pontoon's hull structure. From there, the team prepared the hull  to marry the bridge, which holds the pontoon stable as it is moves in the water. 
<br />

The preparation that was completed was adding a first layer of epoxy to both the hull and the bridge, which would take 18 to 24 hours to cure. Next, was laying fiberglass sheets on top of the epoxy. This was completed by adding an inner and outer layer of fiberglass right on top of each other. A final layer of epoxy was added on top of the fiberglass, which then was left to cure for 18 to 24 hours. After that, a fairing compound was used, which was laid over the epoxy to seal the pores of the materials so the ASV can be used as a marine vessel. This fairing compound took 12 to 15 hours to cure and turned to a greenish color when it was fully dry. This fairing compound was then sanded to a smooth finish and then spray painted black.

<p align="center">
<a ><img src="https://live.staticflickr.com/7843/46744293204_aa893232a7_o.jpg" height="260" alt="RoboBoat hUL Lafayette 
fabrication"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script> 

<a ><img src="https://live.staticflickr.com/7890/46567063235_ecf8e5323c_o.jpg" height="260" alt="First fiberglass layer"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a ><img src="https://live.staticflickr.com/7924/47520156092_5fcb10cff6_o.jpg" height="260" alt="Almost there"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>
</p>

<br />

<a ><img src="https://live.staticflickr.com/65535/51197901767_3190dbea6b_o.png" width="425" alt="thrusters"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

After the hull and bridge were coated for marine use, they were assembled and the electronics were installed. The first of the many electronics to be installed on the system, were the four Blue Robotics T-200 Thrusters. These thrusters were positioned on the ASV in an "X"-configuration to allow for holonomic motion, which allows for pure surge, sway, and yaw movement, as seen in the video below. Due to the pure surge, sway, and yaw movement, this boat is able to make tight turns as well as move directly left or right without the need to move forward or backwards such as a standard boat. This setup allows the ASV to parallel park easier than a traditional boat, and it allows for quicker movements around buoys, which is a big advantage for this competition. In the video below, a demonstration is presented on how this boat maneuvers in the water. Also, this video shows the very first time this ASV touched the water and moved under its own power!

<br />


<center>

<a data-flickr-embed="true" href="https://www.flickr.com/photos/crawlab/33949274818/in/album-72157707215763765/" title="First Time on the Water"><img src="https://live.staticflickr.com/31337/33949274818_cb0eab3d71_o.jpg" height="260" alt="First Time on the Water"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

</center>

<br />
<br />

<a data-flickr-embed="true" href="https://www.flickr.com/photos/crawlab/48010009852/in/album-72157707215763765/" title="E-stop and Status Light Check"><img style="float: right;" src="https://live.staticflickr.com/31337/48010009852_6a99cd76ed_o.jpg" height="250" alt="E-stop and Status Light Check"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

After this ASV was tested and seen to be a possible design, it was now time to add all the rest of the electronics in the electronics enclosure. This electronics enclosure was a Monoprice  Weatherproof Hard Case. It was used due to its ability to keep the electronics safe from water and was fairly priced. The special part about all of these electronics is the E-Stop. This long range (LoRa) E-Stop uses a heartbeat signal that is published via a Robot Operating System (ROS) node. When the E-Stop is pressed, the system removes power to the thrusters, but keeps providing power to the electronics. There are two physical E-Stops on this ASV and one remote LoRa E-Stop. As seen in this video, the E-Stop works great! In 2019, the Robot Operating System (ROS) software package  [GMapping](http://wiki.ros.org/gmapping) was used for mapping during the competition and data was collected via a  ZED Stereo Camera and Hokuyo Scanning Rangefinder (3D LiDAR) on the bow of the boat. GMapping is the most simplistic form of mapping as it is creates  a 2D map. GMapping also allows for path planning to be used, which is incredibly helpful in guiding the ASV to various destinations.
<br />
<br />

<a ><img style="float: left;" src="https://live.staticflickr.com/65535/51196213438_586395f948_o.png" height="260" alt="Broken Thruster"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<br />

Now, it was time for the team to compete at the competition, but there was a big obstacle the team had to overcome, one of the thrusters broke when transporting the ASV to Daytona Beach, Florida. Luckily, the [Embry-Riddle RoboBoat Team](https://www.roboticsassociation.org/roboboat) allowed the team to borrow a replacement thruster for the week. The 2019 Team worked on replacing the housing and at the end of the day even, though the weather was not on their side, they were able to put the boat out on the water! The ASV being on the water shows that the design met all the safety specifications for the competition. So, needless to say, this boat was a success!

<br />

<center>
<a ><img src="https://live.staticflickr.com/65535/48135398433_8bdfe8918f_o.jpg" height="260" alt="2019 International RoboBoat Competition - 45"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a ><img src="https://live.staticflickr.com/65535/48135447492_981e7ced31_o.jpg" height="260" alt="2019 International RoboBoat Competition - 109"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>
</center>

<br />
<br />

After the competition, the 2019 UL Lafayette Ragin' Cajuns  RoboBoat Team was awarded [$1,000](https://roboboat.org/2019/10/09/2019-roboboat-final-standings/) for the Manufacturing Award from [RoboNation](https://robonation.org/), an award of Recognition for $250 from Blue Robotics, and a NVIDIA Jetson TX2 from RoboNation. This was an outstanding performance made by this team and it really has been the fuel for the next teams to continue to improve the performance of this system.

<center>
<a ><img src="https://live.staticflickr.com/65535/48117409408_33a10029bf_o.jpg" height="260" alt="2019 RoboBoat Manufacturing Award"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a ><img src="https://live.staticflickr.com/65535/48135406183_ded6b4e19f_o.jpg" height="260" alt="2019 RoboBoat - Special Recognition from BlueRobotics"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a ><img src="https://live.staticflickr.com/65535/48135381943_e23e5b82fe_o.jpg" height="260" alt="Not a bad first year"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

</center>

<br />
<br />

<a data-flickr-embed="true" href="https://www.flickr.com/photos/crawlab/49705021942/in/album-72157709882895992/" title="rtabmap with Kinect"><img style="float: right;" src="https://live.staticflickr.com/31337/49705021942_06549286cf_o.jpg" height="270" alt="rtabmap with Kinect"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

During the 2019 to 2020 school year, the UL Lafayette Ragin' Cajuns RoboBoat Team focused on the coding and software aspect the ASV. There were areas of improvement that this team sought out to improve, such as creating a better way for the ASV to view its surroundings. This was done by adding a second ZED Stereo Camera and Hokuyo Scanning Rangefinder on the stern of the ASV. They also upgraded the mapping package from [GMapping](http://wiki.ros.org/gmapping) to [RTAB-Map](http://wiki.ros.org/rtabmap). RTAB-Map, or Real Time Appearance Based Mapping, is a 3-D loop closure Simultaneous Localization and Mapping (SLAM) algorithm. This video shows what RTAB-Map produces with a Kinect camera, which is similar to the ZED Stereo Camera. Also, with this new system design there would be a need for more processing power, which would produce a lot more heat than the team was comfortable with in the enclosure that the 2019 RoboBoat Team used. The UL Lafayette 2020 Ragin' Cajuns RoboBoat Team was able to find a sponsor to donate a new enclosure for this ASV. This new enclosure is perfect for the upgraded computing power and the new electronics on the ASV, due to its increased volume. This video shows the CAD model of the ASV with all the new hardware added. 

<br />

<center>
<a data-flickr-embed="true" href="https://www.flickr.com/photos/crawlab/50400449713/in/album-72157715576359036/" title="RoboBoat Turntable"><img src="https://live.staticflickr.com/31337/50400449713_d1cd0270ab_o.jpg" height="260" alt="RoboBoat Turntable"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>
</center>

<br />
<br />

The 2020 team was unable to complete the installation of these new components due to COVID-19 restrictions, but it was completed by the 2021 Ragin' Cajuns RoboBoat Team. The UL Lafayette 2020 RoboBoat Team obtained 2nd place overall in the competition. This competition was hosted virtually and judging was based on the Technical Design Report, website, and video. The Technical Design Report was ranked 3rd place out of the 10 teams that competed. This was a huge accomplishment for the team, and the team was awarded [$2,000](https://roboboat.org/2020/07/26/2020-roboboat-final-standings/) for coming in 2nd place! As we all know 2020 was a year of change due to COVID-19, so here are some photos of the UL Lafayette 2020 Team before social distancing. This was the last time the ASV was out on the water before the 2020 RoboBoat Competition.

<p align="center">
<a ><img src="https://live.staticflickr.com/65535/48374329637_6cd365aef7_o.jpg" height="260" alt="Testing at the UL Pool"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a ><img src="https://live.staticflickr.com/65535/48428302362_fc8fa1f896_o.jpg" height="260" alt="More Pool Testing - 3"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a ><img src="https://live.staticflickr.com/65535/48428302272_7976c2e8d4_o.jpg" height="260" alt="More Pool Testing - 1"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>
</p>

<br />
<br />

In August of 2020, a group of 4 undergrads took on the challenge of improving upon the UL Lafayette Ragin' Cajuns RoboBoat system. The team decided to change the approach used last year and decided to figure out what would be the most beneficial to upgrade on this system. The team determined the best place for improvements would be maximizing the points this system can obtain by adding an Unmanned Aerial Vehicle (UAV) to the system, due to the points the team would obtain from launching and landing on the UAV on ASV, as well as using the UAV for the object delivery task. With the UAV added to the system, there is a potential 1,200 points to be added to the total points. 

<a ><img style="float: left;" src="https://live.staticflickr.com/65535/51193887202_521475a42e_o.png" height="265" alt="51194800123_08104afebc_o"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

From there, the team conducted research on the different possibilities for the UAV in this competition. These possibilities included Quadcopter, Hexacopters, and VTOLs. The final design choice was a quadcopter UAV, due to its versatility and relatively small size. The team had to meet [design specifications](https://robonation.org/app/uploads/sites/3/2021/04/RoboBoat-2021-Rules-and-Task-Description_V2.pdf), with key specifcations including the UAV must be fully autonomous, meet the measurement requirements, and be positively buoyant. This led to the creation of the UAV located on the left. The Team decided that the main body would be DJI's F450 Frame. This frame was chosen due to it meeting all the [geometrical constraints](https://robonation.org/app/uploads/sites/3/2019/10/RoboBoat-Aerial-Vehicle-Guidelines.pdf), as well for its adaptability. As noted in the image below, the UAV addition to the ASV does in fact meet all of the measurement constraints to compete at this competition. 

<a ><img src="https://live.staticflickr.com/65535/51195996173_9dfcc570b1_o.png" height="260" alt="RoboBoat_Figures_Page_01"></a><script 
async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a ><img style="float: right;" src="https://live.staticflickr.com/65535/51196560939_28cda73f26_o.png" height="260" alt="RoboBoat_Figures_Page_03"></a><script 
async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

To save on weight and add versatility to the UAV, custom plates were made out of carbon fiber. The main customization occurred with the enclosures, which were 3-D printed out of PLA and ABS to ensure that the electronics would be in enclosures designed for IP 34 standards. Also, to allow for the UAV to be positively buoyant, the team 3-D printed fasteners that would lock onto industrial backer rod, which was determined to allow the UAV to float on the water. For autonomy, the UAV uses a Pixhawk 4 autopilot controller and a Raspberry Pi 4 Model B to send a receive MAVROS messages for control. Since the UAV is using the Pixhawk 4 and a companion computer, this allowed for the implementation of ROS. Control messages, specifically [MAVLink](http://wiki.ros.org/mavlink) messages, are sent to the flight controller via [mavros](http://wiki.ros.org/mavros). This UAV also has two different types of global positioning measurements. These are global positioning system (GPS) and real time kinematic (RTK) positioning. By being able to use more than one type of global positioning measurement, the system as a whole has the potential to increase in its precision and accuracy when moving. There is also an RC Receiver that allows for manual takeover with an RC Transmitter.

<br />
<br />

<a ><img style="float: left;" src="https://live.staticflickr.com/65535/51196560909_4d1e4ed1a4_o.png" height="260" alt="RoboBoat_Figures_Page_02"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

As the UAV was being built, there were improvements being made to the ASV. First and foremost, the new electronics enclosure needed to be mounted to the ASV. So, some of the team took a weekend to cut all of the necessary fittings and install the enclosure onto the ASV. Once the new enclosure was mounted, all of the old electronics needed to be transferred from the old enclosure to the new enclosure. After that task was completed, the team changed all of its ZED stereo cameras for the new [OAK-D](https://store.opencv.ai/products/oak-d) machine vision sensors that were obtained through the [OAK-D AI Competition](https://opencv.org/opencv-ai-competition-2021/). Once the two cameras were installed on the bow and stern of the ASV, the next thing to install was the Hokuyo Scanning Rangefinder on the stern ASV. The results of the installation can be seen below. 

<br />
<br />
<br />

<center>

<a ><img src="https://live.staticflickr.com/65535/51186651194_e8b75abd76_o.jpg" height="260" alt="Development for 
RoboBoat 2021 - 10"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a ><img src="https://live.staticflickr.com/65535/51185178262_39de37da22_o.jpg" height="260" alt="Development for RoboBoat 2021 - 15"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

</center>

<br />
<br />


<a data-flickr-embed="true" href="https://www.flickr.com/photos/crawlab/51185211587/in/album-72157715576359036/" title="RoboBoat Testing - 
14 May 2021 - 25"><img style="float: right;" src="https://live.staticflickr.com/31337/51185211587_99dd13e6dd_o.jpg" height="260" alt="RoboBoat Testing - 14 May 2021 - 25"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></
script>

<br />
<br />
<br />

Once all of the components were installed, the system was now ready to test. This test occurred at a local swamp and the progress of the system can be shown in the videos below. These videos show that the ASV is able to move around with all of the new improvements and the UAV is able to move around as well. During this testing the ASV and UAV were both being controlled through a remote.

<br />
<br />
<br />
<br />
<br />


<center>

<a data-flickr-embed="true" href="https://www.flickr.com/photos/crawlab/51185898751/in/album-72157715576359036/" title="RoboBoat Testing - 14 May 2021 - 26"><img src="https://live.staticflickr.com/31337/51185898751_c28c31de28_k.jpg" height="260" alt="RoboBoat Testing - 14 May 2021 - 26"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a data-flickr-embed="true" href="https://www.flickr.com/photos/crawlab/51186939985/in/album-72157715576359036/" title="Development for RoboBoat 2021 - 17"><img src="https://live.staticflickr.com/31337/51186939985_63ffc6603a_o.jpg" height="260" alt="Development for RoboBoat 2021 - 17"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

</center>

<br />
<br />

<!-- Honestly I would be exceedinly surprised if anyone is reading this, so if you are all I can say is thank you for helping me out because I am literally clueless on what I am doing for this website. I just hope its a good website to the judges -->
This is as far as the team was able to progress until a drastic turn occurred... one of the ASV's thrusters hit the hull during a small impact, which cracked the fiberglass. Unfortunately, the team is currently at a standstill until the problem is fixed. The team has looked into the possibilities for this fix and were able to determine that this crack in the fibrglass can be patched. Due to the fact that this hull can be repaired, it will allow for future teams to use this same hull and bridge design.


<center>

<a ><img src="https://live.staticflickr.com/65535/51198815173_4c78efe4ee_o.png" height="260" alt="Hull Damage"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

</center>


<!-- Dont Worry Brennan. I kept everything you had written before right here  All GOOD B 

## 2021 UL Lafayette Ragin' Cajuns ASV
  
  - The ASV for the 2021 competition is an improved version of the previous system. The computer aided design can be seen below following the cad is the current state of the ASV. 

<p align="center">
    <img width="58%" src="images/Current_ASV_State.JPEG
    " alt=""/><br>
    <strong>2021 ASV System(Need to update with just ASV Picture)</strong>
</p>

<p align="center">
    <img width="60%" src="images/New_ASV_CAD.png" alt=""/><br>
    <strong>2021 ASV CAD</strong>
</p>

   - This ASV was custom fabricated at UL Lafayette in 2019. It uses four Blue Robotics T-200 thrusters in an unique X configuration to allow holonomic motion. For perception, it has an Oak-D machine vision sensor and a Hokuyo LiDAR on both the bow and stern. This system has two NVIDIA Jetson TX2s for the heavy computation and a Raspberry Pi 4 with an EMLID NAVIO2 control HAT to aid in motor control and various sensing capabilities.

## The New Enclosure
* The cad files for the new enclosure was used to create new mounting brackets for this enclosure. 8020 T-Slotted frame was used because of its adaptability and ease of assembly. 

<p align="center">
    <img width="79%" src="images/ASV_FUL Lafayette.png" alt=""/><br>
    <strong>Complete ASV System</strong>
</p>

<p align="center">
    <img width="100%" src="images/Mounting_Bracket_for_ASV_Enclosure.png" alt=""/><br>
    <strong>Electronics Enclosure Brackets</strong>
</p>


## The New Electronics 

- The new electronics enclosure utilizes DIN-Rail to create easy mounting and arranging of the internal computers, sensors, and other electronics used in operation of the multi-agent system. 

<p align="center">
    <img width="90%" src="images/ASV_electronics_mount.png" alt=""/><br>
    <strong>2021 New Electronics Mount</strong>
</p>

- This years team was tasked with upgrading the system's electronics enclosure and electronics. The teardown of the old enclosure took place in late 2020.. 

<p align="center">
    <img width="60%" src="images/Teardown_ASV_2.jpg" alt=""/><br>
    <strong>2020 ASV System Teardown</strong>
</p>

<p align="center">
    <img width="40%" src="images/ASV_Electronics_Teardown_1.jpg" alt=""/><br>
    <strong>2020 ASV System's Electronics Teardown</strong>
</p>

<p align="center">
    <img width="60%" src="images/ASV_Enclosure_Teardown.jpg" alt=""/><br>
    <strong>2020 ASV System's Electronics Teardown</strong>
</p>

*More Coming soon...*


-->

