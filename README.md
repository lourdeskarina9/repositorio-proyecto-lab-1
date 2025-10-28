****🌤️ Estación de Monitoreo Ambiental — Arduino Uno****

📋 Descripción general
-  La Estación de Monitoreo Ambiental es un sistema diseñado para registrar y analizar distintas variables del entorno mediante sensores conectados a una placa Arduino Uno.
Su objetivo es obtener datos de temperatura, humedad y radiación ultravioleta (UV), almacenándolos en una tarjeta SD (cada minuto) y mostrándolos en una pantalla LCD 16x2 en tiempo real.

🧠 ¿Qué hace la estación?
-  Mide temperatura y humedad del aire con el sensor DHT11.
-  Detecta la intensidad de radiación UV mediante el sensor ML8511.
-  Muestra los valores en una pantalla LCD 16x2 mediante comunicación I2C.
-  Registra las mediciones en una tarjeta SD, permitiendo su posterior análisis.
-  Incluye un módulo de reloj en tiempo real (RTC) para fechar cada registro de datos.
-  Envía los datos de las mediciones en tiempo real a través de un módulo Bluetooth a una aplicación móvil diseñada a medida para el proyecto.

🧰  Materiales Necesarios:
-  **Placa Arduino Uno con su respectivo cable de alimentación y USB**.
-  **Cables Jumper**. La cantidad y tipo varían según cómo se estructure la conexión.
-  **Breadboard/protoboard**. Se recomienda una del tipo MB-102.
-  **Sensor de temperatura y humedad DHT11 o DHT22**. En nuestro caso se utilizó el DHT11, pero el DHT22 ofrece mayor rango y presición a costo de una lectura más lenta.
-  **Sensor de radiación UV ML8511**.
-  **LCD I2C 16X2**.
-  **Buzzer Pasivo**.
-  **LDR y resistencia de 1kΩ**.
-  **Lector de tarjetas SD del tipo SPI**.
-  **Tarjeta microSD** (con adapatador, según corresponda) de una capacidad máxima de **32GB** en formato **FAT32 o FAT16**.
-  **Módulo Bluetooth HC-05**.


**‼️Antes de compilar y cargar el código "FINAL", asegurate de instalar las siguientes librerías desde el Administrador de Librerías del Arduino IDE:**
-  **Wire.h (incluida en la IDE de desarollo de Arduino)**: permite modificar los pines de comunicación I2C con el LCD de 16x2.
-  **DHT.h (by Adafruit)**: necesaria para trabajar con el sensor DHT11 (o DHT22 en su defecto). 
-  **LiquidCrystal_I2C.h (by Frank Brabander)**: permitre el manejo de la pantalla LCD I2C 16x2.
-  **virtuabotixRTC.h: (by Joseph Datillo)**: permite el control del módulo RTC1302.
-  **SD.h (incluida en la IDE de desarollo de Arduino)**: necesaria para la escritura de datos en un archivo .CSV en la SD en FAT32
-  **SoftwareSerial.h (incluida en la IDE de desarollo de Arduino)**: permite asignar puertos de TXD y RXD personalizados para el módulo Bluetooth HC-05.


🔌Esquema de conexión sugerido
****PENDIENTE****



