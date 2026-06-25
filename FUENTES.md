# FUENTES

## Librerías utilizadas

| Librería                | Versión                | Uso en el proyecto                                                      | Fuente                                          |
| ----------------------- | ---------------------- | ----------------------------------------------------------------------- | ----------------------------------------------- |
| WiFi                    | Incluida en ESP32 Core | Conexión del ESP32-S3 a la red WiFi para el envío de datos              | https://github.com/espressif/arduino-esp32      |
| ThingSpeak              | 2.0.0                  | Envío de datos de concentración de gases hacia la plataforma ThingSpeak | https://github.com/mathworks/thingspeak-arduino |
| Arduino Core para ESP32 | 3.x                    | Compatibilidad entre Arduino IDE y ESP32-S3 Super Mini                  | https://github.com/espressif/arduino-esp32      |

---

## Documentación técnica consultada

### ESP32-S3 Super Mini

* Fuente: Documentación oficial de Espressif.
* URL: https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/
* Uso: Configuración de pines, conexión WiFi y programación del microcontrolador.

### Sensor MQ-3

* Fuente: Datasheet oficial del sensor MQ-3.
* URL: https://www.sparkfun.com/datasheets/Sensors/MQ-3.pdf
* Uso: Comprensión del funcionamiento del sensor, voltajes de operación y comportamiento de la salida analógica.

### ThingSpeak

* Fuente: Documentación oficial de ThingSpeak.
* URL: https://thingspeak.mathworks.com/docs/
* Uso: Configuración de canales, campos de datos y visualización de gráficos.

### Arduino IDE

* Fuente: Documentación oficial de Arduino.
* URL: https://docs.arduino.cc/
* Uso: Programación, compilación y carga del firmware al ESP32-S3.

---

## Código externo adaptado

### Conexión WiFi automática (main.ino)

* Fuente: Random Nerd Tutorials.
* URL: https://randomnerdtutorials.com/esp32-useful-wifi-functions/
* Adaptación realizada:

  * Se simplificó la rutina de conexión para adecuarla a un único punto de acceso WiFi.
  * Se agregaron mensajes de depuración mediante Serial Monitor para facilitar la identificación de errores de conexión.
  * Se ajustó la frecuencia de reconexión para evitar intentos excesivos.

### Envío de datos a ThingSpeak (main.ino)

* Fuente: Ejemplos oficiales de MathWorks ThingSpeak.
* URL: https://github.com/mathworks/thingspeak-arduino
* Adaptación realizada:

  * Se modificó el ejemplo para utilizar lecturas provenientes del sensor MQ-3.
  * Se configuró el envío de datos cada 20 segundos.
  * Se agregaron mensajes de confirmación en el Serial Monitor después de cada transmisión.

### Lectura analógica del sensor MQ-3 (main.ino)

* Fuente: Ejemplos de lectura analógica para ESP32.
* URL: https://docs.espressif.com/projects/arduino-esp32/en/latest/
* Adaptación realizada:

  * Se ajustó la lectura al pin utilizado en el prototipo.
  * Se agregó una clasificación de madurez basada en umbrales experimentales obtenidos durante las pruebas.
  * Se incorporó visualización de resultados en el Serial Monitor.

---

## Uso de Inteligencia Artificial

### Desarrollo del firmware principal

* Herramienta: ChatGPT (OpenAI).

* Fecha de uso: Junio 2026.

* Uso:

  * Apoyo en la programación del ESP32-S3.
  * Corrección de errores de compilación.
  * Configuración de la comunicación con ThingSpeak.
  * Implementación de la lógica de clasificación de paltas maduras e inmaduras.
  * Generación de comentarios explicativos en el código.

* Adaptaciones realizadas:

  * Se modificaron los umbrales de clasificación según resultados experimentales propios.
  * Se ajustó la frecuencia de lectura a una muestra por segundo.
  * Se configuró el envío de datos a ThingSpeak cada 20 segundos.

* Comprensión:

  * El equipo comprende el funcionamiento de cada sección del código.
  * Se realizaron pruebas individuales de lectura del sensor, control del LED y transmisión de datos antes de integrar el sistema completo.
  * El comportamiento fue validado mediante el Serial Monitor y los gráficos de ThingSpeak.

### Elaboración de documentación

* Herramienta: ChatGPT (OpenAI).

* Fecha de uso: Junio 2026.

* Uso:

  * Generación de borradores para README.md.
  * Apoyo en la redacción del BOM.
  * Apoyo en la documentación de hardware y firmware.
  * Organización de la estructura del repositorio GitHub.

* Adaptaciones realizadas:

  * Todo el contenido técnico específico del proyecto fue revisado y complementado por el equipo.
  * Se incorporaron fotografías, diagramas y resultados experimentales obtenidos durante el desarrollo.

---

## Referencias académicas

1. Datasheet oficial del sensor MQ-3.
   https://www.sparkfun.com/datasheets/Sensors/MQ-3.pdf

2. Documentación ESP32-S3 de Espressif.
   https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/

3. Documentación oficial de ThingSpeak.
   https://thingspeak.mathworks.com/docs/

4. Documentación oficial de Arduino.
   https://docs.arduino.cc/

5. Random Nerd Tutorials - ESP32 WiFi Functions.
   https://randomnerdtutorials.com/esp32-useful-wifi-functions/

6. Repositorio oficial ThingSpeak Arduino.
   https://github.com/mathworks/thingspeak-arduino
