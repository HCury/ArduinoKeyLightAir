#define LED_PIN 10 // Connect your LED to digital pin 10 (or any other PWM pin)
#define BRIGHTNESS_STEP 25 // How much to change the brightness each time a key is pressed

int init_brightness = 128; // Start at medium brightness
int brightness = init_brightness;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600); // Start serial communication at 9600 baud
}

void loop() {
  if (Serial.available() > 0) {
    char ch = Serial.read(); // Read the incoming byte

    if (ch == '0') {
      brightness = 0; // Turn off the LED
    }else if (ch == '1'){
      brightness = init_brightness;
    } else if (ch == '2') {
      brightness = min(brightness + BRIGHTNESS_STEP, 200); // Increase brightness, but not above 200 for safety
    } else if (ch == '3') {
      brightness = max(brightness - BRIGHTNESS_STEP, 0); // Decrease brightness
    }

    // Set the new brightness
    analogWrite(LED_PIN, brightness);
  }
}


