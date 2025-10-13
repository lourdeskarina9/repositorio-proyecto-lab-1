🌤️ Estación de Monitoreo Ambiental — Arduino
📋 Descripción general

La Estación de Monitoreo Ambiental es un sistema diseñado para registrar y analizar distintas variables del entorno mediante sensores conectados a una placa Arduino UNO.
Su objetivo es obtener datos de temperatura, humedad y radiación ultravioleta (UV), almacenándolos en una tarjeta SD y mostrándolos en una pantalla LCD 16x2 para su visualización en tiempo real.

🧠 ¿Qué hace la estación?

🌡️ Mide temperatura y humedad del aire con el sensor DHT11.

☀️ Detecta la intensidad de radiación UV mediante el sensor ML8511.

🖥️ Muestra los valores en una pantalla LCD 16x2 mediante comunicación I2C.

💾 Registra las mediciones en una tarjeta SD, permitiendo su posterior análisis.

⏰ Incluye un módulo de reloj en tiempo real (RTC) para fechar cada registro de datos.

🖼️ Esquema de conexión sugerido

📎 (Insertar aquí el diagrama generado o subirlo como archivo esquema_conexion.png y referenciarlo con la siguiente línea)

![Esquema de conexión](esquema_conexion.png)

⚙️ Instalación de librerías necesarias

Antes de compilar y cargar el código, asegurate de instalar las siguientes librerías desde el Administrador de Librerías del Arduino IDE:

Librería	Función
DHT.h	Lectura de temperatura y humedad (sensor DHT11)
Adafruit_Sensor.h	Dependencia general para sensores Adafruit
LiquidCrystal_I2C.h	Manejo de la pantalla LCD con interfaz I2C
RTClib.h	Control del reloj en tiempo real (RTC)
SD.h o SDfat.h	Lectura y escritura de archivos en la tarjeta SD
SPI.h	Comunicación SPI (incluida por defecto en Arduino IDE)
