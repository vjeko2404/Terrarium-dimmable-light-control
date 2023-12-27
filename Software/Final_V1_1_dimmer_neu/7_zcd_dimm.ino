// *********************************************************************
// Dimmer bibliothek einstellen
// *********************************************************************
void dimmer_setup()
// *********************************************************************
{
  TriacDimmer::begin();
}

// *********************************************************************
// Dimmer Loop
// *********************************************************************
void dimmer_loop()
// *********************************************************************
{
  TriacDimmer::setBrightness(triac, dim);
}

// *********************************************************************
// Dimmer einstellen Funktion
// *********************************************************************
void mFunc_set_dimmer(uint8_t param)
// *********************************************************************
{
  byte counter;
  counter = dim * 100;
  if (LCDML.FUNC_setup())  // ****** SETUP *********
  {
    LCDML_UNUSED(param);
    lcd.setCursor(1, 1);
    lcd.print(F("Dimmer:"));
    dim = 0.00;
    lcd.setCursor(9, 1);
    lcd.print(F("MIN"));
    LCDML.FUNC_disableScreensaver();
  }
  if (LCDML.FUNC_loop())  // ****** LOOP *********
  {
    if (LCDML.BT_checkAny()) {
      if (LCDML.BT_checkRight() || LCDML.BT_checkDown()) {
        LCDML.BT_resetRight();
        LCDML.BT_resetDown();
        lcd.clear();
        lcd.setCursor(1, 1);
        lcd.print(F("Dimmer:"));
        dim += 0.01;
        lcd.setCursor(9, 1);
        lcd.print(counter);
      } else if (LCDML.BT_checkLeft() || LCDML.BT_checkUp()) {
        LCDML.BT_resetLeft();
        LCDML.BT_resetUp();
        lcd.clear();
        lcd.setCursor(1, 1);
        lcd.print(F("Dimmer:"));
        dim -= 0.01;
        lcd.setCursor(9, 1);
        lcd.print(counter);
      }
    }
    if (dim >= 1.0) {
      (dim = 1.0);
      lcd.setCursor(9, 1);
      lcd.print(F("MAX  "));
    } else if (dim <= 0.0) {
      (dim = 0.0);
      lcd.setCursor(9, 1);
      lcd.print(F("MIN  "));
    }
    if (LCDML.BT_checkEnter()) {
      LCDML.FUNC_goBackToMenu();
    }
  }
  if (LCDML.FUNC_close())  // ****** STABLE END *********
  {
    // reserve
  }
}

// *********************************************************************
// Dimmer-Licht aus
// *********************************************************************
void mFunc_licht_aus(uint8_t param)
// *********************************************************************
{
  dim = 0.00;
  lcd.clear();
  lcd.setCursor(9, 1);
  lcd.print(F("OK"));
  delay(400);
  LCDML.FUNC_goBackToMenu();
}