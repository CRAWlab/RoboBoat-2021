# on a RPi
docker run -it --rm --privileged \
    --env=LOCAL_USER_ID="$(id -u)" \
    -v /home/pi/src/PX4-Autopilot:/src/PX4-Autopilot:rw \
    -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
    -e DISPLAY=:0 \
    -p 14445:14445/udp \
    --name=UAV_companion ros:melodic-mavros-mavlink bash

roslaunch mavros px4.launch fcu_url:=/dev/ttyAMA0 gcs_url:=udp://@192.168.143.167


# checking IP of container 
docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' UAV_companion