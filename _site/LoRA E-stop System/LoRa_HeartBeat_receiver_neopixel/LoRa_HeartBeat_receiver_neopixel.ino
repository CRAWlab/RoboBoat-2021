/* ----------------------------------------------------------------------------

LoRa_HeartBeat_receiver_neopixel.ino

Arduino sketch to receive heartbeat messages and change the color of a NeoPixel 
strand based on current status. The strand also does a "Knight Rider" effect
since moving colors are easier to see than static ones. It also sends and 
receives status messages over the serial port.

Intended for use with the Feather M0 with LoRa Radio:
  * https://www.adafruit.com/product/3178

Modified from the example code at Adafruit's Tutorial:
  * https://learn.adafruit.com/adafruit-feather-m0-radio-with-lora-radio-module/using-the-rfm-9x-radio
  * https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use

Created: 05/09/19
   - Joshua Vaughan
   - joshua.vaughan@louisiana.edu
   - http://www.ucs.louisiana.edu/~jev9637

 Modified:
   * 05/16/19 - JEV - joshua.vaughan@louisiana.edu
        - Added serial comm. for status
        - Updated yellow color

 TODO:
 * 05/16/19 - Add relay control output, just digital IO
 * 05/16/19 - Update messages to/from CPU for status
 * 05/16/19 - clean up color assignment - use an array? struct?

---------------------------------------------------------------------------- */

#include <stdio.h>
#include <SPI.h>
#include <RH_RF95.h>
#include <Adafruit_NeoPixel.h>

/* for Feather32u4 RFM9x
#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 7
*/

// for feather m0 RFM9x
#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 3


/* for shield 
#define RFM95_CS 10
#define RFM95_RST 9
#define RFM95_INT 7
*/

/* Feather 32u4 w/wing
#define RFM95_RST     11   // "A"
#define RFM95_CS      10   // "B"
#define RFM95_INT     2    // "SDA" (only SDA/SCL/RX/TX have IRQ!)
*/

/* Feather m0 w/wing 
#define RFM95_RST     11   // "A"
#define RFM95_CS      10   // "B"
#define RFM95_INT     6    // "D"
*/

#if defined(ESP8266)
  /* for ESP w/featherwing */ 
  #define RFM95_CS  2    // "E"
  #define RFM95_RST 16   // "D"
  #define RFM95_INT 15   // "B"

#elif defined(ESP32)  
  /* ESP32 feather w/wing */
  #define RFM95_RST     27   // "A"
  #define RFM95_CS      33   // "B"
  #define RFM95_INT     12   //  next to A

#elif defined(NRF52)  
  /* nRF52832 feather w/wing */
  #define RFM95_RST     7    // "A"
  #define RFM95_CS      11   // "B"
  #define RFM95_INT     31   // "C"
  
#elif defined(TEENSYDUINO)
  /* Teensy 3.x w/wing */
  #define RFM95_RST     9    // "A"
  #define RFM95_CS      10   // "B"
  #define RFM95_INT     4    // "C"
#endif


// Change to 434.0 or other frequency, must match RX's freq!
#define RF95_FREQ 915.0

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);

// Onboard LED pin
#define LED 13

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 30

// Pin that relay output is connected to in order to know status 
// of hardwired e-stops
#define WIRED_PIN 14
int relay_state = 1;   // Holds the state of the relay, 1=open

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// Define some colors for the NeoPixels
uint32_t RED_LOW = strip.Color(32, 0, 0);
uint32_t RED_MED = strip.Color(64, 0, 0);
uint32_t RED_HIGH = strip.Color(255, 0, 0);
uint32_t GREEN_LOW = strip.Color(0, 32, 0);
uint32_t GREEN_MED = strip.Color(0, 64, 0);
uint32_t GREEN_HIGH = strip.Color(0, 255, 0);
uint32_t BLUE_LOW = strip.Color(0, 0, 32);
uint32_t BLUE_MED = strip.Color(0, 0, 64);
uint32_t BLUE_HIGH = strip.Color(0, 0, 255);
uint32_t YELLOW_LOW = strip.Color(32, 32, 0);
uint32_t YELLOW_MED = strip.Color(64, 64, 0);
uint32_t YELLOW_HIGH = strip.Color(255, 255, 0);
uint32_t WHITE_LOW = strip.Color(32, 32, 32);
uint32_t WHITE_MED = strip.Color(64, 64, 64);
uint32_t WHITE_HIGH = strip.Color(255, 255, 255);

// Variables to hold the current status of the Neopixel strip
// Initialized to be red
uint32_t low = RED_LOW;
uint32_t med = RED_MED;
uint32_t high = RED_HIGH;

// A boolean value to keep track of the current status, okay if true
bool status_okay = false;

// A string to hold the status message from the CPU
String status_string = "green";

// Configuration variables for relay control
#define RELAY_PIN 5       // pin connected to the relay

// The desired time to loop on receiving (ms)
#define DESIRED_LOOP_TIME 100 

void setup() {
    
    // Set up the onboard LED pin as output
    pinMode(LED, OUTPUT);

    // Set up the relay status pin as an input with pullup resistor
    pinMode(WIRED_PIN, INPUT_PULLUP);
    
    // Set up the pin connected the relay as an output
    pinMode(RELAY_PIN, OUTPUT);
    
    pinMode(RFM95_RST, OUTPUT);
    digitalWrite(RFM95_RST, HIGH);

    Serial.begin(115200);
    Serial.setTimeout(100);

    // Wait for the serial monitor to open
    // Be sure to comment this out in application
    //    while (!Serial) {
    //        delay(1);
    //    }
    delay(100);

    // manual reset
    digitalWrite(RFM95_RST, LOW);
    delay(10);
    digitalWrite(RFM95_RST, HIGH);
    delay(10);

    while (!rf95.init()) {
        //Serial.println("LoRa radio init failed");
        while (1);
    }
    //Serial.println("LoRa radio init OK!");

    // Defaults after init are 434.0MHz, modulation GFSK_Rb250Fd250, +13dbM
    if (!rf95.setFrequency(RF95_FREQ)) {
        //Serial.println("setFrequency failed");
        while (1);
    }
    //Serial.print("Set Freq to: "); Serial.println(RF95_FREQ);

    // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on

    // The default transmitter power is 13dBm, using PA_BOOST.
    // If you are using RFM95/96/97/98 modules which uses the PA_BOOST transmitter pin, then
    // you can set transmitter powers from 5 to 23 dBm:
    rf95.setTxPower(23, false);

    // Now, set up the NeoPixels
    strip.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();             // Turn OFF all pixels ASAP
    strip.setBrightness(255); // Set BRIGHTNESS to about 1/2 (max = 255)
}

void loop() {
    const char HEARTBEAT_MESSAGE[] = "$ULheartbeat";
    const int HEARTBEAT_MESSAGE_LENGTH = sizeof(HEARTBEAT_MESSAGE) - 1;
    static int num_missed_heartbeats = 0;
    const int MAX_MISSED_HEARTBEATS = 10;

    static uint8_t going = 1;
    static uint8_t pixel_index = 0;

    unsigned long start_time;
    unsigned long elapsed_time;
    start_time = millis();
    
    if (rf95.available()) {
        // Add a linespace between each heartbeat loop
        // TODO: 05/16/19 - JEV - Comment out in application
        //Serial.println("");
    
        // Should be a message for us now
        uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
        uint8_t len = sizeof(buf);
    
        if (rf95.recv(buf, &len)) {
            // Here, we'll always indicate that we received a message
            // In operation, we probably don't want to always print this out
            digitalWrite(LED, HIGH);
            //RH_RF95::printBuffer("Received: ", buf, len);
            //Serial.print("Got: ");
            //Serial.println((char*)buf);

            // Compare the message received with the HEARTBEAT_MESSAGE expected
            // If it doesn't match, increment the num_missed_heartbeats counter
            // If it does, reset the counter and send an acknowledgement message
            if (strncmp((char*)buf, HEARTBEAT_MESSAGE, HEARTBEAT_MESSAGE_LENGTH) != 0) {
              //Serial.println("Heartbeat didn't match.");
              num_missed_heartbeats = num_missed_heartbeats + 1;
            }
            else {
                // reset missed heartbeat counter 
                num_missed_heartbeats = 0;
                
                // Set the status okay to true
                status_okay = true;

                // This will print the signal strength of the last message received.
                //Serial.print("RSSI: ");
                //Serial.println(rf95.lastRssi(), DEC);
                
                // Send a reply
                uint8_t data[] = "$UL_ACK";
                rf95.send(data, sizeof(data));
                rf95.waitPacketSent();
                // Serial.println("Sent a reply");
                digitalWrite(LED, LOW);
            }
        }
    }
    else { 
        // If there was no data availalbe, we also increment the num_missed_heartbeats counter
        num_missed_heartbeats = num_missed_heartbeats + 1;
        
        if (num_missed_heartbeats < MAX_MISSED_HEARTBEATS) {
            //Serial.println("Heartbeat missed");    
            ; // Do nothing here
        }
    }
    
    // Now, read the serial communication with the host CPU
    if (Serial.available() > 0) {
        // get incoming data, which must be terminated with a newline character
        status_string = Serial.readStringUntil('\r'); // TODO: Should this be /n?
        //Serial.print("Status: ");
        //Serial.println(status_string);
    }
    
    // Compare the message received with the the available colors
    // to set the color of the LED strip
    if (status_string.equals("green")) {
        low = GREEN_LOW;
        med = GREEN_MED;
        high = GREEN_HIGH;
    }
    else if (status_string.equals("yellow")) {
        low = YELLOW_LOW;
        med = YELLOW_MED;
        high = YELLOW_HIGH;
    }
    else if (status_string.equals("blue")) {
        low = BLUE_LOW;
        med = BLUE_MED;
        high = BLUE_HIGH;
    }
    else if (status_string.equals("white")) {
        low = WHITE_LOW;
        med = WHITE_MED;
        high = WHITE_HIGH;
    }
    else if (status_string.equals("red")) {
        low = RED_LOW;
        med = RED_MED;
        high = RED_HIGH;
    }
    
    // Now, check if we've exceeded the maximum number of missed beats
    // and process the NeoPixel colors accordingly
    if (num_missed_heartbeats < MAX_MISSED_HEARTBEATS) {
        status_okay = true;
        //Serial.println("Status Okay");
        
        // Keep the relay pin high to keep the relay closed/on
        digitalWrite(RELAY_PIN, HIGH);
    }
    else if (num_missed_heartbeats == MAX_MISSED_HEARTBEATS) {
        //Serial.println("Heartbeat missed");
        //Serial.println("Missed too many heartbeats!!!");
        digitalWrite(LED, HIGH);

        status_okay = false;
        
        // Set the status LED Strip to red
        low = RED_LOW;
        med = RED_MED;
        high = RED_HIGH;
        
        // Keep the relay pin low to let the relay open
        digitalWrite(RELAY_PIN, LOW);
    }
    else { // Do not care what the status is from the CPU, set red
        digitalWrite(LED, HIGH);

        status_okay = false;
        low = RED_LOW;
        med = RED_MED;
        high = RED_HIGH;
        
        // Keep the relay pin low to let the relay open
        digitalWrite(RELAY_PIN, LOW);
    }

    // Now check the status of the relay output, which tells us the status of
    // the hardwired E-stops
    // Using the pullup means that button_state will be HIGH (1) 
    // when the relay is open
    if (digitalRead(WIRED_PIN)) {
        digitalWrite(LED, HIGH);

        status_okay = false;
        low = RED_LOW;
        med = RED_MED;
        high = RED_HIGH;
    }

    // Increment our Knight Rider Effect with color based on the current status
    // Fill the neopixels with medium brightness 
    strip.fill(high, 0);

    if (pixel_index + 5 >= LED_COUNT) {
        going = 0;
    }
    else if (pixel_index <= 0) {
        going = 1;
    }

    if (going) {
        strip.fill(low, pixel_index, 5);              
        pixel_index = pixel_index + 1;
    }
    else {
        strip.fill(low, pixel_index, 5);
        pixel_index = pixel_index - 1;
    }
    strip.show();  // Update NeoPixel strip

    // Serial.print("Status: ");
    if (status_okay) {
        Serial.println("$ESTOP,OK");
    }
    else {
        Serial.println("$ESTOP,STOPPED");
    }
    
    elapsed_time = millis() - start_time;

    if (elapsed_time < DESIRED_LOOP_TIME) {
        delay(DESIRED_LOOP_TIME - elapsed_time);
    }
}
