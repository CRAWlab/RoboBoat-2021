## First step on a RPi terminal 
* docker run -it --rm --privileged \
-v /home/pi/src:/src:rw \
 --name=UAV_companion ros:melodic-mavros-mavlink bash

* Then launch a roscore in the terminal


## Second step from separate terminal that is SSHd into the RPi 
    * (Make sure Host Name for QGCS is localhost:14540) 
    * (Have a QGCS session up  on same network)
docker exec -it UAV_companion bash

source ros_entrypoint.sh 

rosrun mavros mavros_node _fcu_url:=/dev/ttyAMA0:921600 _gcs_url:=udp://@192.168.143.232
