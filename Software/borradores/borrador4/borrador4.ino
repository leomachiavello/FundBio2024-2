#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int pinSensor = A1;
const int pinBuzzer = A0;
const float limiteVoltaje = 0.8;
unsigned long tiempoInicio = 0;
unsigned long duracionReporte = 10000;
unsigned long tiempoTranscurrido = 0;
bool cronometroActivo = false;
bool mostrandoReporte = false;

float voltajeMaximo = 0;
float voltajeTotal = 0;
int contadorVoltajes = 0;

void mostrarReporte(float maxVoltaje, float promedioVoltaje) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.print(F("Reporte"));
  
  display.setTextSize(1);
  display.setCursor(10, 30);
  display.print(F("Max: "));
  display.print(maxVoltaje, 3);
  display.print(F(" V"));

  display.setCursor(10, 45);
  display.print(F("Prom: "));
  display.print(promedioVoltaje, 3);
  display.print(F(" V"));

  display.display();
}

void mostrarLungie() {
  display.clearDisplay();
  display.setTextSize(2.5);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(26, 18);
  display.print(F("LUNGIE"));
  display.display();
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
  pinMode(pinBuzzer, OUTPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
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
    display.clearDisplay();
    display.setTextSize(2.5);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(26, 0);
    display.print(F("LUNGIE"));
    display.setTextSize(1);
    display.setCursor(30, 40);  // Ajusta la posición del cronómetro
    display.print("Tiempo: ");
    display.print(tiempoTranscurrido);
    display.print(" s");
    display.display();
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