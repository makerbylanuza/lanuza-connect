#ifndef LANUZACONNECT_H
#define LANUZACONNECT_H

#include <esp_now.h>
#include <WiFi.h>

// Tipo de datos para el mensaje
typedef struct struct_message {
    char data[250];
} struct_message;

class LanuzaConnect {
public:
    LanuzaConnect(const String &mode);

    void initializeWiFi();
    void communicationStartup();
    void addPeer(const uint8_t *address);    
    void sendString(const String &text, const uint8_t *destAddress);
    String getLast();
    
    // Métodos estáticos para callbacks
    static void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
    static void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len);

private:
    static void printMAC(const uint8_t *macAddr);
    String _mode;
    static String lastReceived;
};

#endif