#ifndef MQTT_MANAGER_H
#define MQTT_MANAGER_H
#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <WiFiMulti.h>
extern WiFiClient espClient;  //  Declaração sem inicialização
extern PubSubClient client;   //  Declaração sem inicialização

#define MQTT_SERVER "test.mosquitto.org"
#define MQTT_PORT 1883
#define MQTT_TOPIC "Seu topic"
#define MQTT_TOPIC_WIFI "Seu topic WiFi"
#define MQTT_TOPIC_CALLBACK_RELE "Seu topic mqttCallback subscriber"

void configurarMQTT(PubSubClient& client);
void mqttCallback(char* topic, byte* payload, unsigned int length);
void reconectarMQTT(PubSubClient& client);


#endif
