// *********************************************************************
// Sonnen Unter/Aufgang berechnen und Daten-Parsing
// *********************************************************************
void sonnendaten_berechnen()
// *********************************************************************
{
    char str[6];
    calcSunriseSunset(jahr, monat, datum, latitude, longitude, transit, sunrise, sunset);
    str_sonnenaufgang = (hoursToString(sunrise + timezone_gmt_offset, str));
    str_mittagssonne = (hoursToString(transit + timezone_gmt_offset, str));
    str_sonnenuntergang = (hoursToString(sunset + timezone_gmt_offset, str));

    //Serial.println(hoursToString(sunrise + timezone_gmt_offset, str));
    //Serial.println(hoursToString(transit + timezone_gmt_offset, str));
    //Serial.println(hoursToString(sunset + timezone_gmt_offset, str));

    str_sonnenaufgang.toCharArray(sonnenaufgang, 6);
    str_mittagssonne.toCharArray(mittagssonne, 6);
    str_sonnenuntergang.toCharArray(sonnenuntergang, 6);
    //parsing();
  }
/*
void parsing() {
  char *del;
  del = strtok(sonnenaufgang, ":");
  sonnenaufgang_stunde = atoi(del);
  del = strtok(NULL, ":");
  sonnenaufgang_minute = atoi(del);
  del = strtok(sonnenuntergang, ":");
  sonnenuntergang_stunde = atoi(del);
  del = strtok(NULL, ":");
  sonnenuntergang_minute = atoi(del);
}
*/
// *********************************************************************
// Sonnen Unter/Aufgang Zeiten rundung
// *********************************************************************
void sonnendaten()
// *********************************************************************
{
}
char *hoursToString(double h, char *str) {
  int m = int(round(h * 60));
  int hr = (m / 60) % 24;
  int mn = m % 60;

  str[0] = (hr / 10) % 10 + '0';
  str[1] = (hr % 10) + '0';
  str[2] = '%';
  str[3] = (mn / 10) % 10 + '0';
  str[4] = (mn % 10) + '0';
  str[5] = '\0';
  return str;
}
