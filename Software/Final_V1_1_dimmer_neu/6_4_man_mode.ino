// *********************************************************************
// Sonnenaufgang Startzeit einstellung
// *********************************************************************
bool sa_std_saved = false;
// *********************************************************************
void mFunc_sa_einstellen(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    simulation = 0;
    auto_mode = 0;
    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.print(F("[   :  ]"));
    lcd.setCursor(7, 1);
    lcd.write(0x7E);
    lcd.setCursor(8, 1);
    lcd.print(sa_start_std);
    lcd.setCursor(11, 1);
    lcd.print(sa_start_min);
    LCDML.FUNC_disableScreensaver();
    LCDML.FUNC_setLoopInterval(100);
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    if (sa_std_saved == false) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(9, 1);
        lcd.print(F(" "));
        lcd.setCursor(8, 1);
        sa_start_std++;
        lcd.setCursor(8, 1);
        lcd.print(sa_start_std);
      }
      if (sa_std_saved == false) {
        if (LCDML.BT_checkEnter()) {
          sa_std_saved = true;
          EEPROM.write(14, sa_start_std);
          lcd.setCursor(8, 1);
          lcd.print(F(" "));
          lcd.setCursor(7, 1);
          lcd.print(sa_start_std);
          lcd.setCursor(9, 1);
          lcd.print(F(":"));
          lcd.setCursor(10, 1);
          lcd.write(0x7E);
        }
      }
    } else if (sa_std_saved == true) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(12, 1);
        lcd.print(F(" "));
        sa_start_min++;
        lcd.setCursor(11, 1);
        lcd.print(sa_start_min);
      }
      if (LCDML.BT_checkEnter()) {
        EEPROM.write(16, sa_start_min);
        LCDML.FUNC_goBackToMenu();
      }
    }

    if (sa_start_std >= 24) {
      (sa_start_std = 0);
      lcd.setCursor(8, 1);
      lcd.print(F("0 "));
    } else if (sa_start_min >= 60) {
      (sa_start_min = 0);
      lcd.setCursor(11, 1);
      lcd.print(F("0 "));
    }
  }
  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    simulation = 1;
    sa_std_saved = false;
    lcd.clear();
    lcd.setCursor(9, 1);
    lcd.print(F("OK"));
    delay(400);
  }
}

// *********************************************************************
// Sonnenuntergang Startzeit einstellung
// *********************************************************************
bool su_std_saved = false;
// *********************************************************************
void mFunc_su_einstellen(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    simulation = 0;
    auto_mode = 0;
    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.print(F("[   :  ]"));
    lcd.setCursor(7, 1);
    lcd.write(0x7E);
    lcd.setCursor(8, 1);
    lcd.print(su_start_std);
    lcd.setCursor(11, 1);
    lcd.print(su_start_min);
    LCDML.FUNC_disableScreensaver();
    LCDML.FUNC_setLoopInterval(100);
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    if (su_std_saved == false) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(9, 1);
        lcd.print(F(" "));
        lcd.setCursor(8, 1);
        su_start_std++;
        lcd.setCursor(8, 1);
        lcd.print(su_start_std);
      }
      if (su_std_saved == false) {
        if (LCDML.BT_checkEnter()) {
          su_std_saved = true;
          EEPROM.write(18, su_start_std);
          lcd.setCursor(8, 1);
          lcd.print(F(" "));
          lcd.setCursor(7, 1);
          lcd.print(su_start_std);
          lcd.setCursor(9, 1);
          lcd.print(F(":"));
          lcd.setCursor(10, 1);
          lcd.write(0x7E);
        }
      }
    } else if (su_std_saved == true) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(12, 1);
        lcd.print(F(" "));
        su_start_min++;
        lcd.setCursor(11, 1);
        lcd.print(su_start_min);
      }
      if (LCDML.BT_checkEnter()) {
        EEPROM.write(20, su_start_min);
        LCDML.FUNC_goBackToMenu();
      }
    }
    if (su_start_std >= 24) {
      (su_start_std = 0);
      lcd.setCursor(8, 1);
      lcd.print(F("0 "));
    } else if (su_start_min >= 60) {
      (su_start_min = 0);
      lcd.setCursor(11, 1);
      lcd.print(F("0 "));
    }
  }
  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    simulation = 1;
    su_std_saved = false;
    lcd.clear();
    lcd.setCursor(9, 1);
    lcd.print(F("OK"));
    delay(400);
  }
}

// *********************************************************************
// Sonnenuntergang/Sonnenaufgang Dauer einstellung (max 60 min)
// *********************************************************************
void mFunc_man_dauer_einstellen(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    simulation = 0;
    lcd.clear();
    lcd.setCursor(7, 1);
    lcd.print(F("[   ]"));
    lcd.setCursor(8, 1);
    lcd.write(0x7E);
    lcd.setCursor(9, 1);
    lcd.print(man_dauer);
    LCDML.FUNC_disableScreensaver();
    LCDML.FUNC_setLoopInterval(100);
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
      LCDML.BT_resetRight();
      LCDML.BT_resetDown();
      lcd.setCursor(9, 1);
      man_dauer++;
      lcd.setCursor(9, 1);
      lcd.print(man_dauer);
    }
    if (LCDML.BT_checkEnter()) {
      EEPROM.write(22, man_dauer);
      LCDML.FUNC_goBackToMenu();
    }
    if (man_dauer >= 61) {
      man_dauer = 1;
      lcd.setCursor(9, 1);
      lcd.print(F("1 "));
    } else if (man_dauer <= 9) {
      lcd.setCursor(10, 1);
      lcd.print(F(" "));
    }
  }
  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    simulation = 1;
    lcd.clear();
    lcd.setCursor(9, 1);
    lcd.print(F("OK"));
    delay(400);
  }
}