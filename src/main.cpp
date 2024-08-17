#include <Arduino.h>
#include <SimpleLed.h>

SimpleLed led(LED_BUILTIN);

void setup() {
  Serial.begin(115200);
  
  led.blink(500);
}

void loop() {
  led.update();
}
