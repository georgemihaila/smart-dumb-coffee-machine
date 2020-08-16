#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266SSDP.h>

const char* ssid     = "";
const char* password = "";

ESP8266WebServer server(80);

void setup(){
    Serial.begin(9600);
    pinMode(14, OUTPUT);
    pinMode(12, OUTPUT);
    digitalWrite(14, LOW); //not sure which state works best
    digitalWrite(12, HIGH);
    WiFi.mode(WIFI_STA);
    WiFi.hostname("ESP2866CM-Dev");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    Serial.print(".");
    digitalWrite(LED_BUILTIN, LOW);
  }
  digitalWrite(LED_BUILTIN, LOW);

  server.on("/description.xml", handleSSDP);
  server.on("/make-coffee", makeCoffee);
  server.onNotFound(handle_NotFound);
  server.begin();

  SSDP.setSchemaURL("description.xml");
  SSDP.setHTTPPort(80);
  SSDP.setName("ESP8266-Coffee-Machine");
  SSDP.setSerialNumber("");
  SSDP.setModelName("ESP8266 simple coffee machine");
  SSDP.setModelNumber("ESP8266CM010");
  SSDP.setDeviceType("upnp:rootdevice"); 
  SSDP.begin();
}

void loop(){
  server.handleClient();
}

void makeCoffee(){
    digitalWrite(14, HIGH);
    digitalWrite(12, LOW);
    delay(500);
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
    server.send(200, "text/html", "ok");
}

void handleSSDP(){
  SSDP.schema(server.client());
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
