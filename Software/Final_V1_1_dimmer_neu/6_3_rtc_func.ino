// *********************************************************************
// RTC Modul - Integer aktuallisierung Loop
// *********************************************************************
void rtc_aktualisierung()
// *********************************************************************
{
  rtc_stunde = RTC.getHour(h12Flag, pmFlag), DEC;
  rtc_minute = RTC.getMinute(), DEC;
  rtc_sekunde = RTC.getSecond(), DEC;
  rtc_datum = RTC.getDate(), DEC;
  rtc_monat = RTC.getMonth(century), DEC;
  rtc_jahr = RTC.getYear(), DEC;
}

// *********************************************************************
// RTC Modul - Zeit einstellen
// *********************************************************************
bool std_saved = false;
bool min_saved = false;
// *********************************************************************
void mFunc_zeit_einstellen(uint8_t param)
// *********************************************************************
{
  static int temp_std;      // Temporäre Variable wie die richtige werden ständig aktualisiert
  static int temp_min;      // Temporäre Variable wie die richtige werden ständig aktualisiert
  static int temp_sek;      // Temporäre Variable wie die richtige werden ständig aktualisiert
  if (LCDML.FUNC_setup())   // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    temp_std = RTC.getHour(h12Flag, pmFlag), DEC;
    temp_min = RTC.getMinute(), DEC;
    temp_sek = RTC.getSecond(), DEC;
    lcd.clear();
    lcd.setCursor(4, 1);
    lcd.print(F("[   :  :  ]"));
    lcd.setCursor(5, 1);
    lcd.write(0x7E);
    lcd.setCursor(6, 1);
    lcd.print(RTC.getHour(h12Flag, pmFlag), DEC);
    lcd.setCursor(9, 1);
    lcd.print(RTC.getMinute(), DEC);
    lcd.setCursor(12, 1);
    lcd.print(RTC.getSecond(), DEC);
    LCDML.FUNC_disableScreensaver();
    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    if (std_saved == false) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(7, 1);
        lcd.print(F(" "));
        lcd.setCursor(6, 1);
        temp_std++;
        lcd.setCursor(6, 1);
        lcd.print(temp_std);
      }
      if (std_saved == false) {
        if (LCDML.BT_checkEnter()) {
          std_saved = true;
          RTC.setHour(temp_std);
          lcd.setCursor(6, 1);
          lcd.print(F(" "));
          lcd.setCursor(5, 1);
          lcd.print(temp_std);
          lcd.setCursor(7, 1);
          lcd.print(F(":"));
          lcd.setCursor(8, 1);
          lcd.write(0x7E);
        }
      }
    } else if (std_saved == true && min_saved == false) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(10, 1);
        lcd.print(F(" "));
        temp_min++;
        lcd.setCursor(9, 1);
        lcd.print(temp_min);
      }
      if (std_saved == true && min_saved == false) {
        if (LCDML.BT_checkEnter()) {
          min_saved = true;
          RTC.setMinute(temp_min);
          lcd.setCursor(9, 1);
          lcd.print(F(" "));
          lcd.setCursor(8, 1);
          lcd.print(temp_min);
          lcd.setCursor(10, 1);
          lcd.print(F(":"));
          lcd.setCursor(11, 1);
          lcd.write(0x7E);
        }
      }
    } else if (std_saved == true && min_saved == true) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(13, 1);
        lcd.print(F(" "));
        temp_sek++;
        lcd.setCursor(12, 1);
        lcd.print(temp_sek);
      }
      if (std_saved == true && min_saved == true) {
        if (LCDML.BT_checkEnter()) {
          RTC.setSecond(temp_sek);
          LCDML.FUNC_goBackToMenu();
        }
      }
    }
    if (temp_std >= 24) {
      (temp_std = 0);
      lcd.setCursor(6, 1);
      lcd.print(F("0 "));
    } else if (temp_min >= 60) {
      (temp_min = 0);
      lcd.setCursor(9, 1);
      lcd.print(F("0 "));
    } else if (temp_sek >= 60) {
      (temp_sek = 0);
      lcd.setCursor(12, 1);
      lcd.print(F("0 "));
    }
  }
  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    lcd.clear();
    lcd.setCursor(9, 1);
    lcd.print(F("OK"));
    std_saved = false;
    min_saved = false;
    delay(400);
  }
}

// *********************************************************************
// RTC Modul - Datum einstellen
// *********************************************************************
bool tag_saved = false;
bool mon_saved = false;
// *********************************************************************
void mFunc_datum_einstellen(uint8_t param)
// *********************************************************************
{
  static int temp_tag;      // Temporäre Variable wie die richtige werden ständig aktualisiert
  static int temp_mon;      // Temporäre Variable wie die richtige werden ständig aktualisiert
  static int temp_jah;      // Temporäre Variable wie die richtige werden ständig aktualisiert
  if (LCDML.FUNC_setup())   // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    temp_tag = RTC.getDate(), DEC;
    temp_mon = RTC.getMonth(century), DEC;
    temp_jah = RTC.getYear(), DEC;
    lcd.clear();
    lcd.setCursor(4, 1);
    lcd.print(F("[   -  -20  ]"));
    lcd.setCursor(5, 1);
    lcd.write(0x7E);
    lcd.setCursor(6, 1);
    lcd.print(RTC.getDate(), DEC);
    lcd.setCursor(9, 1);
    lcd.print(RTC.getMonth(century), DEC);
    lcd.setCursor(14, 1);
    lcd.print(RTC.getYear(), DEC);
    LCDML.FUNC_disableScreensaver();
    LCDML.FUNC_setLoopInterval(100);
  }

  if (LCDML.FUNC_loop())    // ****** LOOP *********
  {
    if (tag_saved == false) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(7, 1);
        lcd.print(F(" "));
        lcd.setCursor(6, 1);
        temp_tag++;
        lcd.setCursor(6, 1);
        lcd.print(temp_tag);
      }
      if (tag_saved == false) {
        if (LCDML.BT_checkEnter()) {
          tag_saved = true;
          RTC.setDate(temp_tag);
          lcd.setCursor(6, 1);
          lcd.print(F(" "));
          lcd.setCursor(5, 1);
          lcd.print(temp_tag);
          lcd.setCursor(7, 1);
          lcd.print(F("-"));
          lcd.setCursor(8, 1);
          lcd.write(0x7E);
        }
      }
    } else if (tag_saved == true && mon_saved == false) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(10, 1);
        lcd.print(F(" "));
        temp_mon++;
        lcd.setCursor(9, 1);
        lcd.print(temp_mon);
      }
      if (tag_saved == true && mon_saved == false) {
        if (LCDML.BT_checkEnter()) {
          mon_saved = true;
          RTC.setMonth(temp_mon);
          lcd.setCursor(9, 1);
          lcd.print(F(" "));
          lcd.setCursor(8, 1);
          lcd.print(temp_mon);
          lcd.setCursor(10, 1);
          lcd.print(F("-"));
          lcd.setCursor(11, 1);
          lcd.write(0x7E);
        }
      }
    } else if (tag_saved == true && mon_saved == true) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.setCursor(12, 1);
        lcd.print(F("20"));
        lcd.setCursor(15, 1);
        lcd.print(F(" "));
        temp_jah++;
        lcd.setCursor(14, 1);
        lcd.print(temp_jah);
      }
      if (tag_saved == true && mon_saved == true) {
        if (LCDML.BT_checkEnter()) {
          RTC.setYear(temp_jah);
          temp_tag = 0;
          temp_mon = 0;
          temp_jah = 0;
          LCDML.FUNC_goBackToMenu();
        }
      }
    }
    if (temp_tag >= 32) {
      (temp_tag = 1);
      lcd.setCursor(6, 1);
      lcd.print(F("1 "));
    } else if (temp_mon >= 13) {
      (temp_mon = 1);
      lcd.setCursor(9, 1);
      lcd.print(F("1 "));
    } else if (temp_jah >= 41) {
      (temp_jah = 20);
      lcd.setCursor(14, 1);
      lcd.print(F("20"));
    }
  }
  if (LCDML.FUNC_close())   // ****** STABLE END *********
  {
    lcd.clear();
    lcd.setCursor(9, 1);
    lcd.print(F("OK"));
    tag_saved = false;
    mon_saved = false;
    delay(400);
  }
}