
// *********************************************************************
// Lichtwecker ein
// *********************************************************************
void mFunc_lw_ein(uint8_t param)
// *********************************************************************
{
  lw_on = 1;
  EEPROM.write(2, lw_on);
  lcd.clear();
  lcd.setCursor(9, 1);
  lcd.print(F("OK"));
  delay(400);
  LCDML.FUNC_goBackToMenu();
}

// *********************************************************************
// Lichtwecker aus
// *********************************************************************
void mFunc_lw_aus(uint8_t param)
// *********************************************************************
{
  lw_on = 0;
  EEPROM.write(2, lw_on);
  lcd.clear();
  lcd.setCursor(9, 1);
  lcd.print(F("OK"));
  delay(400);
  LCDML.FUNC_goBackToMenu();
}

// *********************************************************************
// Lichtwecker Vorgang
// *********************************************************************
//byte lw_active;
unsigned int alarm_timeout = 0;
// *********************************************************************
void mFunc_lichtwecker(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    //lw_active = 1;
    alarm_timeout = 0;
    lcd.clear();
    byte alarm_dauer = 3;  //Einstellung wie lange wird der Lichtalarm dauern. Minuteneingabe (3min Standard)
    LCDML_UNUSED(param);
    float alarm_mathe;
    dim = 0.24;
    alarm_mathe = 0.54 / (alarm_dauer * 60.0);
    inkrement = alarm_mathe / 10.0;
    if (sprache == 1) {
      lcd.setCursor(1, 1);
      lcd.print(F("Lichtwecker aktiv"));
      lcd.setCursor(5, 2);
      lcd.print(F("Aufwecken"));
    } else if (sprache == 2) {
      lcd.setCursor(1, 1);
      lcd.print(F("Light alarm aktive"));
      lcd.setCursor(6, 2);
      lcd.print(F("Wake up"));
    } else if (sprache == 3) {
      lcd.setCursor(2, 1);
      lcd.print(F("Svjetlobudilica"));
      lcd.setCursor(5, 2);
      lcd.print(F("Probudi se"));
    }
    LCDML.FUNC_setLoopInterval(100);
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    LCDML.SCREEN_resetTimer();
    dim += inkrement;
    alarm_timeout ++;
  }

  if ((alarm_timeout >= 3000) || (LCDML.BT_checkEnter())) {
    dim = 0.0;
    //lw_active = 0;
    LCDML.OTHER_jumpToID(40);
  }
  //if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    // Reserve
  }
}

// *********************************************************************
// Lichtwecker Startzeit einstellung
// *********************************************************************
bool lw_std_saved = false;
bool lw_min_saved = false;
// *********************************************************************
void mFunc_lw_einstellen(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    lcd.clear();
    lcd.setCursor(4, 1);
    lcd.print(F("[   :  :  ]"));
    lcd.setCursor(5, 1);
    lcd.write(0x7E);
    lcd.setCursor(6, 1);
    lcd.print(lwstart_stunde);
    lcd.setCursor(9, 1);
    lcd.print(lwstart_minute);
    lcd.setCursor(12, 1);
    lcd.print(lwstart_sekunde);
    LCDML.FUNC_disableScreensaver();
    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    if (lw_std_saved == false) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(7, 1);
        lcd.print(F(" "));
        lcd.setCursor(6, 1);
        lwstart_stunde++;
        lcd.setCursor(6, 1);
        lcd.print(lwstart_stunde);
      }
      if (lw_std_saved == false) {
        if (LCDML.BT_checkEnter()) {
          lw_std_saved = true;
          EEPROM.write(4, lwstart_stunde);
          lcd.setCursor(6, 1);
          lcd.print(F(" "));
          lcd.setCursor(5, 1);
          lcd.print(lwstart_stunde);
          lcd.setCursor(7, 1);
          lcd.print(F(":"));
          lcd.setCursor(8, 1);
          lcd.write(0x7E);
        }
      }
    } else if (lw_std_saved == true && lw_min_saved == false) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(10, 1);
        lcd.print(F(" "));
        lwstart_minute++;
        lcd.setCursor(9, 1);
        lcd.print(lwstart_minute);
      }
      if (lw_std_saved == true && lw_min_saved == false) {
        if (LCDML.BT_checkEnter()) {
          lw_min_saved = true;
          EEPROM.write(6, lwstart_minute);
          lcd.setCursor(9, 1);
          lcd.print(F(" "));
          lcd.setCursor(8, 1);
          lcd.print(lwstart_minute);
          lcd.setCursor(10, 1);
          lcd.print(F(":"));
          lcd.setCursor(11, 1);
          lcd.write(0x7E);
        }
      }
    } else if (lw_std_saved == true && lw_min_saved == true) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(13, 1);
        lcd.print(F(" "));
        lwstart_sekunde++;
        lcd.setCursor(12, 1);
        lcd.print(lwstart_sekunde);
      }
      if (lw_std_saved == true && lw_min_saved == true) {
        if (LCDML.BT_checkEnter()) {
          EEPROM.write(8, lwstart_sekunde);
          LCDML.FUNC_goBackToMenu();
        }
      }
    }
    if (lwstart_stunde >= 24) {
      (lwstart_stunde = 0);
      lcd.setCursor(6, 1);
      lcd.print(F("0 "));
    } else if (lwstart_minute >= 60) {
      (lwstart_minute = 0);
      lcd.setCursor(9, 1);
      lcd.print(F("0 "));
    } else if (lwstart_sekunde >= 60) {
      (lwstart_sekunde = 0);
      lcd.setCursor(12, 1);
      lcd.print(F("0 "));
    }
  }
  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    lw_std_saved = false;
    lw_min_saved = false;
    lcd.clear();
    lcd.setCursor(9, 1);
    lcd.print(F("OK"));
    delay(400);
  }
}

// *********************************************************************
// Lichtwecker Zeitvergleicher
// *********************************************************************
void lichtwecker_zeitvergleich()
// *********************************************************************
{
  if ((lw_on == 1) && (lwstart_stunde == rtc_stunde) && (lwstart_minute == rtc_minute) && (lwstart_sekunde == rtc_sekunde))
    LCDML.OTHER_jumpToID(41);
}