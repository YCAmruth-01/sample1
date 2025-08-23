#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <SPIFFS.h>
#include <ArduinoJson.h>

#define CONFIG_PATH "/credentials.json"
#define HTML_PATH "/index.html"

const char* ap_ssid = "ESP32_Config";
const char* ap_password = "esp32pass";
WebServer server(80);
StaticJsonDocument<256> configDoc;

void loadConfig() {
  File f = SPIFFS.open(CONFIG_PATH, "r");
  if (f) { deserializeJson(configDoc, f); f.close(); }
}
void saveConfig() {
  File f = SPIFFS.open(CONFIG_PATH, "w");
  if (f) { serializeJson(configDoc, f); f.close(); }
}
void connectWiFi() {
  const char* ssid = configDoc["ssid"] | "";
  const char* pass = configDoc["password"] | "";
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, pass);
}
void handleWeb() {
  File f = SPIFFS.open(HTML_PATH, "r");
  if (!f) { server.send(404, "text/plain", "No index.html"); return; }
  server.send(200, "text/html", f.readString()); f.close();
}
void handleUpdate() {
  deserializeJson(configDoc, server.arg("plain"));
  saveConfig();
  server.send(200, "text/plain", "Updated");
}
void setup() {
  Serial.begin(115200);
  SPIFFS.begin(true);
  WiFi.softAP(ap_ssid, ap_password);
  loadConfig();
  connectWiFi();
  server.on("/", HTTP_GET, handleWeb);
  server.on("/updateConfig", HTTP_POST, handleUpdate);
  server.begin();
}
void loop() { server.handleClient(); }