# Hardware 
![image](https://github.com/user-attachments/assets/9de2a79b-1d61-4d1f-a3f4-c5d2d0efa6d2)


# Esquema Electrónico
![Esquema Final](https://github.com/user-attachments/assets/bcffc749-1599-42ce-967e-c1c1894fa787)

# Ejecución del código Arduino 

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
# Diagrama de flujo (Arduino)
![Diagrama de flujo datos](https://github.com/user-attachments/assets/03669abb-cc05-4dae-80cd-62f969e2b264)

# Reporte de pruebas
![tabla](https://github.com/leomachiavello/FundBio2024-2/blob/main/Im%C3%A1genes/tabla_de_funciones.png?raw=true)

# Impresión 3D
![Base y tapa](https://github.com/user-attachments/assets/fa982ae2-4024-4257-9742-05e49f6b3ee7)
