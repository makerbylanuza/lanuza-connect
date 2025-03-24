#include <LanuzaConnect.h>

LanuzaConnect esp("MAC");

void setup() {
  Serial.begin(115200);
  esp.init();
}

void loop() {
  // No loop is needed for this example
}
