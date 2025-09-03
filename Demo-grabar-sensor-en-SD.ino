
 // esto no funciona, agregenle los sensores correctos

#include <SD.h>

File dataFile;
const int chipSelect = 7;   // Pin CS de tu módulo SD
const int sensorPin = A0;   // Sensor en pin analógico A0

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando SD...");

  if (!SD.begin(chipSelect)) {
    Serial.println("❌ No se pudo inicializar la SD");
    return;
  }
  Serial.println("✅ SD inicializada correctamente");

  // Borramos archivo viejo (opcional, así no duplica datos)
   // SD.remove("sensores.txt");
}

void loop() {
  int valorSensor = analogRead(sensorPin);  // Leer sensor (0-1023)

  // Mostrar en Monitor Serie
  Serial.print("Lectura del sensor: ");
  Serial.println(valorSensor);

  // Guardar en la SD
  dataFile = SD.open("sensores.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(valorSensor);  // Escribimos el valor
    dataFile.close();
    Serial.println("✅ Guardado en SD");
  } else {
    Serial.println("❌ Error al abrir sensores.txt");
  }

  delay(1000); // Esperar 1 segundo antes de la próxima lectura
}

