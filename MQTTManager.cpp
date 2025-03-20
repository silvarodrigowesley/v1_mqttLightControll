#include "MQTTManager.h"
#include <Arduino.h>

#define RELAY_PIN 12
#define NUM_RELES 11  // Quantidade de relés


WiFiClient espClient;
PubSubClient client(espClient);  // 🔹 Torna 'client' global

// Array com os pinos que serão usados para os relés
//const int pinos_rele[NUM_RELES] = {2, 4, 5, 13, 14, 15, 18, 19, 21, 22, 23};
const int pinos_rele[NUM_RELES] = { 32, 33, 25, 26, 27, 14, 13, 15 };

void configurarMQTT(PubSubClient& client) {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  // Configura todos os pinos do array como OUTPUT e os inicia em LOW
  for (int i = 0; i < NUM_RELES; i++) {
    pinMode(pinos_rele[i], OUTPUT);
    delay(50);
    digitalWrite(pinos_rele[i], HIGH);
  }
  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(mqttCallback);
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {

  
  String mensagem = "";
 char msgCallbackRele[30];
  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }
  Serial.println("Mensagem chegou do tópico: " + String(topic));
  Serial.print("Mensagem recebida: ");
  Serial.println(mensagem);

  if (mensagem == "ON-1") {
    for (int i = 0; i < NUM_RELES; i++) {
      pinMode(pinos_rele[i], OUTPUT);
      digitalWrite(pinos_rele[i], LOW);
      sprintf(msgCallbackRele, "%s-%d", "RELES ON", i);
      client.publish(MQTT_TOPIC_CALLBACK_RELE,msgCallbackRele);
      delay(100);
    }
    Serial.println("Relé ligado!");
  } else if (mensagem == "OFF-1") {
    for (int i = 0; i < NUM_RELES; i++) {
      pinMode(pinos_rele[i], OUTPUT);
      digitalWrite(pinos_rele[i], HIGH);
      sprintf(msgCallbackRele, "%s-%d", "RELES OFF",i);
      delay(100);
      client.publish(MQTT_TOPIC_CALLBACK_RELE,msgCallbackRele);
    }
  } else if (mensagem == "ON-2") {
    for (int i = 0; i < NUM_RELES; i++) {
      pinMode(pinos_rele[1], OUTPUT);
      digitalWrite(pinos_rele[1], !HIGH);
      sprintf(msgCallbackRele, "%s", "RELE 2 ON");
      
      client.publish(MQTT_TOPIC_CALLBACK_RELE,msgCallbackRele);
    }
  } else if (mensagem == "OFF-2") {
    for (int i = 0; i < NUM_RELES; i++) {
      pinMode(pinos_rele[1], OUTPUT);
      digitalWrite(pinos_rele[1], !LOW);
      sprintf(msgCallbackRele, "%s", "RELE 2 OFF");
      client.publish(MQTT_TOPIC_CALLBACK_RELE,msgCallbackRele);
    }
  }
 
}


void reconectarMQTT(PubSubClient& client) {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("ESP32Cliente")) {
      Serial.println("Conectado!");
      client.subscribe(MQTT_TOPIC);
      client.subscribe(MQTT_TOPIC_WIFI);
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5s");
      delay(5000);
    }
  }
}


/*#include <HTTPUpdate.h>

t_httpUpdate_return ret = httpUpdate.update(client, "https://raw.githubusercontent.com/<username>/<reponame>/main/<arquivo>.bin");

if(ret == HTTP_UPDATE_OK) {
    Serial.println("Atualização concluída com sucesso!");
}*/
