#include <SPI.h>
#include <SD.h>

const int chipSelect = 10; // Pin CS conectado al pin 10 del Arduino

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando SD...");

  // Inicializar la tarjeta SD
  if (!SD.begin(chipSelect)) {
    Serial.println("Error al inicializar la tarjeta SD.");
    while (1); // Detener si no se detecta la tarjeta
  }
  Serial.println("Tarjeta SD inicializada correctamente.");

  // Crear un nuevo archivo
  String nombreArchivo = "archivo1.txt"; // Cambia el nombre según sea necesario
  crearArchivo(nombreArchivo);
}

void loop() {
  // No hay acciones en el loop
}

void crearArchivo(String nombreArchivo) {
  // Abrir o crear el archivo
  File archivo = SD.open(nombreArchivo.c_str(), FILE_WRITE);

  if (archivo) {
    Serial.print("Creando archivo: ");
    Serial.println(nombreArchivo);
    archivo.println("Este es el contenido del archivo.");
    archivo.println("¡Archivo creado exitosamente!");
    archivo.close(); // Siempre cierra el archivo después de escribir
    Serial.println("Datos escritos y archivo cerrado.");
  } else {
    Serial.println("Error al crear o abrir el archivo.");
  }
}