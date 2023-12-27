
// Andere Anzeige-Möglichkeiten. Nicht benötigt.
/*
Serial.print("Stunde: "); Serial.println(tm.tm_hour);          // aktuelle Stunde
Serial.print("Minute: "); Serial.println(tm.tm_min);           // aktuelle Minute
Serial.print("Sekunde: "); Serial.println(tm.tm_sec);          // aktuelle Sekunde
Serial.print("Tag: "); Serial.println(tm.tm_mday);             // Tag als Zahl
Serial.print("Monat: "); Serial.println(tm.tm_mon + 1);        // Monat als Zahl
Serial.print("Jahr: "); Serial.println(tm.tm_year + 1900);     // Jahr als Zahl
strftime (buff, sizeof(buff), "Wochentag: %u\n", &tm);         // http://www.cplusplus.com/reference/ctime/strftime/
Serial.print(buff);                                            // Tag der Woche
Serial.print("Tag des Jahr: "); Serial.println(tm.tm_yday + 1);// Tag des Jahres
strftime (buff, sizeof(buff), "Kalenderwoche: %V\n", &tm);     // http://www.cplusplus.com/reference/ctime/strftime/
Serial.print(buff);                                            // Kalenderwoche
Serial.println(DAY_NAMES[tm.tm_wday]);                         // aktueller Wochentag
Serial.println(MONTH_NAMES[tm.tm_mon]);                        // aktueller Monat
Serial.println(DAY_SHORT[tm.tm_wday]);                         // aktueller Wochentag (Abk.)
Serial.println(MONTH_SHORT[tm.tm_mon]);                        // aktueller Monat (Abk.)
Serial.printf("Name der Zeitzone: %s\n", _tzname[0]);
Serial.printf("Name der Sommerzeitzone: %s\n", _tzname[1]);
Serial.println(tm.tm_isdst ? "Sommerzeit" : "Normalzeit");


//const char* const PROGMEM DAY_NAMES[]   = { "Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag" };
//const char* const PROGMEM DAY_SHORT[]   = { "So", "Mo", "Di", "Mi", "Do", "Fr", "Sa" };
//const char* const PROGMEM MONTH_NAMES[] = { "Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember" };
//const char* const PROGMEM MONTH_SHORT[] = { "Jan", "Feb", "Mrz", "Apr", "Mai", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Dez" };

CHECK CONNECNTION PERIODICALY

unsigned long currentMillis = millis();
// if WiFi is down, try reconnecting
if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {
  Serial.print(millis());
  Serial.println("Reconnecting to WiFi...");
  WiFi.disconnect();
  WiFi.reconnect();

  //ESP.restart(); //Or completly restart the ESP32
  previousMillis = currentMillis;
}

  char* del;
    del = strtok(str_sonnenaufgang, ":");
    sonnenaufgang_stunde = atoi(del);
    del = strtok(NULL, ":");
    sonnenaufgang_minute = atoi(del);
    del = strtok(str_sonnenuntergang, ":");
    sonnenuntergang_stunde = atoi(del);
    del = strtok(NULL, ":");
    sonnenuntergang_minute = atoi(del);
 */


