
#include "WiFiManager.h"
#include <Arduino.h>
WiFiMulti wifiMulti;  
// Configurações da rede WiFi
char ssid1[] = "ssid1";  
char ssid2[] = "ssid2"; 
char ssid3[] = "ssid3";
char pass1[] = "pass1"; 
char pass2[] = "pass2";
char pass3[] = "pass3";
void conectarWiFi() {
    Serial.println("Adicionando redes Wi-Fi...");
    wifiMulti.addAP(ssid1, pass1);
    wifiMulti.addAP(ssid2, pass2);  // Adicione mais redes conforme necessário
    wifiMulti.addAP(ssid3, pass2);

    Serial.print("Conectando ao Wi-Fi...");
    while (wifiMulti.run() != WL_CONNECTED) {
        Serial.println(".");
        delay(1000);
    }

    Serial.println("\nWiFi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}

void reconectarWiFi() {
    if (wifiMulti.run() != WL_CONNECTED) {
        Serial.println("Wi-Fi desconectado! Tentando reconectar...");
        WiFi.disconnect();
        wifiMulti.run();
        int tentativas = 0;
        while (WiFi.status() != WL_CONNECTED && tentativas < 10) {  // Tenta por 10 segundos
            delay(1000);
            Serial.print(".");
            tentativas++;
        }
        if (WiFi.status() == WL_CONNECTED) {
            Serial.println("\nWiFi reconectado!");
            Serial.print("IP: ");
            Serial.println(WiFi.localIP());
        } else {
            Serial.println("\nFalha ao reconectar o Wi-Fi!");
        }
    }
}
