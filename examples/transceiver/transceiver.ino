#include <LanuzaConnect.h>

LanuzaConnect esp("TRANSCEIVER");

// Dirección MAC del receptor
uint8_t peer[] = {0xB0, 0xA7, 0x32, 0x16, 0x1F, 0x9C};

void setup() {
    Serial.begin(115200);
    esp.init();
    esp.addPeer(peer);

}

void loop() {
   esp.sendString("Hola, amigo", peer);
   delay(5000);
}


