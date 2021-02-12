# This is an auto generated Dockerfile for ros:ros-base
# generated from docker_images/create_ros_image.Dockerfile.em 

#This is from the ROS Docker Hub https://hub.docker.com/_/ros
FROM ros:melodic-robot

# install ros packages from osrf https://github.com/osrf/docker_images
RUN apt-get update && apt-get install -y --no-install-recommends \
    ros-melodic-robot=1.4.1-0* \
    && rm -rf /var/lib/apt/lists/*

RUN sudo apt-get update && sudo apt-get install -y \
    ros-melodic-mavros \
    ros-melodic-mavros-extras \
    nano \
    ros-melodic-usb-cam \
    ros-melodic-roscpp \
    ros-melodic-catkin \
    ros-melodic-compressed-image-transport \
    ros-melodic-roscpp \
    ros-melodic-std-msgs \
    ros-melodic-std-srvs \
    ros-melodic-sensor-msgs \
    ros-melodic-camera-info-manager \
    ros-melodic-dynamic-reconfigure \
    ros-melodic-diagnostic-updater \
    ros-melodic-message-generation \
    ros-melodic-message-runtime

RUN wget https://raw.githubusercontent.com/mavlink/mavros/master/mavros/scripts/install_geographiclib_datasets.sh \
    && chmod +x install_geographiclib_datasets.sh \
    && sudo ./install_geographiclib_datasets.sh \
    && rm install_geographiclib_datasets.sh

RUN rm -rf /var/lib/apt/lists/* 
