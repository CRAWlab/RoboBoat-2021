# on a RPi
docker run -it --rm --privileged \
    --env=LOCAL_USER_ID="$(id -u)" \
    -v /home/pi/src/PX4-Autopilot:/src/PX4-Autopilot:rw \
    -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
    -e DISPLAY=:0 \
    -p 14570:14570/udp \
    --name=UAV_companion px4io/px4-dev-ros-melodic bash
    px4io/px4-dev-raspi bash 
docker pull px4io/px4-dev-ros-melodic
# PX4 
roslaunch mavros px4.launch

# checking IP o container 
docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' UAV_companion