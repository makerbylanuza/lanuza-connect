#include <LanuzaConnect.h>

LanuzaConnect esp("TRANSMITTER");

int number = 1;
String text;

// Receiver's MAC address (must be changed to actual address)
const uint8_t receiver[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB};

void setup() {
  Serial.begin(115200);
  esp.init();
  esp.addPeer(receiver);
}

void loop() {
  text = "Hello World! #" + String(number);
  esp.sendString(text, receiver);

  number++;
  delay(5000);
}