#include <WiFi.h>
#include <ThingSpeak.h>

// --------------------
// CONFIGURACIÓN SENSOR
// --------------------

// Pin donde está conectado el MQ-3
#define MQ3_PIN 4

// Pines del LED RGB
#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 7

// --------------------
// CONFIGURACIÓN WIFI
// --------------------

// Red a la que se conectará el ESP32
const char* ssid = "iPhone de Matilde";
const char* password = "219693729";

// --------------------
// CONFIGURACIÓN THINGSPEAK
// --------------------

// Canal donde se almacenarán los datos
unsigned long channelID = 3411523;

// Clave para enviar datos al canal
const char* writeAPIKey = "V4DXWL3Y1BSY0D3Z";

// Cliente de comunicación
WiFiClient client;

// Variable para controlar cada cuánto se envían datos
unsigned long ultimoEnvio = 0;

void setup() {

  // Inicia el monitor serial
  Serial.begin(115200);

  // Configura los LEDs como salidas
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Conecta el ESP32 a Internet
  Serial.println("Conectando WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado");

  // Inicia la conexión con ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {

  // Lee el valor entregado por el sensor MQ-3
  int valorGas = analogRead(MQ3_PIN);

  // Variable para guardar el estado de la palta
  int estado;

// Clasificación según el valor medido

if (valorGas < 320) {

  estado = 0;

  // Sin palta: LED apagado
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  Serial.print("Valor MQ3: ");
  Serial.print(valorGas);
  Serial.println(" --> SIN PALTA");
}

else if (valorGas < 400) {

  estado = 1;

  // LED rojo = palta inmadura
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  Serial.print("Valor MQ3: ");
  Serial.print(valorGas);
  Serial.println(" --> PALTA INMADURA");
}

else {

  estado = 2;

  // LED verde = palta madura
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  Serial.print("Valor MQ3: ");
  Serial.print(valorGas);
  Serial.println(" --> PALTA MADURA");
}

  // Cada 20 segundos envía los datos a ThingSpeak
  if (millis() - ultimoEnvio >= 20000) {

    // Guarda el valor del sensor
    ThingSpeak.setField(1, valorGas);

    // Guarda el estado de la palta
    ThingSpeak.setField(2, estado);

    // Envía los datos al canal
    int respuesta = ThingSpeak.writeFields(channelID, writeAPIKey);

    if (respuesta == 200) {
      Serial.println("Datos enviados a ThingSpeak");
    } else {
      Serial.println("Error al enviar datos");
    }

    // Reinicia el contador de tiempo
    ultimoEnvio = millis();
  }

  // Realiza una nueva lectura cada segundo
  delay(1000);
}