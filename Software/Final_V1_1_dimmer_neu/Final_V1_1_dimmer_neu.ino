// *********************************************************************
// Bibliotheken laden
// *********************************************************************
//#include <NeoSWSerial.h>      // https://github.com/SlashDevin/NeoSWSerial -> DEBUG
#include <LiquidCrystal_I2C.h>  // https://github.com/johnrickman/LiquidCrystal_I2C
#include <LCDMenuLib2.h>        // https://github.com/Jomelo/LCDMenuLib2
#include <Encoder.h>            // https://github.com/PaulStoffregen/Encoder
#include <EEPROM.h>             // https://docs.arduino.cc/learn/built-in-libraries/eeprom
#include <DS3231.h>             // https://github.com/NorthernWidget/DS3231
#include <TriacDimmer.h>        // https://github.com/AJMansfield/TriacDimmer


// *********************************************************************
// LCDML LCD-Display Einstellungen
// *********************************************************************
#define _LCDML_DISP_cols 20
#define _LCDML_DISP_rows 4
#define _LCDML_DISP_cfg_cursor 0x7E  // Pfeil Symbol
#define _LCDML_DISP_cfg_scrollbar 0  // Scrollbar aktivieren 1=ein 0=aus - Kann 3,5% Programspeicher sparen!

// *********************************************************************
// Bibliothek-Einstellungen
// *********************************************************************

void lcdml_menu_display();
void lcdml_menu_clear();
void lcdml_menu_control();

unsigned char sync = 8;       // Nulldurchgang Pin
unsigned char triac = 9;      // AC Triac Pin

//NeoSWSerial ESP(7, 2);                                                                                                   // Software Serielle Pins für DEBUG definieren
DS3231 RTC;                                                                                                                // RTC Bibliothek start
LiquidCrystal_I2C lcd(0x27, _LCDML_DISP_cols, _LCDML_DISP_rows);                                                           // LCD Bibliothek start
LCDMenuLib2_menu LCDML_0(255, 0, 0, NULL, NULL);                                                                           // Stammmenüelement (nicht ändern)
LCDMenuLib2 LCDML(LCDML_0, _LCDML_DISP_rows, _LCDML_DISP_cols, lcdml_menu_display, lcdml_menu_clear, lcdml_menu_control);  // LCD-Menu Bibliothek start

// *********************************************************************
// Setup
// *********************************************************************
void setup()
// *********************************************************************
{
  //erster_start(); // <<<<<<<<<<<-------MUSS EINMAL AUSGEFÜHRT WERDEN !! EEPROM EINSTELLEN

  //ESP.begin(19200);                 // DEBUG !!!

  Serial.begin(115200);               // für interne ESP Strings lesen
  dimmer_setup();                     // Einrichtung in der Registerkarte zero_cross
  setup_menu();                       // Einrichtung in der Registerkarte LCDML_03011_i2c_display_20x4
  setup_rtc_variablen();              // Daten aus RTC in Varieblen speichern
  get_eeprom();                       // Daten aus EEPRROM auslesen und in Variablen speichern
}

// *********************************************************************
// Loop
// *********************************************************************
void loop()
// *********************************************************************
{
  LCD_Menu();                               // Hauptmenüschleife
  ESP_Receive_loop();                       // Daten vom ESP empfangen und in Variablen speichern
  dimmer_loop();                            // Dimmerwert lesen und Triac ansteuern
  rtc_aktualisierung();                     // Aktualisier die Variablen mit RTC Daten
  lichtwecker_zeitvergleich();              // Lichtwecker Zeitvergleicher 
  sonnen_zeitvergleicher();                 // Simulation Zeitvergleicher
  automatic_mode_loop();                    // 6_5_auto_mode
}