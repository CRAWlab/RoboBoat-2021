#!/bin/bash

while true
    do
        clear
        
        cpu=$(</sys/class/thermal/thermal_zone0/temp)

        echo ""
        echo "$(date) @ $(hostname)"
        echo "------------------------------"
        echo "CPU: temp=$((cpu/1000))'C"
        echo "GPU: $(/opt/vc/bin/vcgencmd measure_temp)"
        echo ""
        
        sleep 1 
    done
