// *********************************************************************
// Wlan reset Funktion
// *********************************************************************
uint8_t timer_wlan = 0;
unsigned long w_timer = 0;
// *********************************************************************
void mFunc_wlan_reset(uint8_t param)
// *********************************************************************
{

  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    Serial.write("WLAN_RST");
    timer_wlan = 20;
    LCDML.FUNC_setLoopInterval(100);

    LCDML.TIMER_msReset(w_timer);
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    LCDML.SCREEN_resetTimer();
    if (LCDML.TIMER_ms(w_timer, 1000)) {
      timer_wlan--;
      lcd.setCursor(9, 1);
      lcd.print(F("  "));
      lcd.setCursor(9, 1);
      lcd.print(timer_wlan);
    }
    if (timer_wlan <= 0) {
      LCDML.FUNC_goBackToMenu();
    }
  }

  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    got_data_wlan = false;
    got_data_geo = false;
    auto_mode = 0;
  }
}

// *********************************************************************
// Wlan Info
// *********************************************************************
void mFunc_wlan_info(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    if (got_data_wlan == true) {
      lcd.setCursor(0, 0);
      lcd.print(F("SSID:"));
      lcd.setCursor(0, 1);
      lcd.print(ssid);
      lcd.setCursor(0, 3);
      lcd.print(F("IP:"));
      lcd.setCursor(4, 3);
      lcd.print(ip_address);
    } else if (got_data_wlan == false && sprache == 1) {
      lcd.setCursor(4, 1);
      lcd.print(F("Keine WLAN"));
      lcd.setCursor(4, 2);
      lcd.print(F("Verbindung"));
    } else if (got_data_wlan == false && sprache == 2) {
      lcd.setCursor(5, 1);
      lcd.print(F("No WiFi"));
      lcd.setCursor(4, 2);
      lcd.print(F("connection"));
    } else if (got_data_wlan == false && sprache == 3) {
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