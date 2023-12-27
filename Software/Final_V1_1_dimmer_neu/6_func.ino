// *********************************************************************
// Über das Gerät
// *********************************************************************
void mFunc_information(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    lcd.setCursor(2, 0);
    lcd.print(F("2022 CRBK Hennef"));
    lcd.setCursor(1, 2);
    lcd.print(F("Christian R\357ssner"));
    lcd.setCursor(1, 3);
    lcd.print(F("Vjekoslav Jakolic"));
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    if (LCDML.BT_checkAny()) {
      LCDML.FUNC_goBackToMenu();
    }
  }
  if (LCDML.FUNC_close()) {
    //reserve
  }
}

// *********************************************************************
// Hauptanzeige (Bildschirmschoner)
// *********************************************************************
void mFunc_screensaver(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    LCDML.BT_resetRight();
    LCDML.BT_resetLeft();
    lcd.setCursor(0, 0);
    lcd.print(F(" Terra-Lichtcontrol "));
    lcd.setCursor(12, 3);
    lcd.print(F(".  .20"));
    lcd.setCursor(14, 2);
    lcd.print(F(":  :"));
    lcd.setCursor(10, 2);
    lcd.write(8);
    if (auto_mode == 1) {
      lcd.setCursor(17, 1);
      lcd.print(F("[A]"));
    } else {
      lcd.setCursor(17, 1);
      lcd.print(F("[M]"));
    }
    if (simulation == 1) {
      lcd.setCursor(4, 2);
      lcd.print(F(":"));
      lcd.setCursor(4, 3);
      lcd.print(F(":"));
      lcd.setCursor(0, 2);
      lcd.write(5);
      lcd.setCursor(0, 3);
      lcd.write(6);
      if (sa_start_std <= 9) {
        lcd.setCursor(2, 2);
        lcd.print(F("0"));
        lcd.setCursor(3, 2);
        lcd.print(sa_start_std);
      } else {
        lcd.setCursor(2, 2);
        lcd.print(sa_start_std);
      }
      if (sa_start_min <= 9) {
        lcd.setCursor(5, 2);
        lcd.print(F("0"));
        lcd.setCursor(6, 2);
        lcd.print(sa_start_min);
      } else {
        lcd.setCursor(5, 2);
        lcd.print(sa_start_min);
      }
      if (su_start_std <= 9) {
        lcd.setCursor(2, 3);
        lcd.print(F("0"));
        lcd.setCursor(3, 3);
        lcd.print(su_start_std);
      } else {
        lcd.setCursor(2, 3);
        lcd.print(su_start_std);
      }
      if (su_start_min <= 9) {
        lcd.setCursor(5, 3);
        lcd.print(F("0"));
        lcd.setCursor(6, 3);
        lcd.print(su_start_min);
      } else {
        lcd.setCursor(5, 3);
        lcd.print(su_start_min);
      }
    }
    if (lw_on == 1) {
      lcd.setCursor(4, 1);
      lcd.print(F(":"));
      lcd.setCursor(0, 1);
      lcd.write(7);
      if (lwstart_stunde <= 9) {
        lcd.setCursor(2, 1);
        lcd.print(F("0"));
        lcd.setCursor(3, 1);
        lcd.print(lwstart_stunde);
      } else {
        lcd.setCursor(2, 1);
        lcd.print(lwstart_stunde);
      }
      if (lwstart_minute <= 9) {
        lcd.setCursor(5, 1);
        lcd.print(F("0"));
        lcd.setCursor(6, 1);
        lcd.print(lwstart_minute);
      } else {
        lcd.setCursor(5, 1);
        lcd.print(lwstart_minute);
      }
    }
    LCDML.FUNC_setLoopInterval(100);
  }
  if (LCDML.FUNC_loop()) {  // ******* LOOP *********
    if (LCDML.BT_checkEnter()) {
      LCDML.FUNC_goBackToMenu();
    }
    if (got_data_wlan == true) {
      lcd.setCursor(16, 1);
      lcd.write(9);
    } else {
      // reserve
    }
    lcd.setCursor(18, 3);
    lcd.print(rtc_jahr);
    if (rtc_sekunde <= 9) {
      lcd.setCursor(18, 2);
      lcd.print(F("0"));
      lcd.setCursor(19, 2);
      lcd.print(rtc_sekunde);
    } else {
      lcd.setCursor(18, 2);
      lcd.print(rtc_sekunde);
    }
    if (rtc_minute <= 9) {
      lcd.setCursor(15, 2);
      lcd.print(F("0"));
      lcd.setCursor(16, 2);
      lcd.print(rtc_minute);
    } else {
      lcd.setCursor(15, 2);
      lcd.print(rtc_minute);
    }
    if (rtc_stunde <= 9) {
      lcd.setCursor(12, 2);
      lcd.print(F("0"));
      lcd.setCursor(13, 2);
      lcd.print(rtc_stunde);
    } else {
      lcd.setCursor(12, 2);
      lcd.print(rtc_stunde);
    }
    if (rtc_datum <= 9) {
      lcd.setCursor(10, 3);
      lcd.print(F("0"));
      lcd.setCursor(11, 3);
      lcd.print(rtc_datum);
    } else {
      lcd.setCursor(10, 3);
      lcd.print(rtc_datum);
    }
    if (rtc_monat <= 9) {
      lcd.setCursor(13, 3);
      lcd.print(F("0"));
      lcd.setCursor(14, 3);
      lcd.print(rtc_monat);
    } else {
      lcd.setCursor(13, 3);
      lcd.print(rtc_monat);
    }
  }
  if (LCDML.FUNC_close()) {
    // Der Bildschirmschoner geht in das Hauptmenü
    LCDML.MENU_goRoot();
  }
}

// *********************************************************************
// Menu - Zurück-Funktion
// *********************************************************************
void mFunc_back(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    LCDML.FUNC_goBackToMenu(1);  // Funktion verlassen und eine Ebene zurückgehen
  }
}

// *********************************************************************
// Displaybeleuchtung timeout
// *********************************************************************
void backlight_automatic_switch_OnOff()
// *********************************************************************
{
  static unsigned long last_ms = 0;
  const unsigned int bl_interval = 30000;                      // Hintergrundsbeleuchtung dauer bis ausgeschaltet (30s)
  if (g_LCDML_CONTROL_button_prev == LOW || ENCODER.read()) {  // wenn irgendein Taster gedrückt wurde geht die Beleuchtung an...
    last_ms = millis();                                        // ...und der Zähler setzt auf 0
    lcd.backlight();
  } else {
    if (millis() - last_ms >= bl_interval) {
      lcd.noBacklight();
    }
  }
}

// *********************************************************************
// Funktionen für die Sprachauswahl Deutsch
// *********************************************************************
void mFunc_sprache_de(uint8_t param)
// *********************************************************************
{
  sprache = 1;
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print(F("Deutsch ausgew\341hlt"));
  delay(400);
  {
    LCDML_UNUSED(param);
    LCDML.MENU_goRoot();
  }
}

// *********************************************************************
// Funktionen für die Sprachauswahl Englisch
// *********************************************************************
void mFunc_sprache_en(uint8_t param)
// *********************************************************************
{
  sprache = 2;
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print(F("English selected"));
  delay(400);
  {
    LCDML_UNUSED(param);
    LCDML.MENU_goRoot();
  }
}

// *********************************************************************
// Funktionen für die Sprachauswahl Kroatisch
// *********************************************************************
void mFunc_sprache_kr(uint8_t param)
// *********************************************************************
{
  sprache = 3;
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print(F("Hrvatski odabran"));
  delay(400);
  {
    LCDML_UNUSED(param);
    LCDML.MENU_goRoot();
  }
}

// *********************************************************************
// Geodaten Info
// *********************************************************************
void mFunc_geo_info(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    if (got_data_geo == true) {
      lcd.setCursor(0, 0);
      lcd.printstr(city);
      lcd.setCursor(0, 1);
      lcd.print(postal_code);
      lcd.setCursor(6, 1);
      lcd.print(country_code);
      lcd.setCursor(0, 2);
      lcd.print(longitude, 4);
      lcd.setCursor(0, 3);
      lcd.print(latitude, 4);
    } else if (got_data_geo == false && sprache == 1) {
      lcd.setCursor(4, 1);
      lcd.print(F("Keine WLAN"));
      lcd.setCursor(4, 2);
      lcd.print(F("Verbindung"));
    } else if (got_data_geo == false && sprache == 2) {
      lcd.setCursor(5, 1);
      lcd.print(F("No WiFi"));
      lcd.setCursor(4, 2);
      lcd.print(F("connection"));
    } else if (got_data_geo == false && sprache == 3) {
      lcd.setCursor(5, 1);
      lcd.print(F("WLAN nije"));
      lcd.setCursor(6, 2);
      lcd.print(F("povezan"));
    }
    LCDML.FUNC_setLoopInterval(100);
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    if (LCDML.BT_checkAny()) {
      LCDML.FUNC_goBackToMenu();
    }
  }
  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    //reserve
  }
}

// *********************************************************************
// Geodaten abrufen
// *********************************************************************
uint8_t timer_geo = 0;
unsigned long g_timer = 0;
// *********************************************************************
void mFunc_geo_reset(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    if (got_data_wlan == true) {
      Serial.write("GEO_GET");
      got_data_geo = false;
      timer_geo = 25;
    } else if (got_data_wlan == false && sprache == 1) {
      lcd.setCursor(4, 1);
      lcd.print(F("Keine WLAN"));
      lcd.setCursor(4, 2);
      lcd.print(F("Verbindung"));
      delay(800);
    } else if (got_data_wlan == false && sprache == 2) {
      lcd.setCursor(5, 1);
      lcd.print(F("No WiFi"));
      lcd.setCursor(4, 2);
      lcd.print(F("connection"));
      delay(800);
    } else if (got_data_wlan == false && sprache == 3) {
      lcd.setCursor(5, 1);
      lcd.print(F("WLAN nije"));
      lcd.setCursor(6, 2);
      lcd.print(F("povezan"));
      delay(800);
    }
    LCDML.FUNC_setLoopInterval(100);
    LCDML.TIMER_msReset(g_timer);
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    LCDML.SCREEN_resetTimer();
    if (LCDML.TIMER_ms(g_timer, 1000)) {
      timer_geo--;
      lcd.setCursor(9, 1);
      lcd.print(F("  "));
      lcd.setCursor(9, 1);
      lcd.print(timer_geo);
    }
    if (timer_geo <= 0) {
      LCDML.FUNC_goBackToMenu();
    }
  }

  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    //reserve
  }
}