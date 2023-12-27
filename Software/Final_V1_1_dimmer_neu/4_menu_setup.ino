// *********************************************************************
// LCD Clear funktion
// *********************************************************************
void lcdml_menu_clear()
// *********************************************************************
{
  lcd.clear();
  lcd.setCursor(0, 0);
}

// *********************************************************************
// LCD und Hauptmenu einstellungen
// *********************************************************************
void lcdml_menu_display()
// *********************************************************************
{
  if (LCDML.DISP_checkMenuUpdate()) {                           // Inhalt aktualisieren
    LCDML.DISP_clear();                                         // Menü löschen
    char content_text[_LCDML_DISP_cols];                        // den Inhaltstext eines jeden Menüelements speichern
    LCDMenuLib2_menu *tmp;                                      // Menü-Element-Objekt

    uint8_t i = LCDML.MENU_getScroll();                         // einige Grenzwerte
    uint8_t maxi = _LCDML_DISP_rows + i;
    uint8_t n = 0;

    if ((tmp = LCDML.MENU_getDisplayedObj()) != NULL) {         // Loop zur Anzeige von Zeilen und Sprachen
      do {
        if (tmp->checkCondition()) {
          if (tmp->checkType_menu() == true) {
            switch (sprache) {

              case 1:
                LCDML_getContent(content_text, tmp->getID());
                lcd.setCursor(1, n);
                lcd.print(content_text);
                EEPROM.put(0, 1);
                break;

              case 2:
                LCDML_getCustomContent(EN, content_text, tmp->getID());
                lcd.setCursor(1, n);
                lcd.print(content_text);
                EEPROM.write(0, 2);
                break;

              case 3:
                LCDML_getCustomContent(KR, content_text, tmp->getID());
                lcd.setCursor(1, n);
                lcd.print(content_text);
                EEPROM.write(0, 3);
                break;
            }
            if (tmp->checkType_dynParam()) {
              tmp->callback(n);
            }
          }
          i++;
          n++;
        }
      } while (((tmp = tmp->getSibling(1)) != NULL) && (i < maxi));
    }
  }
  if (LCDML.DISP_checkMenuCursorUpdate()) {
    uint8_t n_max = (LCDML.MENU_getChilds() >= _LCDML_DISP_rows) ? _LCDML_DISP_rows : (LCDML.MENU_getChilds());
    uint8_t scrollbar_min = 0;
    uint8_t scrollbar_max = LCDML.MENU_getChilds();
    uint8_t scrollbar_cur_pos = LCDML.MENU_getCursorPosAbs();
    uint8_t scroll_pos = ((1. * n_max * _LCDML_DISP_rows) / (scrollbar_max - 1) * scrollbar_cur_pos);
    for (uint8_t n = 0; n < n_max; n++) {
      lcd.setCursor(0, n);
      if (n == LCDML.MENU_getCursorPos()) {
        lcd.write(_LCDML_DISP_cfg_cursor);
      } else {
        lcd.write(' ');
      }
      // Scrollbar
      if (_LCDML_DISP_cfg_scrollbar == 1) {
        if (scrollbar_max > n_max) {
          lcd.setCursor((_LCDML_DISP_cols - 1), n);
          lcd.write((uint8_t)0);
        } else {
          lcd.setCursor((_LCDML_DISP_cols - 1), n);
          lcd.print(' ');
        }
      }
    }
    // Anzeige Scrollbar
    if (_LCDML_DISP_cfg_scrollbar == 1) {
      if (scrollbar_max > n_max) {
        if (scrollbar_cur_pos == scrollbar_min) {
          lcd.setCursor((_LCDML_DISP_cols - 1), 0);
          lcd.write((uint8_t)1);
        } else if (scrollbar_cur_pos == (scrollbar_max - 1)) {
          lcd.setCursor((_LCDML_DISP_cols - 1), (n_max - 1));
          lcd.write((uint8_t)4);
        } else {
          lcd.setCursor((_LCDML_DISP_cols - 1), scroll_pos / n_max);
          lcd.write((uint8_t)(scroll_pos % n_max) + 1);
        }
      }
    }
  }
}