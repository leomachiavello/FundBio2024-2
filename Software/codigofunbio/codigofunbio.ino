const int pinSensor = A0;
const int pinBuzzer = A1;

float valorSensor = 0;
float voltaje = 0;
float voltajeMax = 3.0;

void setup() {

  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);

}

void loop() {

  int valorSensor = analogRead(pinSensor);
  float voltaje = valorSensor * (5.0/1023.0);
  
  Serial.print("Valor del sensor de presión: ");
  Serial.print(valorSensor);
  Serial.print(" - Voltaje: ");
  Serial.println(voltaje, 3);

  if (voltaje >= voltajeMax){
    tone(pinBuzzer, 1000);
  } else {
    noTone(pinBuzzer);
  }

  delay(1000);

}


