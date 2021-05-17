/* ----------------------------------------------------------------------------

Estop_LED_check.ino

Code to check the LED button for the RoboBoat LoRA E-stop

Created: 06/04/19
   - Joshua Vaughan
   - joshua.vaughan@louisiana.edu
   - http://www.ucs.louisiana.edu/~jev9637

 Modified:
   *

---------------------------------------------------------------------------- */

#define LED_PIN 14      // The pin the LED of the button is connected to
#define BUTTON_PIN 15   // The pin the button of the button 

int button_state = 1;   // Holds the state of the button, 1=not pressed

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // Define the button to be an input with a pullup
  pinMode(BUTTON_PIN, INPUT_PULLUP);

}

void loop() {
    // Using the pullup means that button_state will be HIGH (1) 
    // when the button is *not* pressed
    button_state = digitalRead(BUTTON_PIN);

    if (button_state) {  
        // If the button is not pressed, we want the LED on
        digitalWrite(LED_PIN, HIGH);
    }
    else {
        // Otherwise, we want it off
        digitalWrite(LED_PIN, LOW);
    }

    // Delay 100ms between checks of the button state
    delay(100);
}
