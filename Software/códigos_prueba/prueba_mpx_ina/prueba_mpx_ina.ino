const int pinSensor = A0;

float valorSensor = 0;
float voltaje = 0;
float voltajeMax = 3.0;

void setup() {

  Serial.begin(9600);

}

void loop() {

  int valorSensor = analogRead(pinSensor);
  float voltaje = valorSensor * (5.0/1023.0);
  float voltajeAbs = fabs(voltaje);
  
  Serial.print("Señal: ");
  Serial.println(valorSensor);
  Serial.print("Voltaje: ");
  Serial.println(voltajeAbs, 3);

  delay(1000);

}
