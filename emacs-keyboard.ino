// -*- c++ -*-
// #include "Keyboard.h"
// #include "HID.h"

struct Key {
  int pin;
  char keyCode;
  boolean wasPushed;
};

const int NUM_OF_KEYS = 4;
Key keys[NUM_OF_KEYS];

void setup() {
  keys[0] = { 5, KEY_LEFT_CTRL , false };
  keys[1] = { 4, KEY_LEFT_ALT, false};
  keys[2] = { 3, KEY_LEFT_SHIFT, false };
  keys[3] = { 2, KEY_LEFT_GUI, false };

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
    if((digitalRead(keys[i].pin) == LOW) && (keys[i].wasPushed == false)) {
      Keyboard.press(keys[i].keyCode); // Send key down
      keys[i].wasPushed = true;
    }
    else if ((digitalRead(keys[i].pin) == HIGH) && (keys[i].wasPushed == true)) {
      Keyboard.release(keys[i].keyCode); // Send key up
      keys[i].wasPushed = false;
    }
  }
  delay(10);
}
