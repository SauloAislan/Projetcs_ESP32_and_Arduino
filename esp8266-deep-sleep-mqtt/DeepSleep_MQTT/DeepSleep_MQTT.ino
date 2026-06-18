/**
 * @file DeepSleep_MQTT.ino
 * @author Saulo Aislan
 * @brief Deep Sleep com ESP8266: lê temperatura TMP36, publica via MQTT
 *        e dorme por 30 segundos antes de repetir o ciclo.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/economizando-energia-sleep-modes-no-esp8266/
 *
 * Componentes:
 *   - ESP8266 NodeMCU V3 (Lolin)
 *   - Sensor TMP36 (saída analógica → A0)
 *
 * Bibliotecas necessárias:
 *   - ESP8266WiFi (built-in no ESP8266 Arduino Core)
 *   - PubSubClient (Library Manager)
 *
 * IMPORTANTE: Conecte GPIO16 (D0) ao RST somente APÓS o upload.
 */

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* WIFI_SSID = "SEU_SSID";    // << Altere
const char* WIFI_PASS = "SUA_SENHA";   // << Altere
const char* mqttServer = "broker.mqtt-dashboard.com";
const int   mqttPort   = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void connectToWifi() {
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(WIFI_SSID);
  WiFi.persistent(false);
  WiFi.mode(WIFI_OFF);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  unsigned long wifiConnectStart = millis();
  while (WiFi.status() != WL_CONNECTED) {
    if (WiFi.status() == WL_CONNECT_FAILED) {
      Serial.println("Falha ao conectar no WiFi");
    }
    delay(500);
    Serial.print(".");
    if (millis() - wifiConnectStart > 5000) {
      Serial.println("\nTimeout – falha na conexão WiFi");
      return;
    }
  }
  Serial.println("\nWiFi conectado! IP: " + WiFi.localIP().toString());
}

void publishMsg(double tempC) {
  client.setServer(mqttServer, mqttPort);
  String msg = "{Temperatura:" + String(tempC) + "}";
  while (!client.connected()) {
    Serial.println("Conectando ao MQTT...");
    if (client.connect("EletrogateClient")) {
      Serial.println("MQTT conectado!");
      client.publish("topic/eletrogate", (char*)msg.c_str());
      delay(5000);
    } else {
      Serial.print("Falha MQTT, estado: ");
      Serial.println(client.state());
    }
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("-------------------------------------");
  Serial.println("Firmware Deep Sleep + MQTT");
  Serial.println("-------------------------------------");

  connectToWifi();

  int raw    = analogRead(A0);
  double tempC = (((raw / 1024.0) * 3.2) - 0.5) * 100.0;

  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.println(" °C");

  publishMsg(tempC);

  Serial.println("Entrando em Deep-Sleep por 30 segundos");
  ESP.deepSleep(30e6);
}

void loop() {}
