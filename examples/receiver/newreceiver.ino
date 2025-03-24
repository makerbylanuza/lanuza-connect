#include <LanuzaConnect.h>

LanuzaConnect esp("RECEIVER");

String last = "";

void setup() {
  Serial.begin(115200);
  esp.init();    
}

void loop() {
  if (last != esp.getLast()) {
    last = esp.getLast();
    Serial.println("Received a new string!");
  }
}