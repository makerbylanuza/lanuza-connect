#include <LanuzaConnect.h>

LanuzaConnect esp("MAC");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  esp.init();
}

void loop() {
  // put your main code here, to run repeatedly:

}
