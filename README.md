# v1_mqttLightControll
# ESP32 MQTT Light Control

Este projeto utiliza um ESP32 para conectar-se a uma rede Wi-Fi e a um broker MQTT. O ESP32 recebe comandos MQTT para ligar e desligar um relé.

## 📌 Funcionalidades
- Conexão Wi-Fi utilizando WiFiMulti para conexão com redes prioritárias.
- Conexão com um broker MQTT.
- Controle de relé via mensagens MQTT (`ON-1` e `OFF-1`).
- Reconexão automática ao Wi-Fi e MQTT em caso de desconexão.

## 🛠️ Requisitos
- **Placa ESP32**
- **Arduino IDE** (ou outro ambiente de desenvolvimento compatível)
- **Bibliotecas Necessárias:**
  - `WiFi` (versão 3.1.1 ou superior)
  - `PubSubClient` (versão 2.8 ou superior)

## 🔌 Ligação do Relé
Os relés estão conectados a pinos do ESP32 definidos em um array, e configurados como `OUTPUT` no código.

## 📜 Como Usar
1. Clone ou baixe este repositório.
2. Abra o código na **Arduino IDE**.
3. Configure as credenciais Wi-Fi no arquivo `WiFiManager.h`.
4. Configure o **endereço do broker MQTT** no arquivo `MQTTManager.h`.
5. Compile e envie o código para o ESP32.
6. No broker MQTT, envie os comandos:
   - `ON-1` para ligar o relé
   - `OFF-1` para desligar o relé

## 📝 Estrutura do Código
O código está organizado em arquivos `.h` e `.cpp`:
- **`WiFiManager.h/.cpp`**: Gerencia a conexão Wi-Fi com WiFiMulti.
- **`MQTTManager.h/.cpp`**: Gerencia a conexão e comunicação MQTT.
- **`mqttLightControll.ino`**: Arquivo principal, que inicializa os componentes e executa o loop principal.

## 🌐 Broker MQTT Público
Caso não tenha um broker próprio, pode usar o Mosquitto test server:
```
Broker: test.mosquitto.org
Porta: 1883 (sem SSL) ou 8883 (com SSL)
```


