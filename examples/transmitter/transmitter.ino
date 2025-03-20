#include <LanuzaConnect.h>

LanuzaConnect esp("TRANSMITTER");

int number = 1;
String text;

// Dirección MAC del receptor
uint8_t receiver[] = {0xB8, 0xD6, 0x1A, 0x47, 0xC3, 0x3C};

void setup() {
  Serial.begin(115200);
  esp.init();
  esp.addPeer(receiver);
    
}

void loop() {
  text = String("Hola mundo " + number);
  esp.sendString(text, receiver);
  delay(5000);
}


