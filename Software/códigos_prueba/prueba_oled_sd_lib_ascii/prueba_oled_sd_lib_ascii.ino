// Test for minimum program size.
// Edit AVRI2C_FASTMODE in SSD1306Ascii.h to change the default I2C frequency.

#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#include <SD.h>

const int chipSelect = 10;

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1

SSD1306AsciiAvrI2c oled;
//------------------------------------------------------------------------------
void setup() {

Serial.begin(9600);

#if RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
#endif // RST_PIN >= 0
  // Call oled.setI2cClock(frequency) to change from the default frequency.

  oled.setFont(Arial14);
  oled.clear();
  oled.println("Iniciando SD...");
  delay(1000);

  if (!SD.begin(chipSelect)) {
    oled.clear();
    oled.print("Error tarjeta SD.");
    while (1); // Detener si no se detecta la tarjeta
  }
  oled.clear();
  oled.print("Tarjeta SD OK.");
}
//------------------------------------------------------------------------------
void loop() {}