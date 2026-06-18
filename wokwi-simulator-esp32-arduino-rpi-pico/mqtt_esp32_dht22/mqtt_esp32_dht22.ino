/**
 * @file mqtt_esp32_dht22.ino
 * @author Saulo Aislan
 * @brief ESP32 lê temperatura/umidade do DHT22 e publica via MQTT.
 *        Simulado no Wokwi com broker test.mosquitto.org.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/simulando-esp32-arduino-e-raspberry-pi-com-o-wokwi/
 *
 * Bibliotecas necessárias:
 *   - EspMQTTClient (Library Manager)
 *   - DHT sensor library for ESPx (Library Manager)
 *
 * Tópicos MQTT:
 *   Publish: topicowokwi/Temp | topicowokwi/Humidade
 *   Subscribe: topicowokwi/msgRecebida/#
 */

#include "EspMQTTClient.h"
#include "DHTesp.h"

EspMQTTClient client(
  "Wokwi-GUEST",        // SSID (rede virtual do Wokwi)
  "",                   // Senha (sem senha no Wokwi)
  "test.mosquitto.org", // Broker MQTT
  "mqtt-wokwi",         // Client ID
  1883                  // Porta
);

const int DHT_PIN = 15;
DHTesp dhtSensor;

void setup()
{
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  client.enableDebuggingMessages();
  client.enableHTTPWebUpdater();
  client.enableOTA();
  client.enableLastWillMessage("TestClient/lastwill", "Vou ficar offline");
}

void lerEnviarDados() {
  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  Serial.println("Temp: " + String(data.temperature, 2) + "°C");
  Serial.println("Humidade: " + String(data.humidity, 1) + "%");
  Serial.println("---");
  client.publish("topicowokwi/Temp",     String(data.temperature, 2) + "°C");
  client.publish("topicowokwi/Humidade", String(data.humidity, 1) + "%");
}

void onConnectionEstablished()
{
  client.subscribe("topicowokwi/msgRecebida/#", [](const String& topic, const String& payload) {
    Serial.println("Mensagem recebida no topic: " + topic + ", payload: " + payload);
  });
  lerEnviarDados();
}

void loop()
{
  client.loop();
}
