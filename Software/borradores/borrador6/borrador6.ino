#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#include <SD.h>
#include <math.h>

#define I2C_ADDRESS 0x3C
#define RST_PIN -1

File flujoTiempoFile;
File flujoVolumenFile;
SSD1306AsciiAvrI2c oled;

const int pinSD = 10;
const int pinSensor = A1;
const int pinBuzzer = A0;
const int sensibilidadSensor = 5;
const int factorCalib = 1;
const float limiteVoltaje = 2.5;
unsigned long tiempoInicio = 0;
unsigned long duracionReporte = 10000;
unsigned long tiempoTranscurrido = 0;
bool cronometroActivo = false;
bool mostrandoReporte = false;

// Variables para PEF, FEV1, FVC
float flujoMaximo = 0; // PEF
float volumenFEV1 = 0; // FEV1
float volumenTotal = 0; // FVC

unsigned long ultimoTiempoOLED = 0; 
const unsigned long intervaloOLED = 1000; 

String obtenerNombreArchivo(String baseNombre) {
  int numeroArchivo = 1;
  String nombreArchivo = baseNombre + String(numeroArchivo) + ".csv";

  while (SD.exists(nombreArchivo.c_str())) {
    numeroArchivo++;
    nombreArchivo = baseNombre + String(numeroArchivo) + ".csv";
  }

  return nombreArchivo;
}

void mostrarReporte(float PEF, float FEV1, float FVC) {
  oled.setFont(Arial14);
  oled.clear();
  oled.println("Reporte:");

  oled.print("PEF: ");
  oled.print(PEF, 3);
  oled.println(" L/s");

  oled.print("FEV1: ");
  oled.print(FEV1, 3);
  oled.println(" L");

  oled.print("FVC: ");
  oled.print(FVC, 3);
  oled.println(" L");
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
  #else
    oled.begin(&Adafruit128x64, I2C_ADDRESS);
  #endif

  oled.clear();
  oled.setFont(Arial14);
  oled.print("Iniciando SD...");
  delay(1000);

  if (!SD.begin(pinSD)) {
    oled.clear();
    oled.print("Error tarjeta SD.");
    while (1);
  }
  oled.clear();
  oled.print("Tarjeta SD OK.");
  delay(1000);

  String nombreFlujoTiempo = obtenerNombreArchivo("flujo_tiempo_");
  flujoTiempoFile = SD.open(nombreFlujoTiempo.c_str(), FILE_WRITE);
  if (flujoTiempoFile) {
    flujoTiempoFile.println("Tiempo (s);Flujo (L/s)");
    flujoTiempoFile.close();
    oled.clear();
    oled.print("Archivo tiempo OK.");
    delay(1000);
  } else {
    oled.clear();
    oled.print("Error archivo tiempo.");
    while (1);
  }

  String nombreFlujoVolumen = obtenerNombreArchivo("flujo_volumen_");
  flujoVolumenFile = SD.open(nombreFlujoVolumen.c_str(), FILE_WRITE);
  if (flujoVolumenFile) {
    flujoVolumenFile.println("Volumen (L);Flujo (L/s)");
    flujoVolumenFile.close();
    oled.clear();
    oled.print("Archivo volumen OK.");
    delay(1000);
  } else {
    oled.clear();
    oled.print("Error archivo volumen.");
    while (1);
  }

  mostrarLungie();
}

void loop() {
  int promedio = getStableReading(A1);
  float voltajeProm = promedio * (5.0 / 1023.0);
  float presionProm = voltajeProm / (5 * sensibilidadSensor);
  float flujoProm = factorCalib * sqrt(presionProm); // Flujo en L/s

  Serial.print("Flujo: ");
  Serial.println(flujoProm, 3);

  if (voltajeProm > limiteVoltaje) {
    if (!cronometroActivo) {
      cronometroActivo = true;
      tiempoInicio = millis();
      flujoMaximo = 0;
      volumenFEV1 = 0;
      volumenTotal = 0;
    }

    if (flujoProm > flujoMaximo) {
      flujoMaximo = flujoProm; // Actualiza el PEF
    }

    // Calcula el tiempo transcurrido
    tiempoTranscurrido = (millis() - tiempoInicio);

    // Sumar flujo al volumen total (FVC)
    volumenTotal += flujoProm * (1.0 / 1000.0); // Asumiendo delay de 1 ms para conversión a segundos

    // Sumar flujo al volumen FEV1 si estamos en el primer segundo
    if (tiempoTranscurrido <= 1000) {
      volumenFEV1 += flujoProm * (1.0 / 1000.0);
    }

    flujoTiempoFile = SD.open(obtenerNombreArchivo("flujo_tiempo_").c_str(), FILE_WRITE);
    if (flujoTiempoFile) {
      flujoTiempoFile.print(tiempoTranscurrido / 1000.0);
      flujoTiempoFile.print(";");
      flujoTiempoFile.println(flujoProm, 3);
      flujoTiempoFile.close();
    }

      flujoVolumenFile = SD.open(obtenerNombreArchivo("flujo_volumen_").c_str(), FILE_WRITE);
    if (flujoVolumenFile) {
      flujoVolumenFile.print(volumenTotal, 3);
      flujoVolumenFile.print(";");
      flujoVolumenFile.println(flujoProm, 3);
      flujoVolumenFile.close();
    }

    if (millis() - ultimoTiempoOLED >= intervaloOLED) {
      ultimoTiempoOLED = millis();
      oled.clear();
      oled.setFont(Arial14);
      oled.print("Tiempo: ");
      oled.print(tiempoTranscurrido / 1000.0);
      oled.print(" s");
    }

  } else {
    if (cronometroActivo) {
      cronometroActivo = false;
      mostrandoReporte = true;
      mostrarReporte(flujoMaximo, volumenFEV1, volumenTotal);
      tiempoInicio = millis();
    }
  }

  if (mostrandoReporte && millis() - tiempoInicio >= duracionReporte) {
    mostrandoReporte = false;
    mostrarLungie();
  }

  delay(10);
}
