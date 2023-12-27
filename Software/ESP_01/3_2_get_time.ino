// *********************************************************************
// Setup NTP-Zeit Variablen bzw. Time-Bibliothek
// ****************************** QUELLEN ******************************
//
//  https://fipsok.de/Projekt/esp8266-ntp-zeit
//  http://www.cplusplus.com/reference/ctime/tm/
//  https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv
//
// *********************************************************************

struct tm tm;
const uint32_t SYNC_INTERVAL = 24;
const char* const PROGMEM NTP_SERVER[] = { "fritz.box", "de.pool.ntp.org", "at.pool.ntp.org", "ch.pool.ntp.org", "ptbtime1.ptb.de", "europe.pool.ntp.org" };
extern "C" uint8_t sntp_getreachability(uint8_t);

bool getNtpServer(bool reply = false) {
  uint32_t timeout{ millis() };
  configTime("CET-1CEST,M3.5.0/02,M10.5.0/03", NTP_SERVER[0], NTP_SERVER[1], NTP_SERVER[2]);
  do {
    delay(25);
    if (millis() - timeout >= 1e3) {
      delay(975);
    }
    sntp_getreachability(0) ? reply = true : sntp_getreachability(1) ? reply = true
                                           : sntp_getreachability(2) ? reply = true
                                                                     : false;
  } while (millis() - timeout <= 16e3 && !reply);
  return reply;
}

// *********************************************************************
// Kalendarzeit in Serial senden
// *********************************************************************
void showTime()
// *********************************************************************
{
  char buff[20];
  static time_t lastsec{ 0 };
  time_t now = time(&now);
  localtime_r(&now, &tm);
  if (tm.tm_sec != lastsec) {
    lastsec = tm.tm_sec;
    strftime(buff, sizeof(buff), "%d.%m.%Y %T", &tm);
    if (!(time(&now) % (SYNC_INTERVAL * 3600))) {
      getNtpServer(true);
    }
    datum = (tm.tm_mday);          // Tag als Zahl
    monat = (tm.tm_mon + 1);       // Monat als Zahl
    jahr = (tm.tm_year - 100);    // Jahr als Zahl
    stunde = (tm.tm_hour);         // aktuelle Stunde
    minute = (tm.tm_min);          // aktuelle Minute
    sekunde = (tm.tm_sec);         // aktuelle Sekunde
    //time_sync();
    //geo_sync();
    //wlan_status();
    //Serial.println(sonnenaufgang_stunde);
    //Serial.println(sonnenaufgang_minute);
    //Serial.println(sonnenuntergang_stunde);
    //Serial.println(sonnenuntergang_minute);
    //Serial.println(sonnenaufgang);
    //Serial.println(sonnenuntergang);
    //Serial.println(str_sonnenaufgang);
    //Serial.println(str_sonnenuntergang);
  }
}

// *********************************************************************
// Setup NTP Variablen
// *********************************************************************
void setup_ntpdaten()
// *********************************************************************
{
  bool timeSync = getNtpServer();
}
