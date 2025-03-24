#ifndef LANUZACONNECT_H
#define LANUZACONNECT_H

// Include libraries
#include <esp_now.h>
#include <WiFi.h>

// Data type for the message
typedef struct struct_message {
  char data[250];
} struct_message;

class LanuzaConnect {
public:
  // Constructor
  LanuzaConnect(const String &mode);
    
  // Available functions
  void initializeWiFi();
  void init();
  void addPeer(const uint8_t *address);    
  void sendString(const String &text, const uint8_t *destAddress);
  String getLast();
  
  // Static callback methods
  static void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
  static void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len);

private:
  static void printMAC(const uint8_t *macAddr);
  String _mode;
  static String lastReceived;
};
#endif
