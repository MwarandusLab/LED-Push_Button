const int buttonPin = 6;  // Replace with the appropriate button pin
const int ledPin = 2;    // Replace with the appropriate LED pin

int buttonState = 0;
int previousButtonState = 0;
bool ledOn = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Check if the button state has changed
  if (buttonState != previousButtonState) {
    // If the button is pressed
    if (buttonState == LOW) {
      ledOn = !ledOn;  // Toggle the LED state
      digitalWrite(ledPin, ledOn ? HIGH : LOW);  // Turn the LED on or off
    }

    delay(50);  // Debounce delay to avoid multiple state changes

    // Update the previous button state
    previousButtonState = buttonState;
  }
}
