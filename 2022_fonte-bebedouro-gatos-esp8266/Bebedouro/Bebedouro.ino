/**
 * @file Bebedouro.ino
 * @author Saulo Aislan
 * @brief Firmware para controle da bomba d'água de um bebedouro para gatos.
 *        Interface web com modos: contínuo, por tempo, manual e híbrido.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/fonte-bebedouro-para-gatos-com-esp8266/
 *
 * Componentes:
 *   - Wemos D1 Mini Pro (ESP8266)
 *   - Mini bomba submersível 5V
 *   - Módulo relé 5V 1 canal
 *   - Transistor NPN 2N2222
 *   - Resistores 1kΩ e 47kΩ
 *
 * Bibliotecas necessárias (Library Manager):
 *   - ESPAsyncTCP
 *   - ESPAsyncWebServer
 *
 * Rede WiFi criada pelo dispositivo:
 *   SSID: Bebedouro | Senha: 123456789
 *   Acesse: http://192.168.4.1
 */

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#define PIN_MOTOR 4  // Wemos D2 = GPIO4

const char* ssid     = "Bebedouro";
const char* password = "123456789";

AsyncWebServer server(80);

bool buttonStatus   = false;
bool motorStatus    = false;
uint8_t paramMotorStatus = 0;
uint8_t controlMode      = 0;
uint16_t interval        = 60;  // minutos

void withOutControl(void) {
  digitalWrite(PIN_MOTOR, HIGH);
  buttonStatus = false;
}

void controlManual(void) {
  Serial.println("Controle Manual");
  buttonStatus = true;
}

void timeControl(int i_interval) {
  i_interval = i_interval * 60 * 1000;
  digitalWrite(PIN_MOTOR, LOW);
  delay(i_interval);
  digitalWrite(PIN_MOTOR, HIGH);
  delay(15000);  // opera por 15 segundos
}

void manualControl(AsyncWebServerRequest* request) {
  bool st;
  if (request->hasParam("st"))
    st = request->getParam("st")->value().toInt();
  else
    st = 0;

  if (st) {
    digitalWrite(PIN_MOTOR, HIGH);
    Serial.println("Motor: LIGADO");
  } else {
    digitalWrite(PIN_MOTOR, LOW);
    Serial.println("Motor: DESLIGADO");
  }
  request->send(200, "text/html", SendHTML());
}

String SendHTML() {
  String ptr = "<!DOCTYPE html><html>";
  ptr.concat(F("<head><meta http-equiv='Content-Type' content='text/html; charset=utf-8'>"));
  ptr.concat(F("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">"));
  ptr.concat(F("<title>Bebedouro para Gato</title>"));
  ptr.concat(F("<style>html{font-family:Arial,Helvetica,sans-serif;display:inline-block;margin:0 auto;text-align:center;}"));
  ptr.concat(F("body{margin:0;font-size:1rem;color:#1e4659;background:#f2f2f2;}"));
  ptr.concat(F(".topnav{background:#04448c;padding:10px;color:white;}"));
  ptr.concat(F(".button{display:block;width:80px;background:#3498db;border:none;color:white;padding:13px 30px;font-size:25px;margin:0 auto 35px;cursor:pointer;border-radius:4px;}"));
  ptr.concat(F(".button-on{background:#4caf50;}.button-off{background:#f44336;}"));
  ptr.concat(F("select,input{width:100%;padding:10px;margin:8px 0;border:1px solid #ccc;border-radius:4px;}"));
  ptr.concat(F("</style></head>"));
  ptr.concat(F("<body><div class=\"topnav\"><h1>Bebedouro para Gato</h1></div>"));
  ptr.concat(F("<div><form name=\"formMode\">"));
  ptr.concat(F("<select onchange=\"setmode()\" name=\"opMode\" id=\"mode\">"));
  ptr.concat(F("<option value=\"-\">Selecione o modo</option>"));
  ptr.concat(F("<option value=\"/mode?op=1\">Contínuo</option>"));
  ptr.concat(F("<option value=\"/mode?op=2\">Por Tempo</option>"));
  ptr.concat(F("<option value=\"/mode?op=3\">Manual</option>"));
  ptr.concat(F("<option value=\"/mode?op=4\">Tempo e Manual</option>"));
  ptr.concat(F("</select></form></div>"));

  if (buttonStatus) {
    if (digitalRead(PIN_MOTOR) == LOW) {
      ptr.concat(F("<a class='button button-on' href=\"/bomba?st=1\">Ligar</a>"));
    } else {
      ptr.concat(F("<a class='button button-off' href='/bomba?st=0'>Desligar</a>"));
    }
  } else {
    ptr.concat(F("<a class='button' style='background:#c3c3c3;'> - </a>"));
  }

  ptr.concat(F("<script>function setmode(){location=document.formMode.opMode.options[document.formMode.selectedIndex].value}</script>"));
  ptr.concat(F("</body></html>"));
  return ptr;
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_MOTOR, OUTPUT);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send(200, "text/html", SendHTML());
  });

  server.on("/mode", HTTP_GET, [](AsyncWebServerRequest* request) {
    if (request->hasParam("op"))
      paramMotorStatus = request->getParam("op")->value().toInt();
    else
      paramMotorStatus = 0;
    controlMode = paramMotorStatus;
    Serial.print("Modo: ");
    Serial.println(paramMotorStatus);
    request->send(200, "text/html", SendHTML());
  });

  server.on("/bomba", HTTP_GET, manualControl);
  server.begin();
}

void loop() {
  switch (controlMode) {
    case 1: withOutControl();       break;
    case 2: timeControl(interval);  break;
    case 3: controlManual();        break;
    case 4:
      controlManual();
      timeControl(interval);
      break;
    default: timeControl(30);  // 30 minutos por padrão
  }
}
