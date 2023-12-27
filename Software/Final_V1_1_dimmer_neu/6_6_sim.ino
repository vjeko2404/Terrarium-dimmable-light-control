// *********************************************************************
// Simulation Zeitvergleicher
// *********************************************************************
void sonnen_zeitvergleicher()
// *********************************************************************
{

  if ((simulation == 1) && (sa_start_std == rtc_stunde) && (sa_start_min == rtc_minute) && (rtc_sekunde == 0)) {
    dim = 0.23;
    LCDML.OTHER_jumpToID(42);

  } else if ((simulation == 1) && (su_start_std == rtc_stunde) && (su_start_min == rtc_minute) && (rtc_sekunde == 0)) {
    if (dim >= 0.24) {
      LCDML.OTHER_jumpToID(43);
    }
  }
}

// *********************************************************************
// Simulation Sonnenaufgang
// *********************************************************************
uint8_t timer_s = 0;
unsigned long s_timer = 0;
// *********************************************************************
void mFunc_sonnenaufgang(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    float sa_mathe;
    dim = 0.24;
    sa_mathe = 0.54 / (man_dauer * 60.0);
    inkrement = sa_mathe / 10.0;
    timer_s = man_dauer;
    if (sprache == 1) {
      lcd.setCursor(3, 1);
      lcd.print(F("Sonnenaufgang"));
      lcd.setCursor(2, 2);
      lcd.print(F("Noch    Minuten"));
      lcd.setCursor(7, 2);
      lcd.print(timer_s);
    } else if (sprache == 2) {
      lcd.setCursor(6, 1);
      lcd.print(F("Sunrise"));
      lcd.setCursor(5, 2);
      lcd.print(F("minutes left"));
      lcd.setCursor(2, 2);
      lcd.print(timer_s);
    } else if (sprache == 3) {
      lcd.setCursor(3, 1);
      lcd.print(F("Izlazak sunca"));
      lcd.setCursor(1, 2);
      lcd.print(F("Jos    min. ostalo"));
      lcd.setCursor(5, 2);
      lcd.print(timer_s);
    }
    LCDML.FUNC_setLoopInterval(100);
    LCDML.TIMER_msReset(s_timer);
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    LCDML.SCREEN_resetTimer();
    dim += inkrement;
    if (LCDML.TIMER_ms(s_timer, 60000)) {
      timer_s--;
      if (sprache == 1) {
        lcd.setCursor(7, 2);
        lcd.print(timer_s);
      } else if (sprache == 2) {
        lcd.setCursor(2, 2);
        lcd.print(timer_s);
      } else if (sprache == 3) {
        lcd.setCursor(5, 2);
        lcd.print(timer_s);
      }
    }
  }
  if ((dim >= 0.80) || (LCDML.BT_checkEnter())) {
    LCDML.OTHER_jumpToID(40);
  }
  //if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    // Reserve
  }
}

// *********************************************************************
// Simulation Sonnenuntergang
// *********************************************************************
void mFunc_sonnenuntergang(uint8_t param)
// *********************************************************************
{
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    float sa_mathe;
    sa_mathe = 0.54 / (man_dauer * 60.0);
    inkrement = sa_mathe / 10.0;
    timer_s = man_dauer;
    if (sprache == 1) {
      lcd.setCursor(1, 1);
      lcd.print(F("Sonnenuntergang"));
      lcd.setCursor(2, 2);
      lcd.print(F("Noch    Minuten"));
      lcd.setCursor(7, 2);
      lcd.print(timer_s);
    } else if (sprache == 2) {
      lcd.setCursor(7, 1);
      lcd.print(F("Sunset"));
      lcd.setCursor(5, 2);
      lcd.print(F("minutes left"));
      lcd.setCursor(2, 2);
      lcd.print(timer_s);
    } else if (sprache == 3) {
      lcd.setCursor(3, 1);
      lcd.print(F("Zalazak sunca"));
      lcd.setCursor(1, 2);
      lcd.print(F("Jos    min. ostalo"));
      lcd.setCursor(5, 2);
      lcd.print(timer_s);
    }
    LCDML.FUNC_setLoopInterval(100);
    LCDML.TIMER_msReset(s_timer);
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    LCDML.SCREEN_resetTimer();
    dim -= inkrement;
    if (LCDML.TIMER_ms(s_timer, 60000)) {
      timer_s--;
      if (sprache == 1) {
        lcd.setCursor(7, 2);
        lcd.print(timer_s);
      } else if (sprache == 2) {
        lcd.setCursor(2, 2);
        lcd.print(timer_s);
      } else if (sprache == 3) {
        lcd.setCursor(5, 2);
        lcd.print(timer_s);
      }
    }
  }
  if ((dim <= 0.24) || (LCDML.BT_checkEnter())) {
    LCDML.OTHER_jumpToID(40);
    dim = 0.0;
  }
  //if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    // reserve
  }
}

// *********************************************************************
// Simulation ein
// *********************************************************************
void mFunc_simulation_ein(uint8_t param)
// *********************************************************************
{
  simulation = 1;
  EEPROM.write(12, 1);
  lcd.clear();
  lcd.setCursor(9, 1);
  lcd.print(F("OK"));
  delay(400);
  LCDML.FUNC_goBackToMenu();
}

// *********************************************************************
// Simulation aus
// *********************************************************************
void mFunc_simulation_aus(uint8_t param)
// *********************************************************************
{
  simulation = 0;
  EEPROM.write(12, 0);
  lcd.clear();
  lcd.setCursor(9, 1);
  lcd.print(F("OK"));
  delay(400);
  LCDML.FUNC_goBackToMenu();
}