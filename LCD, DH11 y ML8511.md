// BIBLIOTECAS NECESARIAS
#include <Wire.h> 		
#include <LiquidCrystal_I2C.h> 
#include <DHT.h> 		

// PINES
#define DHTPIN 7
#define DHTTYPE DHT11   
#define UVPIN A0        // Pin de salida analógica del ML8511
#define BUZZER 6        // Pin digital para el buzzer

DHT dht(DHTPIN, DHTTYPE);	
LiquidCrystal_I2C lcd(0x27, 16, 2); 

//PROGRAMA
void setup() {
  lcd.init();       // iniciar pantalla
  lcd.backlight();  // incender luz de fondo (necesario porque sino no se ve nada)
  dht.begin();      // iniciar sensor
  lcd.setCursor(0, 0); // deja el cursor del LCD al comienzo para poder escribir
  lcd.print("Iniciando"); //mensajito ;)
  lcd.setCursor(0, 1); // paso a la parte de abajo 
  lcd.print("centralita..."); //mensajito ;)
  delay(2000);
  lcd.clear(); //limpia el LCD (el mensajito)
}


void loop() {
  // Variables del DHT
  float h = dht.readHumidity(); // lee la humedad
  float t = dht.readTemperature(); //lee la temperatura

  // Leer valor del ML8511
  int lecturaUV = analogRead(UVPIN);
  float voltage = lecturaUV * (5.0 / 1023.0); // Convertir a voltaje
  float indiceUV = mapfloat(voltage, 0.99, 2.9, 0.0, 15.0); 
  // 0.99V ~ 0 UV   |   2.9V ~ 15 UV (rango típico del ML8511)

  // Corrección para evitar valores negativos
  if (indiceUV < 0) {
    indiceUV = 0;
  }

  // Verificar errores del DHT
  if (isnan(h) && isnan(t)) { 
    lcd.setCursor(0, 0); lcd.print("Error sensor DHT");
    lcd.setCursor(0, 1); lcd.print("                ");
    return;
  } 
  else if (isnan(h)) { 
    lcd.setCursor(0, 0); lcd.print("Error humedad  ");
    lcd.setCursor(0, 1); lcd.print("                ");
    return;
  } 
  else if (isnan(t)) { 
    lcd.setCursor(0, 0); lcd.print("Error temp     ");
    lcd.setCursor(0, 1); lcd.print("                ");
    return;
  }

  // Mostrar en el LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223); // Símbolo de grados "°" (el LCD no lo muestra bien sino)
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humedad: ");
  lcd.print(h);
  lcd.print("%");

  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Indice UV:");
  lcd.print(indiceUV, 1); // 1 decimal


  // ---- CONTROL DEL BUZZER ----
  if (indiceUV > 8) {
    lcd.setCursor(4,1);
    lcd.print("PELIGRO");
    for (int i=0; i<3; i++){
      beep(3000); // 1000 Hz 
    }  
  }

  delay(2000); // Actualiza cada segundo
}

// -------- FUNCIONES --------
// Beep para buzzer pasivo (con tono)
void beep(int frecuencia) {
  tone(BUZZER, frecuencia); // Arranca el tono
  delay(500);            // Lo mantiene
  noTone(BUZZER);           // Lo apaga
  delay(1000);               // Pausa entre beeps
}

// Función auxiliar para mapear float (igual que map() pero con decimales)
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
