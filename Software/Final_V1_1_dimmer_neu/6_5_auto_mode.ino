// *********************************************************************
// Automatic mode ein
// *********************************************************************
void mFunc_auto_mode_ein(uint8_t param)
// *********************************************************************
{
  if ((got_data_wlan == true) && (esp_jahr >= 20)) {
    auto_mode = 1;
    //EEPROM.write(10, 1);
    RTC.setYear(esp_jahr);
    RTC.setMonth(esp_monat);
    RTC.setDate(esp_datum);
    RTC.setHour(esp_stunde);
    RTC.setMinute(esp_minute);
    RTC.setSecond(esp_sekunde);
    sa_start_std = auto_sa_start_std;
    sa_start_min = auto_sa_start_min;
    su_start_std = auto_su_start_std;
    su_start_min = auto_su_start_min;
    EEPROM.write(14, sa_start_std);
    EEPROM.write(16, sa_start_min);
    EEPROM.write(18, su_start_std);
    EEPROM.write(20, su_start_min);
    lcd.clear();
    lcd.setCursor(9, 1);
    lcd.print(F("OK"));
  } else if (got_data_wlan == false && sprache == 1) {
    lcd.clear();
    lcd.setCursor(4, 1);
    lcd.print(F("Keine WLAN"));
    lcd.setCursor(4, 2);
    lcd.print(F("Verbindung"));
    auto_mode = 0;
    EEPROM.write(10, 1);
  } else if (got_data_wlan == false && sprache == 2) {
    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print(F("No WiFi"));
    lcd.setCursor(4, 2);
    lcd.print(F("connection"));
    auto_mode = 0;
    EEPROM.write(10, 0);
  } else if (got_data_wlan == false && sprache == 3) {
    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print(F("WLAN nije"));
    lcd.setCursor(6, 2);
    lcd.print(F("povezan"));
    auto_mode = 0;
    //EEPROM.write(10, 0);
  }
  delay(400);
  LCDML.FUNC_goBackToMenu();
}

// *********************************************************************
// Automatic mode aus
// *********************************************************************
void mFunc_auto_mode_aus(uint8_t param)
// *********************************************************************
{
  auto_mode = 0;
  //EEPROM.write(10, 0);
  lcd.clear();
  lcd.setCursor(9, 1);
  lcd.print(F("OK"));
  delay(400);
  LCDML.FUNC_goBackToMenu();
}

// *********************************************************************
// Automatic mode loop -Automatische Umstellung und Fehlerkorrektur
// *********************************************************************
void automatic_mode_loop()
// *********************************************************************
{  // Variablen-Fehler automatische korrektur
  if ((auto_mode == 1) && (auto_su_start_std != 0) && (auto_su_start_min != 0) && (auto_sa_start_std != 0) && (auto_sa_start_min != 0)) {
    sa_start_std = auto_sa_start_std;
    sa_start_min = auto_sa_start_min;
    su_start_std = auto_su_start_std;
    su_start_min = auto_su_start_min;
  }  // Eine minute nach dem Mitternacht werden die Sonnendaten aktualisiert
  else if ((auto_mode == 1) && (rtc_stunde == 0) && (rtc_minute == 1) && (rtc_sekunde == 0)) {
    sa_start_std = auto_sa_start_std;
    sa_start_min = auto_sa_start_min;
    su_start_std = auto_su_start_std;
    su_start_min = auto_su_start_min;
  }
}