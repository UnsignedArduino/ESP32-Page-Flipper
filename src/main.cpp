#include <Arduino.h>
#include <BLEHIDDevice.h>
#include <BleKeyboard.h>
#include <SimpleLed.h>
#include <SimpleTouch.h>

const gpio_num_t FORWARD_TOUCH_PAD = GPIO_NUM_14;
const gpio_num_t BACKWARD_TOUCH_PAD = GPIO_NUM_27;

BleKeyboard bleKeyboard("Page Flipper");
SimpleLed led(LED_BUILTIN);
SimpleTouch forwardTouch;
SimpleTouch backwardTouch;

void setup() {
  Serial.begin(115200);

  forwardTouch.begin(FORWARD_TOUCH_PAD);
  backwardTouch.begin(BACKWARD_TOUCH_PAD);

  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    if (forwardTouch.justPressed()) {
      bleKeyboard.write(KEY_RIGHT_ARROW);
    }
    if (backwardTouch.justPressed()) {
      bleKeyboard.write(KEY_LEFT_ARROW);
    }
    led.setState(forwardTouch.isTouched() || backwardTouch.isTouched());
  } else {
    led.blink(200);
  }

  forwardTouch.update();
  backwardTouch.update();
  led.update();
}
