#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int pinSensor = A0;
const int pinBuzzer = A1;

float valorSensor = 0;
float voltaje = 0;
float voltajeMax = 3.0;

void setup() {

  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

}

void loop() {

  int valorSensor = analogRead(pinSensor);
  float voltaje = valorSensor * (5.0/1023.0);
  float voltajeAbs = fabs(voltaje);

  Serial.print("Valor del sensor de presión: ");
  Serial.print(valorSensor);
  Serial.print(" - Voltaje: ");
  Serial.println(voltajeAbs, 3);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("V"));
  display.print(voltajeAbs, 3);
  display.display();

  if(voltajeAbs>voltajeMax){
    tone(pinBuzzer, 1000, 200); 
  }

  delay(1000);

}
