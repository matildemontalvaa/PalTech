# PalTech – Sistema de Detección de Madurez de Paltas

## Descripción del proyecto

PalTech es un sistema embebido basado en ESP32 que permite estimar el estado de madurez de una palta mediante el sensor MQ-3. El sistema procesa los datos obtenidos, clasifica el estado como “madura” o “inmadura” y envía la información a la plataforma ThingSpeak para su visualización en tiempo real.

## Integrantes del equipo

* Nombre 1 – Jose Tomás Apeleo
* Nombre 2 – Clemente Duarte
* Nombre 3 – Matilde Montalva

## Problema que resuelve

En la actualidad, la determinación del punto de maduración de una palta se realiza de forma manual y subjetiva, lo que genera inconsistencias. Este proyecto busca automatizar el proceso mediante sensores electrónicos, reduciendo el error humano y mejorando la precisión en la clasificación del fruto.

## Componentes necesarios para replicar el hardware

* ESP32-S3 Super Mini
* Sensor MQ-3
* LED RGB
* Batería 1200 mAh
* Interruptor ON/OFF (mini slide switch 3-pin)
* Perf board (placa perforada)
* Cables Dupont

## Instrucciones para cargar el firmware

1. Abrir el archivo main.ino en Arduino IDE.
2. Instalar el soporte de placas ESP32 desde el gestor de tarjetas.
3. Seleccionar la placa ESP32-S3 Super Mini.
4. Conectar el dispositivo al computador mediante USB.
5. Instalar o verificar las librerías necesarias:

   * WiFi.h
   * HTTPClient.h
6. Configurar en el código:

   * Nombre de red WiFi (SSID)
   * Contraseña
   * API Key de ThingSpeak
7. Subir el código al ESP32.
8. Abrir el monitor serial para verificar el funcionamiento.

Importante: esperar aproximadamente 5 minutos para el calentamiento del sensor MQ-3 antes de realizar mediciones confiables.

## Instrucciones para el dashboard (ThingSpeak)

1. Ingresar a https://thingspeak.mathworks.com
2. Crear una cuenta o iniciar sesión.
3. Crear un nuevo canal (Channel).
4. Configurar los campos:

   * Field 1: Valor MQ-3
   * Field 2: Estado de madurez
5. Copiar la Write API Key y agregarla en el firmware.
6. Ejecutar el sistema y verificar la actualización de datos cada aproximadamente 20 segundos.

## Link al dashboard

https://thingspeak.mathworks.com/channels/3411523
