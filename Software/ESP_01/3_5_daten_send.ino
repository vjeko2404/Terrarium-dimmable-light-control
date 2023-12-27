// *********************************************************************
// Zeitdaten von NTP Server abrufen
// *********************************************************************
static unsigned long time_last_ms = 0;
const unsigned int time_interval = 1000;
// *********************************************************************
void time_sync()
// *********************************************************************
{
  if (WiFi.status() == WL_CONNECTED) {
    if (millis() - time_last_ms >= time_interval) {
      time_last_ms = millis();
      Serial.println();
      Serial.print("TIME");
      Serial.print("%");
      Serial.print(datum);
      Serial.print("%");
      Serial.print(monat);
      Serial.print("%");
      Serial.print(jahr);
      Serial.print("%");
      Serial.print(stunde);
      Serial.print("%");
      Serial.print(minute);
      Serial.print("%");
      Serial.print(sekunde);
      Serial.print("%");
      Serial.print(str_sonnenaufgang);
      Serial.print("%");
      Serial.print(str_sonnenuntergang);
    }
  }
}

// *********************************************************************
// Geodaten von Abstract-API abrufen
// ********************************************************************
static unsigned long geo_last_ms = 0;
const unsigned int geo_interval = 3000;
// *********************************************************************
void geo_sync()
// *********************************************************************
{
  if (WiFi.status() == WL_CONNECTED) {
    if (millis() - geo_last_ms >= geo_interval) {
      geo_last_ms = millis();
      Serial.println();
      //Serial.print(ip_address);
      Serial.print("GEO");
      Serial.print("$");
      Serial.print(city);
      Serial.print("$");
      Serial.print(postal_code);
      Serial.print("$");
      Serial.print(country_code);
      Serial.print("$");
      Serial.print(longitude, 4);
      Serial.print("$");
      Serial.print(latitude, 4);
      Serial.print("$");
      Serial.print(timezone_gmt_offset);
    }
  }
}

// *********************************************************************
// Wlan Status zeigen
// *********************************************************************
static unsigned long wifi_last_ms = 0;
const unsigned int wifi_interval = 5000;
// *********************************************************************
void wlan_status()
// *********************************************************************
{
  if (WiFi.status() == WL_CONNECTED) {
    if ((millis() - wifi_last_ms >= wifi_interval)) {
      wifi_last_ms = millis();
      Serial.println();
      Serial.print("STATUS");
      Serial.print(";");
      Serial.print(WiFi.SSID());
      Serial.print(";");
      Serial.print(WiFi.localIP());
      Serial.print(";");
      Serial.print(WiFi.gatewayIP());
      Serial.print(";");
      Serial.print(WiFi.dnsIP());
    }
  } else if (WiFi.status() != WL_CONNECTED) {
    Serial.println();
    Serial.print("Wifi not connected");
  }
}