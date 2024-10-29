# Esquema electrónico final
![esquema_final](https://github.com/leomachiavello/FundBio2024-2/blob/main/Im%C3%A1genes/esquema_final_entregable_6.png?raw=true)
# Ejecución del código Arduino

# Código Arduino
```
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
    tone(buzzerPin, 1000);
  } else {
    noTone(buzzerPin);
  }

  delay(1000);

}
```