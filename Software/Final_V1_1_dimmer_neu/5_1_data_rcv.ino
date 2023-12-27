// *********************************************************************
// SoftwareSerial Datenempfang
// *********************************************************************
void ESP_Receive()
// *********************************************************************
{
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;
  while (Serial.available() > 0 && esp_data == false) {
    rc = Serial.read();

    if (rc != endMarker) {
      ESP_Data[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    } else {
      ESP_Data[ndx] = '\0';
      ndx = 0;
      esp_data = true;
    }
  }
}

// *********************************************************************
// Datenempfang loop
// *********************************************************************
void ESP_Receive_loop()
// *********************************************************************
{
  ESP_Receive();
  if (esp_data == true) {
    parse_data_time();
    parse_data_geo();
    parse_data_wlan();
  }
  if (esp_data == true) {  //*************DEBUG*************//
    //Serial.println(ESP_Data);
    //Serial.println(ip_address);
    //Serial.println(gateway);
    //Serial.println(dns);
    //Serial.println(esp_jahr);
    //Serial.println(esp_datum);
    //Serial.println(esp_monat);
    //Serial.println(esp_stunde);
    //Serial.println(esp_minute);
    //Serial.println(esp_sekunde);
    //Serial.println(sa_start_std);
    //Serial.println(sa_start_min);
    //Serial.println(su_start_std);
    //Serial.println(su_start_min);
    esp_data = false;
  }
}

// *********************************************************************
// ESP Datentrennung - Zeiten
// *********************************************************************
void parse_data_time()
// *********************************************************************
{
  char* del;
  if (ESP_Data >= "TIME") {
    del = strtok(ESP_Data, "%");
    del = strtok(NULL, "%");
    esp_datum = atoi(del);
    del = strtok(NULL, "%");
    esp_monat = atoi(del);
    del = strtok(NULL, "%");
    esp_jahr = atoi(del);
    del = strtok(NULL, "%");
    esp_stunde = atoi(del);
    del = strtok(NULL, "%");
    esp_minute = atoi(del);
    del = strtok(NULL, "%");
    esp_sekunde = atoi(del);
    del = strtok(NULL, "%");
    auto_sa_start_std = atoi(del);
    del = strtok(NULL, "%");
    auto_sa_start_min = atoi(del);
    del = strtok(NULL, "%");
    auto_su_start_std = atoi(del);
    del = strtok(NULL, "%");
    auto_su_start_min = atoi(del);
  }
}

// *********************************************************************
// ESP Datentrennung - Geostandort
// *********************************************************************
void parse_data_geo()
// *********************************************************************
{
  char* del;
  if (got_data_geo == false) {
    if (ESP_Data >= "GEO") {
      del = strtok(ESP_Data, "$");
      del = strtok(NULL, "$");
      strcpy(city, del);
      del = strtok(NULL, "$");
      strcpy(postal_code, del);
      del = strtok(NULL, "$");
      strcpy(country_code, del);
      del = strtok(NULL, "$");
      longitude = atof(del);
      del = strtok(NULL, "$");
      latitude = atof(del);
      del = strtok(NULL, "$");
      timezone_gmt_offset = atoi(del);
      if ((latitude != 0.0) && (longitude != 0.0)) {
        got_data_geo = true;
      }
    }
  }
}

// *********************************************************************
// ESP Datentrennung - Wlan Status
// *********************************************************************
void parse_data_wlan()
// *********************************************************************
{
  char* del;
  if (got_data_wlan == false) {
    if (ESP_Data >= "STATUS") {
      del = strtok(ESP_Data, ";");
      del = strtok(NULL, ";");
      strcpy(ssid, del);
      del = strtok(NULL, ";");
      strcpy(ip_address, del);
      if (strcmp(ip_address, "0") >= 0) {
        got_data_wlan = true;
      }
    }
  }
}