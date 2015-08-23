// #include "Keyboard.h"
// #include "HID.h"

// https://www.arduino.cc/en/Reference/KeyboardBegin
// https://www.arduino.cc/en/Tutorial/KeyboardMessage
// https://www.arduino.cc/en/Tutorial/KeyboardReprogram

// http://www.cplusplus.com/doc/tutorial/structures/
struct Key {
  int pin;
  char keyCode;
  boolean wasPushed;
};

const int NUM_OF_KEYS = 4;
Key keys[NUM_OF_KEYS];

void setup() {
  // Initialize key data
  // { buttonPin, keyCode, wasPushed }
  keys[0] = { 2, KEY_LEFT_CTRL , false };
  keys[1] = { 3, KEY_LEFT_ALT, false};
  keys[2] = { 4, KEY_LEFT_SHIFT, false };
  keys[3] = { 5, KEY_BACKSPACE, false };

  // make pins inputs and turn on the
  // pullup resistor so they go high unless
  // connected to ground:
  for(int i = 0; i < NUM_OF_KEYS; i++) {
    pinMode(keys[i].pin, INPUT_PULLUP);
  }

  Keyboard.begin();
}

void loop() {
  for(int i = 0; i < NUM_OF_KEYS; i++) {
    if((digitalRead(keys[i].pin) == LOW) && (keys[i].wasPushed == false)) { // If the key is pressed...
      Keyboard.press(keys[i].keyCode); // Send the key
      keys[i].wasPushed = true;
    }
    else if ((digitalRead(keys[i].pin) == HIGH) && (keys[i].wasPushed == true)) {
      Keyboard.release(keys[i].keyCode);
      keys[i].wasPushed = false;
    }
  }
}
