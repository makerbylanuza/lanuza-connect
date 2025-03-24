#include <LanuzaConnect.h>

LanuzaConnect esp("TRANSMITTER");

// Dirección MAC de los receptores (sustituir por las correctas)
uint8_t receiver1[] = {0xB8, 0xD6, 0x1A, 0x47, 0xC3, 0x3C};
uint8_t receiver2[] = {0xB8, 0xD6, 0x1A, 0x47, 0xC3, 0x3C};


void setup() {
    Serial.begin(115200);
    esp.init();
    esp.addPeer(receiver1);
    esp.addPeer(receiver2);
}

void loop() {
   esp.sendString("Hola, receptor 1", receiver1);
   delay(1000);
   esp.sendString("Hola, receptor 2", receiver2);
   delay(5000);
}


