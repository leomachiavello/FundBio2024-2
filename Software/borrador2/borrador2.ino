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

float valorSensor = 0;
float voltaje = 0;
float voltajeMax = 3.0;

int getStableReading(int A1) {
  long sum = 0;                   // Variable para acumular la suma de las lecturas
  for (int i = 0; i < 10; i++) {   // Bucle para realizar 10 lecturas
    sum += analogRead(A1);        // Leer el pin y agregar el valor al total
    delay(10);                     // Esperar un momento entre lecturas (10 ms)
  }
  return sum / 10;                 // Calcular el promedio dividiendo por el número de lecturas
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

  int valorSensor = analogRead(pinSensor);
  float voltaje = valorSensor * (5.0/1023.0);
  float voltajeAbs = fabs(voltaje);
  int promedio = getStableReading(A1);
  float voltajeProm = promedio * (5.0/1023.0);

  Serial.print("Valor del sensor de presión: ");
  Serial.print(valorSensor);
  Serial.print(" - Voltaje: ");
  Serial.println(voltajeAbs, 3);
  Serial.print("Lectura promediada: ");
  Serial.println(promedio);
  Serial.print(" - Voltaje promedio: ");
  Serial.println(voltajeProm, 3);


  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(voltajeAbs, 3);
  display.print(F("V"));
  display.display();

  if(voltajeAbs>voltajeMax){
    tone(pinBuzzer, 1000, 200); 
  }

  delay(1000);

}
