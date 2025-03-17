#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h> // Necesaria para esp_wifi_get_mac
#include "LanuzaConnect.h"

// Constructor
LanuzaConnect::LanuzaConnect(const String &mode) : _mode(mode) {}

// Inicialización estática
String LanuzaConnect::lastReceived = "";

// Imprimir dirección MAC
void LanuzaConnect::printMAC(const uint8_t *macAddr) {
    for (int i = 0; i < 6; i++) {
        if (i != 0) Serial.print(":");
        Serial.printf("%02X", macAddr[i]);
    }
    Serial.println();
}

// Inicializar WiFi y obtener la dirección MAC
void LanuzaConnect::initializeWiFi() {
    WiFi.mode(WIFI_STA);
    delay(100); // Espera para inicializar
    uint8_t mac[6];
    if (esp_wifi_get_mac(WIFI_IF_STA, mac) == ESP_OK) {
        Serial.print("MAC Address: ");
        printMAC(mac);
    } else {
        Serial.println("Error obtaining MAC address");
        while (true);
    }
}

// Callback al enviar datos
void LanuzaConnect::OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("Text sent; ");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

// Callback al recibir datos
void LanuzaConnect::OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len) {
    struct_message myData;
    memcpy(&myData, incomingData, sizeof(myData));
    String received = String((char *)incomingData);
    lastReceived = received;    

    Serial.print("Received data: ");
    Serial.println(received);
    Serial.print("Length: ");
    Serial.println(received.length());
    Serial.println();
}

// Configurar comunicación
void LanuzaConnect::communicationStartup() {

    	initializeWiFi();

    if (_mode != "MAC") {

    	Serial.println("WiFi initialized");

    	if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    	}
    	Serial.println("ESP-NOW initialized");

    	if (_mode == "TRANSMITTER" || _mode == "TRANSCEIVER") {
        esp_now_register_send_cb(OnDataSent);
        Serial.println("Mode: Transmitter");
    	}
    	if (_mode == "RECEIVER" || _mode == "TRANSCEIVER") {
        esp_now_register_recv_cb(OnDataRecv);
        Serial.println("Mode: Receiver");
    	}
    }
}

// Añadir receptor
void LanuzaConnect::addPeer(const uint8_t *address) {
    esp_now_peer_info_t peerInfo;
    memset(&peerInfo, 0, sizeof(peerInfo));
    memcpy(peerInfo.peer_addr, address, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Error adding peer");
        return;
    }
    Serial.print("Peer added: ");
    printMAC(address);
}

// Enviar texto
void LanuzaConnect::sendString(const String &text, const uint8_t *destAddress) {
    struct_message myData;
    strncpy(myData.data, text.c_str(), sizeof(myData.data) - 1);
    myData.data[sizeof(myData.data) - 1] = '\0';

    esp_err_t result = esp_now_send(destAddress, (uint8_t *) &myData, sizeof(myData));

    if (result == ESP_OK) {
        Serial.print("Sent successfully data: ");
        Serial.println(text);
    } else {
        Serial.println("Error sending data");
    }
}

// Devolver el último dato recibido
String LanuzaConnect::getLast() {
    return lastReceived;
}
