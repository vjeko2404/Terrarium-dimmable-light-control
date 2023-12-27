// *********************************************************************
// Drehgeber Einstellungen
// *********************************************************************
#define encoder_A_pin 6       // ATMEGA328P Pinnummer 6 (Drehgeber rechts)
#define encoder_B_pin 5       // ATMEGA328P Pinnummer 5 (Drehgeber links)
#define encoder_button_pin 4  // ATMEGA328P Pinnummer 4 (Drehgeber-Taste)

#define g_LCDML_CONTROL_button_long_press 800   // ms
#define g_LCDML_CONTROL_button_short_press 120  // ms

Encoder ENCODER(encoder_A_pin, encoder_B_pin);

unsigned long g_LCDML_CONTROL_button_press_time = millis();
bool g_LCDML_CONTROL_button_prev = HIGH;

// *********************************************************************
// Drehgeber loop
// *********************************************************************
void lcdml_menu_control(void)
// *********************************************************************
{
  // Variable für diese Funktion deklarieren
  int32_t g_LCDML_CONTROL_Encoder_position = ENCODER.read();
  bool g_LCDML_button = digitalRead(encoder_button_pin);

  if (LCDML.BT_setup()) {
    // Init-Pins, Pullups aktivieren
    pinMode(encoder_A_pin, INPUT);
    pinMode(encoder_B_pin, INPUT);
    pinMode(encoder_button_pin, INPUT);
  }
  // Prüfung, ob der Encoder in Richtung A gedreht wird
  if (g_LCDML_CONTROL_Encoder_position <= -3) {
    // Prüfung, ob die Taste gedrückt und der Encoder gedreht wird
    // die Taste ist low-aktiv
    if (g_LCDML_button == LOW) {
      // Taste wird gedrückt
      LCDML.BT_left();
      // Reset-Taste drücken Zeit für nächste Erkennung
      g_LCDML_CONTROL_button_prev = HIGH;
    } else {
      LCDML.BT_down();
    }
    // Init-Encoder für den nächsten Schritt
    ENCODER.write(g_LCDML_CONTROL_Encoder_position + 4);
  }
  // Prüfung, ob der Encoder in Richtung B gedreht wird
  else if (g_LCDML_CONTROL_Encoder_position >= 3) {
    // Prüfung, ob die Taste gedrückt und der Encoder gedreht wird
    // die Taste ist low-aktiv
    if (g_LCDML_button == LOW) {
      // Taste wird gedrückt
      LCDML.BT_right();
      // Reset-Taste drücken Zeit für nächste Erkennung
      g_LCDML_CONTROL_button_prev = HIGH;
    } else {
      LCDML.BT_up();
    }
    // Init-Encoder für den nächsten Schritt
    ENCODER.write(g_LCDML_CONTROL_Encoder_position - 4);
  } else {
    // prüfen, ob die Taste kurz oder lange gedrückt wurde
    //  fallende Flanke, Taste gedrückt, keine Aktion
    if (g_LCDML_button == LOW && g_LCDML_CONTROL_button_prev == HIGH) {
      g_LCDML_CONTROL_button_prev = LOW;
      g_LCDML_CONTROL_button_press_time = millis();
    }
    // steigende Flanke, Taste nicht gedrückt, prüfen, wie lange sie gedrückt war
    else if (g_LCDML_button == HIGH && g_LCDML_CONTROL_button_prev == LOW) {
      g_LCDML_CONTROL_button_prev = HIGH;
      // prüfen, wie lange die Taste gedrückt wurde, und erkennen, ob sie lange oder kurz gedrückt wurde
      // Prüfung der Lage der langer Tastendruck
      if ((millis() - g_LCDML_CONTROL_button_press_time) >= g_LCDML_CONTROL_button_long_press) {
        // Langer Tastendruck erkannt
        LCDML.BT_quit();
      }
      // Prüfung der Lage der kurzer Tastendruck
      else if ((millis() - g_LCDML_CONTROL_button_press_time) >= g_LCDML_CONTROL_button_short_press) {
        // Kurzer Tastendruck erkannt
        LCDML.BT_enter();
      }
    }
    // reserve
    else {
      // reserver
    }
  }
}