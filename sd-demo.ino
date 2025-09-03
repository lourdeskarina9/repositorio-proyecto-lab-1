#include <SD.h>

File myFile;
const int chipSelect = 7;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando SD ...");

  if (!SD.begin(chipSelect)) {
    Serial.println("❌ No se pudo inicializar la SD");
    return;
  }
  Serial.println("✅ SD inicializada correctamente");

  // Borramos archivo antes de escribir para que no duplique
  SD.remove("prueba.txt");

  myFile = SD.open("prueba.txt", FILE_WRITE);
  if (myFile) {
    Serial.println("✅ Escribiendo en prueba.txt...");
    myFile.println("Hola, esto es una prueba desde Arduino.");
    myFile.println("Linea 2 guardada en la SD.");
    myFile.close();
    Serial.println("✅ Escritura finalizada");
  } else {
    Serial.println("❌ Error al abrir prueba.txt para escribir");
  }
}

void loop() {}
