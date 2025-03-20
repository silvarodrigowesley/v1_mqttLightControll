#include <Arduino.h>
#include "MQTTManager.h"
#include "WiFiManager.h"


//WiFiClient espClient;
//PubSubClient client(espClient);

void setup() {
    Serial.begin(115200);
    
    conectarWiFi();
    configurarMQTT(client);
}

void loop() {
    reconectarWiFi();
    if (!client.connected()) {
        reconectarMQTT(client);
    }
    client.loop();
}
