#include <LanuzaConnect.h>

LanuzaConnect esp("RECEIVER");

String last = "";

void setup() {
    Serial.begin(115200);
    esp.communicationStartup();    
}

void loop() {
  if (last != esp.getLast()) {
    last = esp.getLast();
    Serial.println("No sabía que hubiese tantos mundos...")
  }
}


