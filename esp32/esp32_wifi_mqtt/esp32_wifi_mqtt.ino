

#include <math.h>
#include <WiFi.h>
#include <PubSubClient.h>

// ---------- Wi-Fi ----------
const char* ssid = "NOMBRE_DE_TU_WIFI";
const char* password = "CONTRASEÑA_DE_TU_WIFI";



// ---------- MQTT ----------
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;

const char* mqtt_topic = "esp32_prueba_movimiento";

WiFiClient espClient;
PubSubClient client(espClient);

// LED integrado de la ESP32
const int LED_PIN = 2;


void setup_wifi() {

  Serial.println();
  Serial.print("Conectando al Wi-Fi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi conectado");

  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}


void callback(char* topic, byte* payload, unsigned int length) {

  String message = "";

  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  // Buscar "values":[X,Y,Z]
  int valuesStart = message.indexOf("\"values\":[");
  
  if (valuesStart == -1) {
    return;
  }

  valuesStart += 10;

  int comma1 = message.indexOf(',', valuesStart);
  int comma2 = message.indexOf(',', comma1 + 1);
  int end = message.indexOf(']', comma2 + 1);

  if (comma1 == -1 || comma2 == -1 || end == -1) {
    return;
  }

  float x = message.substring(valuesStart, comma1).toFloat();
  float y = message.substring(comma1 + 1, comma2).toFloat();
  float z = message.substring(comma2 + 1, end).toFloat();

  // Magnitud de la aceleración
  float acceleration = sqrt(x * x + y * y + z * z);

  Serial.print("Aceleración: ");
  Serial.println(acceleration);

  // Detectar movimiento
  static float previousAcceleration = 9.8;
  static unsigned long lastMovement = 0;

  float difference = abs(acceleration - previousAcceleration);

  if (difference > 0.5) {
    lastMovement = millis();

    digitalWrite(LED_PIN, HIGH);
    Serial.println("MOVING");
  }

  // segundos sin movimiento significativo
  if (millis() - lastMovement > 1000) {

    digitalWrite(LED_PIN, LOW);
    Serial.println("STILL");
  }

  previousAcceleration = acceleration;
}


void reconnect_mqtt() {

  while (!client.connected()) {

    Serial.print("Conectando a MQTT...");

    String clientId =
      "ESP32-" + String((uint32_t)ESP.getEfuseMac(), HEX);

    if (client.connect(clientId.c_str())) {

      Serial.println(" conectado!");

      client.subscribe(mqtt_topic);

      Serial.print("Suscrito a: ");
      Serial.println(mqtt_topic);

    } 
    else {

      Serial.print(" error, codigo=");
      Serial.print(client.state());

      Serial.println(" . Reintentando en 5 segundos...");

      delay(5000);
    }
  }
}


void setup() {

  Serial.begin(115200);

  // Configuramos el LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}


void loop() {

  if (!client.connected()) {
    reconnect_mqtt();
  }

  client.loop();
}
