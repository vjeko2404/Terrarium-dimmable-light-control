// *********************************************************************
// Geodaten von Abstract-API abrufen
// *********************************************************************
void geodaten()
// *********************************************************************
{
  if ((WiFi.status() == WL_CONNECTED && atmega == "GEO_GET") || (WiFi.status() == WL_CONNECTED && startup == true)) {
    const char* geo_host = "ipgeolocation.abstractapi.com";
    const int httpsPort = 443;  //HTTPS = 443 oder HTTP = 80
    WiFiClientSecure geo_client;
    geo_client.setInsecure();
    geo_client.setTimeout(15000);  // 15 Seconds
    delay(1000);
    int r = 0;  //retry Zähler
    while ((!geo_client.connect(geo_host, httpsPort)) && (r < 30)) {
      delay(100);
      r++;
    }
    String Link;
    Link = "/v1/?api_key=" + Key;
    geo_client.print(String("GET ") + Link + " HTTP/1.1\r\n" + "Host: " + geo_host + "\r\n" + "Connection: close\r\n\r\n");
    while (geo_client.connected()) {
      geo_response = geo_client.readStringUntil('\n');
      if (geo_response == "\r") {
        break;
      }
    }
    while (geo_client.connected()) {
      geo_response = geo_client.readString();
    }
    StaticJsonDocument<600> filter;
    filter["ip_address"] = true;
    filter["city"] = true;
    filter["city_geoname_id"] = false;
    filter["region"] = false;
    filter["region_iso_code"] = false;
    filter["region_geoname_id"] = false;
    filter["postal_code"] = true;
    filter["country"] = false;
    filter["country_code"] = true;
    filter["country_geoname_id"] = false;
    filter["country_is_eu"] = false;
    filter["continent"] = false;
    filter["continent_code"] = false;
    filter["continent_geoname_id"] = false;
    filter["longitude"] = true;
    filter["latitude"] = true;
    filter["security"] = false;
    filter["timezone"] = false;
    filter["flag"] = false;
    filter["currency"] = false;
    filter["connection"] = false;

    JsonObject filter_timezone = filter.createNestedObject("timezone");
    filter_timezone["name"] = false;
    filter_timezone["abbreviation"] = false;
    filter_timezone["gmt_offset"] = true;
    filter_timezone["current_time"] = false;
    filter_timezone["is_dst"] = false;
    filter["flag"] = false;
    filter["currency"] = false;
    filter["connection"] = false;

    StaticJsonDocument<300> doc;

    DeserializationError error = deserializeJson(doc, geo_response, DeserializationOption::Filter(filter));

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    const char* tmp_ip_address = doc["ip_address"];       // "88.152.186.126"
    const char* tmp_city = doc["city"];                   // "Bonn"
    postal_code = doc["postal_code"];                     // "53225"
    const char* tmp_country_code = doc["country_code"];   // "DE"
    longitude = doc["longitude"];                         // 7.1271
    latitude = doc["latitude"];                           // 50.7463
    timezone_gmt_offset = doc["timezone"]["gmt_offset"];  // 2

    ip_address = tmp_ip_address;
    city = tmp_city;
    country_code = tmp_country_code;

    if (postal_code > 0) {
      Serial.println("OK");
    } else {
      Serial.println("FAILED");
    }
  }
  startup = false;
}

// *********************************************************************
// Geodaten autoreconnect
// *********************************************************************
void geo_reconnect()
// *********************************************************************
{
  if ((WiFi.status() == WL_CONNECTED) && (postal_code <= 0) && (startup == false)) {
    geodaten();
  }
}

// *********************************************************************
// Setup Variablen
// *********************************************************************
void setup_geodaten()
// *********************************************************************
{
  startup = true;  //  Variable für Geodaten am Startup abzurufen
}