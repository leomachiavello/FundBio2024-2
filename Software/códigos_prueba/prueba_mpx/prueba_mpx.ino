const int pinSensor1 = A0;
const int pinSensor2 = A1;

float valorSensor1 = 0;
float valorSensor2 = 0;

void setup() {
  
  Serial.begin(9600);
 
}

void loop() {

  int valorSensor1 = analogRead(pinSensor1);
  int valorSensor2 = analogRead(pinSensor2);

  Serial.print("Diferencia de presión: ");
  Serial.println(fabs(valorSensor1-valorSensor2));

  float voltaje = fabs(valorSensor1-valorSensor2) * (5.0/1023.0);
  Serial.print("Voltaje: ");
  Serial.print(voltaje * 1000, 3);
  Serial.println(" mV");

  float presion = voltaje / 0.009;
  Serial.print("Presión: ");
  Serial.print(presion);
  Serial.println(" kPa");

  delay(1000);

}
