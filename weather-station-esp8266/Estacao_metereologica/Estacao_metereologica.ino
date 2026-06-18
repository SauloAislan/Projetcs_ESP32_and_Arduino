/**
 * @file Estacao_metereologica.ino
 * @author Saulo Aislan
 * @brief Estação meteorológica residencial com ESP8266, DHT11, BMP280,
 *        sensor de chuva e display OLED 128x64.
 * @version 0.1
 * @date 2022
 * @copyright Copyright (c) 2022
 *
 * Artigo: https://blog.eletrogate.com/estacao-meteorologica-residencial-com-esp8266/
 *
 * Componentes:
 *   - ESP8266 12F IOT USB
 *   - Display OLED 128x64 I2C (SDA=D4/GPIO2, SCL=D5/GPIO14)
 *   - Sensor DHT11 (pino D1/GPIO5)
 *   - Sensor BMP280 (I2C endereço 0x76)
 *   - Sensor de chuva (analógico A0, divisor com 2x 4k7Ω)
 *
 * Bibliotecas necessárias:
 *   - BMP280 (mahfuz195)
 *   - DHTesp (beegee-tokyo)
 *   - SSD1306 (ThingPulse/esp8266-oled-ssd1306)
 *
 * Inclua o arquivo images.h na mesma pasta com os bitmaps de sol e chuva.
 */

#include <Wire.h>
#include "BMP280.h"
#include "DHTesp.h"
#include "SSD1306.h"
#include "images.h"

#define SDA             2
#define SCL            14
#define RST            26
#define DISPLAY_ADDR 0x3c
#define BMP280_ADDR  0x76
#define P0         1013.25
#define PIN_SENSOR_CHUVA    A0
#define PIN_SENSOR_HUMIDADE  5
#define DELAYINLOOP       2000
#define TRANSITION_DUARTION 3000

BMP280 bmp;
DHTesp dht;
SSD1306 display(DISPLAY_ADDR, SDA, SCL, RST);

typedef void (*Demo)(void);

long timeSinceLastModeSwitch = 0;
int demoMode = 0;
double temperatura, alti, pressao;
float humidade;

void drawSun();
void drawCloud();
void getdados();
bool estaChovendo();
void printCloud();
void printTemp();
void printHumi();
void printPressao();
void printAltitude();

Demo demos[]   = {printCloud, printTemp, printPressao, printAltitude, printHumi};
int demoLength = (sizeof(demos) / sizeof(Demo));

void setup()
{
  Serial.begin(115200);
  pinMode(PIN_SENSOR_CHUVA, INPUT);
  dht.setup(PIN_SENSOR_HUMIDADE, DHTesp::DHT11);

  if (!bmp.begin(SDA, SCL)) {
    Serial.println("BMP280: falha na inicialização!");
    while (1);
  }
  bmp.setOversampling(4);

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.display();
}

void drawSun() {
  display.clear();
  display.drawXbm(41, 0, SUN_WIDTH, SUN_HEIGHT, sun_icon);
  display.display();
}

void drawCloud() {
  display.clear();
  display.drawXbm(41, 0, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_rain_icon);
  display.display();
}

void printCloud() {
  display.setFont(ArialMT_Plain_16);
  display.clear();
  if (estaChovendo()) {
    drawCloud();
    display.drawString(23, 48, "Chovendo...");
  } else {
    drawSun();
    display.drawString(23, 47, "Sem Chuva...");
  }
  display.display();
}

void printTemp() {
  display.setFont(ArialMT_Plain_16);
  display.clear();
  display.drawString(18, 0, "Temperatura");
  display.setFont(ArialMT_Plain_24);
  display.drawString(15, 20, " " + (String)temperatura + "  C");
  display.drawRect(89, 25, 5, 5);
  display.display();
}

void printHumi() {
  display.setFont(ArialMT_Plain_16);
  display.clear();
  display.drawString(25, 0, "Humidade");
  display.setFont(ArialMT_Plain_24);
  display.drawString(15, 20, " " + (String)humidade + " %");
  display.display();
}

void printPressao() {
  display.setFont(ArialMT_Plain_10);
  display.clear();
  display.drawString(18, 5, "Pressão");
  display.drawString(60, 5, "Atmosférica");
  display.setFont(ArialMT_Plain_24);
  display.drawString(5, 20, (String)pressao + " hPa");
  display.display();
}

void printAltitude() {
  display.setFont(ArialMT_Plain_16);
  display.clear();
  display.drawString(37, 0, "Altitude");
  display.setFont(ArialMT_Plain_24);
  display.drawString(15, 20, (String)alti + " m");
  display.display();
}

void getdados()
{
  char result = bmp.startMeasurment();
  double tempBMP;

  Serial.print("\n\n---------- Dados ----------\n");

  if (result != 0) {
    delay(result);
    result = bmp.getTemperatureAndPressure(tempBMP, pressao);
    if (result != 0) {
      alti = bmp.altitude(pressao, P0);
    } else {
      Serial.println("BMP280: erro na leitura.");
    }
  } else {
    Serial.println("BMP280: erro ao iniciar medição.");
  }

  humidade = dht.getHumidity();
  float tempDHT = dht.getTemperature();

  if (isnan(tempDHT)) {
    temperatura = tempBMP;
  } else {
    temperatura = (tempBMP + tempDHT) / 2;
  }

  Serial.print("Temperatura: "); Serial.print(temperatura); Serial.println(" °C");
  Serial.print("Humidade: ");    Serial.print(humidade);    Serial.println(" %");
  Serial.print("Pressão: ");     Serial.print(pressao, 2);  Serial.println(" hPa");
  Serial.print("Altitude: ");    Serial.print(alti, 2);     Serial.println(" m");
  Serial.print("Chuva (ADC): "); Serial.println(analogRead(PIN_SENSOR_CHUVA));
}

bool estaChovendo() {
  return analogRead(PIN_SENSOR_CHUVA) <= 900;
}

void loop()
{
  getdados();
  display.clear();
  demos[demoMode]();
  display.display();

  if (millis() - timeSinceLastModeSwitch > TRANSITION_DUARTION) {
    demoMode = (demoMode + 1) % demoLength;
    timeSinceLastModeSwitch = millis();
  }
  delay(DELAYINLOOP);
}
