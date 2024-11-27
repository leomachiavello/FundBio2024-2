# Esquema electrónico final
![esquema_final](https://github.com/leomachiavello/FundBio2024-2/blob/main/Im%C3%A1genes/esquema_final_entregable_6.png?raw=true)
# Ejecución del código Arduino
A partir del código mostrado en el siguiente inciso, hicimos una prueba usando los componentes básicos (sensor de presión, buzzer y amplificador). A partir de esto pudimos imprimir los datos de voltaje en el monitor serial del Arduino IDE, lo que nos permitió observar el cambio de señales de acuerdo a la presión ejercida.

![prot_arduino](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/prototipo_electr%C3%B3nico_final.jpeg?raw=true)
![datos_arduino](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/arduino_datos.png?raw=true)
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
# Modelo 3D
## Vista explosionada
![vista_exp](https://github.com/leomachiavello/FundBio2024-2/blob/main/Hardware/vista_exp.jpg?raw=true)
## Renderizados
![image](https://github.com/user-attachments/assets/25c6c06d-54be-4c62-a089-2695a0ff0e17)
![image](https://github.com/user-attachments/assets/7854dbc8-a803-49bf-b712-d4e266df2a06)
![image](https://github.com/user-attachments/assets/ccaad79c-acd3-42af-a650-2df78da70c42)

# Diagrama de  flujo de datos (Arduino)
![DFD](https://github.com/leomachiavello/FundBio2024-2/blob/main/Software/DFD_Arduino.png?raw=true)
# Reporte de pruebas
Funciones de los componentes:
-	Arduino Uno: se usa para procesar los datos recibidos por el sensor de presión diferencial y transformarlo en las variables que necesitamos.
-	Sensor de presión: mide la presión que ejerce el flujo de aire que es espirado por el paciente.
-	Buzzer: funciona como un indicador de que el procedimiento ha sido correcto o no.
-	Pantalla OLED: muestra información básica de los resultados del procedimiento.

Al evaluar la funcionalidad de los componentes que usaremos en el dispositivo, hemos verificado que la mayor parte de estos cumplen adecuadamente con su propósito, sin embargo, hemos identificado los siguientes aspectos en los que podemos mejorar:
-	Sensor de presión: es la pieza con más valor del prototipo, Además se tuvieron ciertas dificultades para poder implementarlo en el sistema, por lo que es necesario usarlo con cuidado para evitar dañar el componente y producir errores en la lectura.
-	Lector de tarjeta SD: es un componente difícil de conseguir en el país, por lo que se están evaluando otras posibilidades.
-	Regulador de voltaje (step down): Si bien fue considerado inicialmente como un componente importante, el lector de tarjeta SD tiene ya un regulador integrado, por lo que su uso termina siendo innecesario, lo que lleva a que este componente sea descartado del modelo final. 
