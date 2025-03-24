#include <LanuzaConnect.h>

LanuzaConnect esp("TRANSMITTER");

// Both receivers' MAC addresses (must be changed to actual addresses)
const uint8_t receiver1[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB};
const uint8_t receiver2[] = {0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67};


void setup() {
  Serial.begin(115200);
  esp.init();
  esp.addPeer(receiver1);
  esp.addPeer(receiver2);
}

void loop() {
  esp.sendString("Hello, receiver #1!", receiver1);
  delay(1000);
  esp.sendString("Hello, receiver #2!", receiver2);
  delay(4000);
}


