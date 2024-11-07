#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("Escaneando dispositivos I2C...");

  for (byte i = 8; i < 120; i++) {
    Wire.beginTransmission(i);
    byte error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("Dispositivo I2C encontrado en la dirección: ");
      Serial.print("0x");
      Serial.println(i, HEX);
    }
  }
}

void loop() {
  // El escaneo solo se hace en el setup
}