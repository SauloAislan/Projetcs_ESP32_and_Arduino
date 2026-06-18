/**
 * @file esp32Cam.ino
 * @author Saulo Aislan
 * @brief Firmware para criar um servidor de vídeo stream com ESP32-CAM.
 *        Acesso remoto via ngrok.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/esp32-cam-acessado-remotamente-com-ngrok/
 * Baseado em: https://github.com/Picaio/espcam
 *
 * Estrutura de arquivos:
 *   esp32Cam/
 *   ├── esp32Cam.ino
 *   ├── camera_pins.h
 *   └── src/
 *       ├── OV2640.cpp
 *       └── OV2640.h
 *
 * Componentes:
 *   - ESP32-CAM (AI Thinker) com câmera OV2640
 *   - Conversor FTDI FT232RL (para programação)
 *
 * Configuração no Arduino IDE:
 *   - Tools > Board: AI Thinker ESP32-CAM
 *   - Tools > PSRAM: Enabled
 *
 * Acesso ngrok:
 *   ngrok http --basic-auth="user:senha" IP_LOCAL:8880
 */

#include <WiFi.h>
#include <WebServer.h>
#include <WiFiClient.h>
#include "src/OV2640.h"

#define CAMERA_MODEL_AI_THINKER
#include "camera_pins.h"

#define SSID1 "SEU_SSID"     // << Altere
#define PWD1  "SUA_SENHA"    // << Altere

OV2640 cam;
WebServer server(8880);

const char HTTP_header[]      = "HTTP/1.1 200 OK\r\n"
                                 "Access-Control-Allow-Origin: *\r\n"
                                 "Content-Type: multipart/x-mixed-replace; boundary=123456789000000000000987654321\r\n";
const char HTTP_boundary[]    = "\r\n--123456789000000000000987654321\r\n";
const char HTTP_contentType[] = "Content-Type: image/jpeg\r\nContent-Length: ";
const int  headerLen          = strlen(HTTP_header);
const int  boundaryLen        = strlen(HTTP_boundary);
const int  cntLen             = strlen(HTTP_contentType);

void handleStream(void)
{
  char buf[32];
  int dataSize;
  WiFiClient client = server.client();

  client.write(HTTP_header, headerLen);
  client.write(HTTP_boundary, boundaryLen);

  while (true) {
    if (!client.connected()) break;
    cam.run();
    dataSize = cam.getSize();
    client.write(HTTP_contentType, cntLen);
    sprintf(buf, "%d\r\n\r\n", dataSize);
    client.write(buf, strlen(buf));
    client.write((char*)cam.getfb(), dataSize);
    client.write(HTTP_boundary, boundaryLen);
  }
}

void handlePageNotFound()
{
  String message = "Server em execucao!\n\n";
  message += "URI: " + server.uri() + "\n";
  message += "Metodo: " + String((server.method() == HTTP_GET) ? "GET" : "POST") + "\n";
  server.send(200, "text/plain", message);
}

void setup()
{
  Serial.begin(115200);

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer   = LEDC_TIMER_0;
  config.pin_d0       = Y2_GPIO_NUM;
  config.pin_d1       = Y3_GPIO_NUM;
  config.pin_d2       = Y4_GPIO_NUM;
  config.pin_d3       = Y5_GPIO_NUM;
  config.pin_d4       = Y6_GPIO_NUM;
  config.pin_d5       = Y7_GPIO_NUM;
  config.pin_d6       = Y8_GPIO_NUM;
  config.pin_d7       = Y9_GPIO_NUM;
  config.pin_xclk     = XCLK_GPIO_NUM;
  config.pin_pclk     = PCLK_GPIO_NUM;
  config.pin_vsync    = VSYNC_GPIO_NUM;
  config.pin_href     = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn     = PWDN_GPIO_NUM;
  config.pin_reset    = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  if (psramFound()) {
    config.frame_size   = FRAMESIZE_VGA;
    config.jpeg_quality = 9;
    config.fb_count     = 2;
  } else {
    config.frame_size   = FRAMESIZE_CIF;
    config.jpeg_quality = 12;
    config.fb_count     = 1;
  }

  cam.init(config);

  sensor_t* sensor = esp_camera_sensor_get();
  sensor->set_hmirror(sensor, 1);
  sensor->set_vflip(sensor, 1);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID1, PWD1);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
  Serial.print("Stream: http://");
  Serial.print(WiFi.localIP());
  Serial.println(":8880/");

  server.on("/", HTTP_GET, handleStream);
  server.onNotFound(handlePageNotFound);
  server.begin();
}

void loop()
{
  server.handleClient();
}
