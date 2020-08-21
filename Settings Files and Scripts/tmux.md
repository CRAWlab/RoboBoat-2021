# Allow tmux scrolling and fix client sizes

Add these lines to a file named `.tmux.conf` in your home directory. The leading `.` *does* need to be here. You may need to create it.

    # Make mouse useful
    set -g mouse on
    
    # Only resize to the smallest client if they are looking at it
    setw -g aggressive-resize on
    
The steps to do so should look something like:

    cd ~
    nano .tmux.conf
    
Then, paste in the lines above. To exit nano, Control-X, enter `y` that you would like to save the file, then press enter. These changes will apply the next time t-mux is started.