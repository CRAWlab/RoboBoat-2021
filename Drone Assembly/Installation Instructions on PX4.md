# Senior Projects Installation Instructions For PX4


## Hardware Installation

**Items that will need to be connected to Pixhawk**
1. [ESC’s](https://bluerobotics.com/store/thrusters/speed-controllers/besc30-r3/) 
2. [Power Module](https://shop.holybro.com/pixhawk-4-power-module-pm07_p1095.html)
3. Receiver for Transmitter (Also known as Controller)
4. [RTK (Will be placed in GPS Port)](https://www.sparkfun.com/products/15005)
5. [Raspberry Pi 4 (Will be placed in Telemetry 2 Port)](https://www.sparkfun.com/products/16811)
6. WiFi Antenna

<p align="center">
    <img width="60%" src="Figures/Fully Assembled PX4/PX4 Assembled.jpg" alt="Example of Assembled PX4"/><br>
    <strong>Figure 1: Example of Assembled PX4 [1]</strong>
</p>

### **A Few Things to Note**
1. The PX4 must be placed in the center of gravity of the drone
    * This means that it will be close to the center, but offset (towards the rear of  the drone) due to the weight being more forward on the drone. 
2. The ESC’s will be plugged in at the Main Out Ports of the Pixhawk 4
3. The RTK will be located at the GPS Port of the Pixhawk 4
4. Source for all of this information: 
    * [GPS-RTK Hookup Guide](https://learn.sparkfun.com/tutorials/gps-rtk-hookup-guide)
    * [SparkFun GPS-RTK Board Product Information/Features](https://www.sparkfun.com/products/15005)
    * [Pixhawk4-Pinouts.pdf](www.holybro.com/manual/Pixhawk4-Pinouts.pdf)
    * [DJI Flame Wheel 450 with Distance Sensor and RTK GPS](https://docs.px4.io/master/en/frames_multicopter/dji_flamewheel_450.html)

### **Installing Hardware on PX4**
1. [ESC’s](https://bluerobotics.com/store/thrusters/speed-controllers/besc30-r3/) 
    * There will be ESC’s for these motors
        - Motor 1 – Must be CCW
        - Motor 2 – Must be CCW
        - Motor 3 – Must be CW
        - Motor 4 – Must be CW
        - Figure 2 shows how these motors will connect to the I/O PWM Out Port. For instance, Motor 1 will fit into the IO_CH1 port on the I/O PWM Out Port. Motors 2, 3, and 4 will continue the trend.
        - These motors will be either hard wired to the ESC’s or they will connect to the ESC's via Banana Plugs 
            * The ESC’s can be hard wired to either the Frame of the F450 or to the Power Module
                * If soldered on the frame (Not optimal) - Figure 3
                    * On each corner of the board there will need to be the positive wire and negative wire soldered on. 
                    * Once the ESC’s are soldered in, they will connect to a Power Management Board (PWM)
                    * This PWM will connect to the I/O PWM Port
                    * No easy way to provide power to PX4, so option 2 it is   
                * If soldered on the Power Module (Optimal) - Figure 4
                    * Possibly a messier look, but allows for a battery monitor 
                    * The Power Wires w/ Yellow Terminal and the ESC’s will be soldered to this board as shown in Figure 4
                    * This board will provide power to the PX4 and ESC’s/Motors
<p align="middle">
<img width="20%" src="Figures/ESC & Motor/Motor PX4 Ports.png" alt="Motor Ports"/><br>
<strong>Figure 2: Motor Ports [2]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/ESC & Motor/DJI F450 Frame with Soldered ESC.png" alt="Motor Ports"/><br>
<strong>Figure 3: Motor Ports [3]</strong>
</p>  

<p align="center">
<img width="40%" src="Figures/Power Module/Power Module Soldered.png" alt="ESC’s and Battery Cable Soldered to the Power Module "/><br>
<strong>Figure 4: ESC’s and Battery Cable Soldered to the Power Module [1]</strong>
</p>     

2. [Power Module](https://shop.holybro.com/pixhawk-4-power-module-pm07_p1095.html)                
    * Installing Power Module to PX4 and Motors
        - As noted above solder the battery power wires and ESC’s to the Power Module
        - Plug the tinned wire ends into the FMU PWM Out Terminals, located on Figure 5
            * Motors will need to be placed in order from 1-4
        - The FMU PWR In port is used for servos, which we currently will not be using
        - The I/O PWM In port is used to transmit FMU PWM Out signals to the Pixhawk I/O PWM Out terminals
        - Figure 6 shows how the motors will be talking to the Pixhawk from the Power Module. 
            * The motors will connect to FMU, then the FMU PWM Out will transport the signal to the I/O PWM In
            * The I/O PWM In will transport the signal to the I/O PWM Out port on the PX4

<p align="center">
<img width="40%" src="Figures/Power Module/Power Module.png" alt="Power Module "/><br>
<strong>Figure 5: Power Module [4]</strong>
</p>   

<p align="center">
<img width="40%" src="Figures/Power Module/Power Module Configuration to PX4.png" alt="Power Module Configuration to PX4"/><br>
<strong>Figure 6: Power Module Configuration to PX4 [2]</strong>
</p>

3. Transmitter Receiver
    * Has to connect to PPM, DSM, or SBUS Radio Control
    * The Figures 7, 8, and 9 are ports from the PX4 and connect directly to the receiver. The receiver can be any of these version to work with the Pixhawk

<p align="center">
<img width="40%" src="Figures/Transmitter Receiver/DSM RC Port.png" alt="DSM RC Port"/><br>
<strong>Figure 7: DSM RC Port [2]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/Transmitter Receiver/PPM RC Port.png" alt="PPM RC Port"/><br>
<strong>Figure 8: PPM RC Port [2]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/Transmitter Receiver/SBUS RC Port.png" alt="SBUS RC Port"/><br>
<strong>Figure 9: SBUS RC Port [2]</strong>
</p>

4. [RTK (Will be placed in GPS Port)](https://www.sparkfun.com/products/15005)
    * First, for the RTK, what will be needed is 4 wires for the I2C Port and 2 wires for the UART pins on the Breakout Board. The generic view of the RTK board is shown in Figure 10.
        - The 4 I2C wires will fit into the I2C port on the Breakout Board
            * The three enhanced parts of Figure 11 (enclosed with a black box) are the options for I2C on this Breakout Board
            * Two of the options use Qwiic Connectors which will allow the system to accept 5V or 3.3V. The other option only allows for 3.3V. Using 3.3V is non-optimal because the PX4 provides 5V to the VCC Port, as shown in Figure 12 and a modulator or resistor will be needed to conver the voltage down from 5V to 3.3V
        - The 2 UART wires will fit in the RX/MOSI and TX/MISO pins on the Breakout Board, as seen in Figure 13
            * There is one choice for the UART pins. By default these pins are enabled
                * Must make sure the DSEL jumper on the rear of the board is open, as seen on Figure 14
    * Second, what will be needed is the board to be connected to the Pixhawk 4
        -  There are three choices in connecting the RTK to the Pixhawk 4
            * The first two choices are ports on the Pixhawk, as seen in Table 3
                * The first port is shown in Figure 12. This port is the main port to use for GPS/RTK. The highlighted marks are the ports used for our application.
                * The I2C uses the ports: GND, VCC, SDA, and SCL
                * The UART uses the ports: TX and RX
                * Problem with NOT using the I2C Port (Qwiic Connector): RTK uses 3V3 for an input voltage and the Pixhawk gives off 5V. There may need to be a resistor in place to make sure that the voltage would be correct in going into the system. The I2C port (Qwiic Connector) accepts 5V or 3.3V, but all logic is 3.3V
            * The second port is shown below. This port is optional to use if there is a need to use this for GPS/RTK, as seen in Figure 15
            * The third choice is not hooking the GPS up to the Pixhawk, but instead using the Raspberry Pi to use the RTK coordinates. This option is not an ideal option due to the Pixhawk being used on this device and taking up necessary ports to run the RTK Breakout Board on the Raspberry Pi.
    * The third part will be for the RTK to gain an antenna 
        -  This will be done by attaching a Interface Cable SMA to a U.FL connector. The U.FL connector is shown in the black box in Figure 16.
    * This is also explained in this link ([GPS-RTK Hookup Guide](https://learn.sparkfun.com/tutorials/gps-rtk-hookup-guide))

<p align="center">
<img width="40%" src="Figures/RTK/RTK Breakout Board.png" alt="RTK Breakout Board"/><br>
<strong>Figure 10: RTK Breakout Board [5]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/RTK/I2C Choices in RTK Breakout Board.png" alt="I2C Choices"/><br>
<strong>Figure 11: I2C Choices [5]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/RTK/GPS Module Main Port.png" alt="GPS Module Main Port"/><br>
<strong>Figure 12: GPS Module - Main Port [5]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/RTK/UART Port.png" alt="UART Port"/><br>
<strong>Figure 13: UART Port [5]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/RTK/DSEL Jumper Location.png" alt="DSEL Jumper Location"/><br>
<strong>Figure 14: DSEL Jumper Location [6]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/RTK/GPS Module 2.png" alt="GPS Module"/><br>
<strong>Figure 15: GPS Module [5]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/RTK/U.FL Connection Port on Breakout Board.png" alt="U.FL Connection Port on Breakout Board"/><br>
<strong>Figure 16: U.FL Connection Port on Breakout Board [5]</strong>
</p>

5. [Raspberry Pi 4 (Will be placed in Telemetry 2 Port)](https://www.sparkfun.com/products/16811)
    * This will plug into the Telemetry 2 Port (Figure 15)
    * Plug the 5V Power, TX, RX, and Ground ports from the Raspberry Pi 4 to the Pixhawk 4 as seen in Figure 16 and 17

<p align="center">
<img width="40%" src="Figures/Raspberry Pi 4/Telemetry Ports.png" alt="Telemetry Ports"/><br>
<strong>Figure 15: Telemetry Ports [5]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/Raspberry Pi 4/Raspberry Pi 3 Connected to PX4.png" alt="Raspberry Pi 3 Connected to PX4"/><br>
<strong>Figure 16: Raspberry Pi 3 Connected to PX4 [7]</strong>
</p>

<p align="center">
<img width="40%" src="Figures/Raspberry Pi 4/Raspberry Pi 4 Connections.png" alt="Raspberry Pi 4 Pinout"/><br>
<strong>Figure 17: Raspberry Pi 4 Pinout [8]</strong>
</p>

6. Wi-Fi Antenna
    * Will plug into the Telemetry Radio Port
    * Plugs straight into the Telemetry 1 and/or 2 port, as seen in Figure 15
    * Must have the ability to fit into all of these ports

## Software Installation

### **QGround Control**
1. Must be installed on a Desktop and this will be used to upload firmware to the Pixhawk
2. Follow these instructions for setting up QGround Control on Desktop - [Building QGround Control](https://docs.qgroundcontrol.com/master/en/getting_started/download_and_install.html)
3. Follow these instructions for setting firmware up on Pixhawk 4 - [Loading Firmware | PX4 User Guide](https://docs.px4.io/master/en/config/firmware.html)
4. Follow these instructions for setting up the Airframe - [Airframe Setup | PX4 User Guide](https://docs.px4.io/master/en/config/airframe.html)
    * Our Airframe is a Quadrotor X configuration

    <p align="middle">
    <img width="60%" src="Figures/Quadrotor X Configuration.png" alt="Quadrotor X Configuration"/><br>
    <strong>Figure 18: Quadrotor X Configuration [1]</strong>
    </p>

5. Follow these instructions for orienting the Pixhawk 4 correctly - [Sensor Orientation | PX4 User Guide](https://docs.px4.io/master/en/config/flight_controller_orientation.html)
6. Calibrate the Gyroscope by following this link - [Gyroscope Calibration | PX4 User Guide](https://docs.px4.io/master/en/config/gyroscope.html)
7. Calibrate the Accelerometer by following this link - [Accelerometer | PX4 User Guide](https://docs.px4.io/master/en/config/accelerometer.html)
8. Calibrate the Level Horizon Sensor by following this link - [Level Horizon Calibration | PX4 User Guide](https://docs.px4.io/master/en/config/level_horizon_calibration.html)
9. Calibrate the Air Speed by following this link - [AirSpeed Calibration | PX4 User Guide](https://docs.px4.io/master/en/config/airspeed.html)
10. Setting up the Radio Remote Control follow this link- [Radio (Remote Control) Setup | PX4 User Guide](https://docs.px4.io/master/en/config/radio.html)
11. Setting up the Joystick follow this link - [Joystick Joystick Setup | PX4 User Guide](https://docs.px4.io/master/en/config/joystick.html)
12. Setting up the Flight Mode Configuration - [Flight Mode Configuration | PX4 User Guide](https://docs.px4.io/master/en/config/flight_mode.html)
    * Off Board Mode
        - Off Board Mode is what will allow us to use MAVROS in the system
        - This basically removes the RC control in this Configuration, but we can have multiple configurations with this flight controller
        - Better link for Off Board Mode - [Offboard Mode | PX4 User Guide](https://docs.px4.io/master/en/flight_modes/offboard.html)
13. Setting up the Battery and Power Module - [Battery and Power Module Setup | PX4 User Guide](https://docs.px4.io/master/en/config/battery.html)
    * Use this for having it understand the Battery Percentage
14. Checking the Motor - [Motor/Servo Checks | PX4 User Guide](https://docs.px4.io/master/en/config/motors.html)
15. Set the GeoFence - [GeoFence | PX4 User Guide](https://docs.px4.io/master/en/flying/geofence.html)
16. Set a Kill Switch - [Kill Switch | PX4 User Guide](https://docs.px4.io/master/en/config/safety.html#kill-switch)
17. Extra Help
    * [QGroundControl - FlyView](https://docs.qgroundcontrol.com/master/en/FlyView/FlyView.html)
        - This will require the Pre-Flight Checklist to be accomplished
    * [QGroundControl - PlanView](https://docs.qgroundcontrol.com/master/en/PlanView/PlanView.html)
    * [QGroundControl - Preflight Checklist](https://docs.qgroundcontrol.com/master/en/FlyView/FlyView.html#preflight_checklist)

### **MavROS**
1. [Installation of MAVROS](https://docs.px4.io/master/en/ros/mavros_installation.html)
2. [MAVROS OffBoard Example](https://docs.px4.io/master/en/ros/mavros_offboard.html)
3. Terminology for MAVROS
    * /mavros/setpoint_position/local
        - With this command we can set the target position and the yaw of the drone
    * /mavros/setpoint_attitude/attitude	
        - With this command we can set the target altitude
    * /mavros/setpoint_attitude/att_throttle
        - With this command we can set the target throttle level

### **RTK**
1. This [link](https://learn.sparkfun.com/tutorials/gps-rtk-hookup-guide) will answer the Following:
    * How to connect RTK to Correction Source
    * How to set up RTK as a Base Station

## References
[1] “Pixhawk Wiring Quick Start,” Pixhawk Wiring Quick Start | PX4 User Guide. [Online]. Available: https://docs.px4.io/master/en/.html. [Accessed: 09-Jan-2021]. 

[2] "Pixhawk 4,” Holybro. [Online]. Available: http://www.holybro.com/product/pixhawk-4/. [Accessed: 10-Jan-2021].

[3]	DJI, DJI F450 Setup Demo-Frame Assembly. [Online]. Available: https://www.youtube.com/watch?v=pUTHIL_Xfcc&amp;feature=emb_logo. 

[4] “Pixhawk 4 Power Module (PM07),” Holybro. [Online]. Available: http://www.holybro.com/product/pixhawk-4-power-module-pm07/. [Accessed: 13-Jan-2021]. 

[5]GPS-RTK Hookup Guide. [Online]. Available: https://learn.sparkfun.com/tutorials/gps-rtk-hookup-guide. [Accessed: 28-December-2020].

[6]	M. #894355, M. #1249684, M. #16991, M. #1460730, M. #1535910, and M. #1500361, “SparkFun GPS-RTK Board - NEO-M8P-2 (Qwiic),” GPS-15005 - SparkFun Electronics. [Online]. Available: https://www.sparkfun.com/products/15005. [Accessed: 10-Jan-2021].

[7]	Markvanhaze (Markvanhaze), kevindgoff (Kevin Goff), Kyomo_Jung (Kyomo Jung), fnoop (Fnoop), skylab (Nicholas Irabor), nikker (Nick), seaman (Evgeni Trenev), DMB_A (Dharshana Athauda), Alexander_Perez (Alexander Perez), Ppoirier (Ppoirier), and Kevin_K (Kevin Klemens), “Raspberry Pi 3 connecting to Pixhawk,” ArduPilot Discourse, 07-Jun-2016. [Online]. Available: https://discuss.ardupilot.org/t/raspberry-pi-3-connecting-to-pixhawk/9524. [Accessed: 10-Jan-2021].

[8]	U. Hiwarale, “An introduction to Raspberry Pi 4 GPIO and controlling it with Node.js,” Medium, 01-Sep-2020. [Online]. Available: https://medium.com/sysf/an-introduction-to-raspberry-pi-4-gpio-and-controlling-it-with-node-js-10f2ce41af12. [Accessed: 10-Jan-2021].