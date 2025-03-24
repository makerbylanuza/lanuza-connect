#include <LanuzaConnect.h>

LanuzaConnect esp("TRANSCEIVER");

// Peer's MAC address (must be changed to actual address)
uint8_t peer[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB};

void setup() {
  Serial.begin(115200);
  esp.init();
  esp.addPeer(peer);
}

void loop() {
  esp.sendString("Hello, peer!", peer);
  delay(5000);
}
