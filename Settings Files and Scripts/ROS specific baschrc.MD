# `.bashrc` for RoboBoat 2019

Add the following lines to the `.bashrc` file in your home (`~`) directory.

    # Define the Jeston as ROS_MASTER
    export ROS_MASTER_URI=192.168.0.120

    # Define your ROS_HOSTNAME
    export ROS_HOSTNAME=your.ip.address.here
    
where `your.ip.address.here` is your IP address. If you are adding this to your `.bachrc` file, you should probably have a network profile set up with a fixed IP address at this address.

The steps to do so should look something like:

    cd ~
    nano .bashrc
    
Then, paste in the lines above. To exit nano, Control-X, enter `y` that you would like to save the file, then press enter. These changes will apply for terminals created after the change to `.bashrc` is made. To apply them immediately, you can use:

    source ~/.bashrc
    
Note that if you do this, you may have to "re-source" your ROS workspace.

You can see [this page](https://wiki.ros.org/ROS/EnvironmentVariables), for more information on the environmental variables that ROS uses.