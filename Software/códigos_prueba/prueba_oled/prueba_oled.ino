#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128         // Ancho de la pantalla
#define SCREEN_HEIGHT 64         // Alto de la pantalla
#define OLED_RESET    -1         // No se necesita pin de reset
#define SCREEN_ADDRESS 0x3C    // Dirección típica SSD1306

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(2.5);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("Prueba"));
  display.display();
}

void loop() {
  // No se necesita nada en el loop para este ejemplo.
}