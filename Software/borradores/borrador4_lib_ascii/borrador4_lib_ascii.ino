#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#include <SD.h>

#define I2C_ADDRESS 0x3C
#define RST_PIN -1

SSD1306AsciiAvrI2c oled;

const int pinSD = 10;
const int pinSensor = A1;
const int pinBuzzer = A0;
const float limiteVoltaje = 2.5;
unsigned long tiempoInicio = 0;
unsigned long duracionReporte = 10000;
unsigned long tiempoTranscurrido = 0;
bool cronometroActivo = false;
bool mostrandoReporte = false;

float voltajeMaximo = 0;
float voltajeTotal = 0;
int contadorVoltajes = 0;

void mostrarReporte(float maxVoltaje, float promedioVoltaje) {

  oled.setFont(Arial14);
  oled.clear();
  oled.println("Reporte:");

  oled.print("Max: ");
  oled.print(maxVoltaje, 3);
  oled.println(" V");

  oled.print("Prom: ");
  oled.print(promedioVoltaje, 3);
  oled.print(" V");
}

void mostrarLungie() {

  oled.clear();
  oled.setFont(Arial_bold_14);
  oled.println(" ");
  oled.print("        LUNGIE");

}

int getStableReading(int A1) {
  long sum = 0;                   
  for (int i = 0; i < 10; i++) {  
    sum += analogRead(A1);        
    delay(10);                     
  }
  return sum / 10;                 
}

void setup() {

  Serial.begin(9600);
  #if RST_PIN >= 0
    oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
  #else // RST_PIN >= 0
    oled.begin(&Adafruit128x64, I2C_ADDRESS);
  #endif // RST_PIN >= 0

  oled.clear();
  oled.setFont(Arial14);
  oled.print("Iniciando SD...");
  delay(1000);

  if (!SD.begin(pinSD)) {
    oled.clear();
    oled.print("Error tarjeta SD.");
    while (1); // Detener si no se detecta la tarjeta
  }
  oled.clear();
  oled.print("Tarjeta SD OK.");
  delay(1000);

  mostrarLungie();
}

void loop() {
  
  int promedio = getStableReading(A1);
  float voltajeProm = promedio * (5.0/1023.0);

  Serial.print("Valor del sensor de presión: ");
  Serial.print(promedio);
  Serial.print(" - Voltaje: ");
  Serial.println(voltajeProm, 3);

  if (voltajeProm > limiteVoltaje) {
    if (!cronometroActivo) {
      // Inicia el cronómetro si aún no está activo
      cronometroActivo = true;
      tiempoInicio = millis(); // Guarda el tiempo actual como inicio
    }

    // Actualiza el voltaje máximo y total
    if (voltajeProm > voltajeMaximo) {
      voltajeMaximo = voltajeProm;
    }
    voltajeTotal += voltajeProm;
    contadorVoltajes++;

    // Calcula el tiempo transcurrido en segundos
    tiempoTranscurrido = (millis() - tiempoInicio) / 1000;

    // Actualiza la pantalla OLED con el cronómetro
    oled.clear();
    oled.setFont(Arial14);
    oled.print("Tiempo: ");
    oled.print(tiempoTranscurrido);
    oled.print(" s");
  } else {
    if (cronometroActivo) {
      // Detiene el cronómetro cuando el voltaje baja del límite
      cronometroActivo = false;
      tiempoTranscurrido = (millis() - tiempoInicio) / 1000;

      // Calcular el promedio de los voltajes
      float voltajePromedio = voltajeTotal / contadorVoltajes;

      // Mostrar el reporte durante 10 segundos
      mostrandoReporte = true;
      mostrarReporte(voltajeMaximo, voltajePromedio);
      tiempoInicio = millis();  // Reinicia el tiempo para el reporte
    }
  }

  // Limpiar la pantalla después de 10 segundos
  if (mostrandoReporte && millis() - tiempoInicio >= duracionReporte) {
    mostrandoReporte = false;
    mostrarLungie();  // Muestra de nuevo "LUNGIE" después del reporte
  }
  
  delay(1000);

}