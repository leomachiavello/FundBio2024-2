#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#include <SD.h>
#include <math.h>

#define I2C_ADDRESS 0x3C
#define RST_PIN -1

File dataFile;
SSD1306AsciiAvrI2c oled;

const int pinSD = 10;
const int pinSensor = A0;
const int pinBuzzer = 5;
const float sensibilidadSensor = 0.005;
const int factorCalib = 1;
const float limiteVoltaje = 0.1;
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

String nombreArchivo;

float voltajeReferencia = 0.0;

String obtenerNombreArchivo() {
  int numeroArchivo = 1;
  String nombreArchivo = "datos_" + String(numeroArchivo) + ".csv";

  // Recorremos los archivos existentes en la tarjeta SD para encontrar el último número usado
  while (SD.exists(nombreArchivo.c_str())) {
    numeroArchivo++;  // Incrementamos el número del archivo
    nombreArchivo = "datos" + String(numeroArchivo) + ".csv";  // Generamos el nuevo nombre de archivo
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

  nombreArchivo = obtenerNombreArchivo();

  dataFile = SD.open(nombreArchivo.c_str(), FILE_WRITE);
  if (dataFile) {
    dataFile.println("Tiempo (s);Flujo(L/s);Volumen(L)");  // Cabecera
    dataFile.close();
    oled.clear();
    oled.print("Tabla de datos creada.");
    delay(1000);
  } else {
    oled.clear();
    oled.print("Error creando archivo.");
    while (1); // Detener si no se puede crear el archivo
  }

  float sumaVoltajes = 0.0;
  for (int i = 0; i < 5; i++) {
    float lectura = analogRead(pinSensor) * (5.0 / 1023.0); // Convertir a voltaje
    sumaVoltajes += lectura;
    delay(100); // Pequeño retraso entre lecturas
  }
  voltajeReferencia = sumaVoltajes / 5.0; // Promedio de las 5 lecturas
  Serial.print("Voltaje de referencia establecido: ");
  Serial.println(voltajeReferencia, 3);

  oled.clear();
  oled.print("Voltaje ref: ");
  oled.print(voltajeReferencia, 3);
  delay(2000);

  mostrarLungie();
  delay(5000);
}

void loop() {
  float voltajeProm = analogRead(A0) * (5.0 / 1023.0);
  voltajeProm -= voltajeReferencia;
  float presionProm = voltajeProm / (5 * sensibilidadSensor);
  float flujoProm = factorCalib * sqrt(presionProm); // Flujo en L/s

  Serial.print("Flujo: ");
  Serial.println(flujoProm, 3);
  Serial.print("Voltaje: ");
  Serial.println(voltajeProm, 3);

  if (voltajeProm > limiteVoltaje) {
    if (!cronometroActivo) {
      cronometroActivo = true;
      tiempoInicio = millis();
      flujoMaximo = 0;
      volumenFEV1 = 0;
      volumenTotal = 0;
      tone(pinBuzzer, 262, 500);
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

    dataFile = SD.open(nombreArchivo.c_str(), FILE_WRITE);
    if (dataFile) {
      dataFile.print(tiempoTranscurrido / 1000.0);
      dataFile.print(";");
      dataFile.print(flujoProm, 3);
      dataFile.print(";");
      dataFile.println(volumenTotal, 3);
      dataFile.close();
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
      tone(pinBuzzer, 262, 500);
    }
  }

  if (mostrandoReporte && millis() - tiempoInicio >= duracionReporte) {
    mostrandoReporte = false;
    mostrarLungie();
  }

  delay(10);
}