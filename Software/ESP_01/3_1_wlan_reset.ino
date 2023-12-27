// *********************************************************************
// Wlan-Reset-Funktion
// *********************************************************************
void Wifi_manager_reset()
// *********************************************************************
{
  if (atmega == "WLAN_RST") {
    wm.resetSettings();
    WiFiManager wifiManager;
    if (!wifiManager.startConfigPortal("Terra-Lichtcontrol", "12345678")) {
      delay(3000);
      ESP.restart();
      delay(5000);
    }
  }
}

// *********************************************************************
// Wlan reconnect
// *********************************************************************
unsigned long previousMillis = 0;
unsigned long interval = 3600000;  // 1 h
// *********************************************************************
void reconnect()
// *********************************************************************
{
  unsigned long currentMillis = millis();
  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >= interval)) {
    WiFi.disconnect();
    delay(3000);
    WiFi.reconnect();
    previousMillis = currentMillis;
  }
}