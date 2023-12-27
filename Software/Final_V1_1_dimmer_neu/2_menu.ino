// *********************************************************************
// Eigene Symbole
// *********************************************************************

/*const uint8_t scroll_bar[5][8] = {
  { B10001, B10001, B10001, B10001, B10001, B10001, B10001, B10001 },  // Scrollbar oben
  { B11111, B11111, B10001, B10001, B10001, B10001, B10001, B10001 },  // Scroll Stand 1
  { B10001, B10001, B11111, B11111, B10001, B10001, B10001, B10001 },  // Scroll Stand 2
  { B10001, B10001, B10001, B10001, B11111, B11111, B10001, B10001 },  // Scroll Stand 3
  { B10001, B10001, B10001, B10001, B10001, B10001, B11111, B11111 }   // Scrollbar unten
}; */

byte sonneauf[8] = {0b00000,0b10101,0b01110,0b11011,0b01110,0b10101,0b00000,0b00000};     // Sonnenaufgang Symbol
byte sonneunter[8] = {0b00000,0b10101,0b01110,0b11011,0b11111,0b00000,0b00000,0b00000};   // Sonnenuntergang Symbol
byte glocke[8] = {0b00000,0b00100,0b01110,0b01110,0b11111,0b00000,0b00100,0b00000};       // Glocke Symbol
byte uhr[8] = {0b00000,0b01110,0b10101,0b10111,0b10001,0b01110,0b00000,0b00000};          // Uhr Symbol
byte wlan[8] = {0b00000,0b01110,0b10001,0b00100,0b01010,0b00000,0b00100,0b00000};         // Wlan Symbol
//byte check[8] = {0b00000,0b00001,0b00011,0b10110,0b11100,0b01000,0b00000,0b00000};        // Check Symbol

// *********************************************************************
// Hauptmenu
// ********************************************************************* 

// Menu hinzufügen        ID, Position, Positions-ID, Text                    Funktionen (Callbacks)

LCDML_add                 (0, LCDML_0, 1, "Betriebsart"                       , NULL);
LCDML_langDef             (0, EN, "Operating mode");
LCDML_langDef             (0, KR, "Nacin rada");
LCDML_add                 (1, LCDML_0_1, 1, "Automatikmodus"                  , mFunc_auto_mode_ein);
LCDML_langDef             (1, EN, "Automatic mode");
LCDML_langDef             (1, KR, "Automatski nacin");
LCDML_add                 (2, LCDML_0_1, 2, "Manueller Modus"                 , mFunc_auto_mode_aus);
LCDML_langDef             (2, EN, "Manual mode");
LCDML_langDef             (2, KR, "Rucni nacin");
LCDML_add                 (3, LCDML_0_1, 3, "Zur\365ck"                       , mFunc_back);
LCDML_langDef             (3, EN, "Back");
LCDML_langDef             (3, KR, "Nazad");
LCDML_add                 (4, LCDML_0, 2, "\5 und \6 einstellen"              , NULL);
LCDML_langDef             (4, EN, "Set \5 and \6");
LCDML_langDef             (4, KR, "Podesi \5 i \6");
LCDML_add                 (5, LCDML_0_2, 1, "Sim. einschalten"                , mFunc_simulation_ein);
LCDML_langDef             (5, EN, "Simulation on");
LCDML_langDef             (5, KR, "Upali simulaciju");
LCDML_add                 (6, LCDML_0_2, 2, "Sim. ausschalten"                , mFunc_simulation_aus);
LCDML_langDef             (6, EN, "Simulation off");
LCDML_langDef             (6, KR, "Ugasi simulaciju");
LCDML_add                 (7, LCDML_0_2, 3, "\5 Zeiteingabe"                  , mFunc_sa_einstellen);
LCDML_langDef             (7, EN, "Set \5 time");
LCDML_langDef             (7, KR, "Postavi \5 vrijeme");
LCDML_add                 (8, LCDML_0_2, 4, "\6 Zeiteingabe"                  , mFunc_su_einstellen);
LCDML_langDef             (8, EN, "Set \6 time");
LCDML_langDef             (8, KR, "Postavi \6 vrijeme");
LCDML_add                 (9, LCDML_0_2, 5, "Dauer"                           , mFunc_man_dauer_einstellen);
LCDML_langDef             (9, EN, "Duration");
LCDML_langDef             (9, KR, "Trajanje");
LCDML_add                 (10, LCDML_0_2, 6, "Zur\365ck"                      , mFunc_back);
LCDML_langDef             (10, EN, "Back");
LCDML_langDef             (10, KR, "Nazad");
LCDML_add                 (11, LCDML_0, 3, "\7 Lichtwecker"                   , NULL);
LCDML_langDef             (11, EN, "\7 Light alarm");
LCDML_langDef             (11, KR, "\7 Svijetlo budilica");
LCDML_add                 (12, LCDML_0_3, 1, "Startzeiteingabe"               , mFunc_lw_einstellen);
LCDML_langDef             (12, EN, "Set start time");
LCDML_langDef             (12, KR, "Pocetno vrijeme");
LCDML_add                 (13, LCDML_0_3, 2, "\7 ein"                         , mFunc_lw_ein);
LCDML_langDef             (13, EN, "\7 on");
LCDML_langDef             (13, KR, "\7 upaljen");
LCDML_add                 (14, LCDML_0_3, 3, "\7 aus"                         , mFunc_lw_aus);
LCDML_langDef             (14, EN, "\7 off");   
LCDML_langDef             (14, KR, "\7 ugasen");
LCDML_add                 (15, LCDML_0_3, 4, "Zur\365ck"                      , mFunc_back);
LCDML_langDef             (15, EN, "Back");
LCDML_langDef             (15, KR, "Nazad");
LCDML_add                 (16, LCDML_0, 5, "Einstellungen"                    , NULL);
LCDML_langDef             (16, EN, "Settings");
LCDML_langDef             (16, KR, "Postavke");
LCDML_add                 (17, LCDML_0_5, 1, "Sprache"                        , NULL);
LCDML_langDef             (17, EN, "Language");
LCDML_langDef             (17, KR, "Jezik");
LCDML_add                 (18, LCDML_0_5_1, 1, "Deutsch"                      , mFunc_sprache_de);
LCDML_langDef             (18, EN, "German");
LCDML_langDef             (18, KR, "Njemacki");
LCDML_add                 (19, LCDML_0_5_1, 2, "Englisch"                     , mFunc_sprache_en);
LCDML_langDef             (19, EN, "English");
LCDML_langDef             (19, KR, "Engleski");
LCDML_add                 (20, LCDML_0_5_1, 3, "Kroatisch"                    , mFunc_sprache_kr);
LCDML_langDef             (20, EN, "Croatian");
LCDML_langDef             (20, KR, "Hrvatski");
LCDML_add                 (21, LCDML_0_5_1, 4, "Zur\365ck"                    , mFunc_back);
LCDML_langDef             (21, EN, "Back");
LCDML_langDef             (21, KR, "Nazad");
LCDML_add                 (22, LCDML_0_5, 2, "Wlan"                           , NULL);
LCDML_langDef             (22, EN, "WiFi");
LCDML_langDef             (22, KR, "Bezicna veza");
LCDML_add                 (23, LCDML_0_5_2, 1, "Wlan reset"                   , mFunc_wlan_reset);
LCDML_langDef             (23, EN, "WiFi reset");
LCDML_langDef             (23, KR, "Ponisti postavke");
LCDML_add                 (24, LCDML_0_5_2, 2, "Wlan Info"                    , mFunc_wlan_info); 
LCDML_langDef             (24, EN, "WiFi info");
LCDML_langDef             (24, KR, "Wifi info");
LCDML_add                 (25, LCDML_0_5_2, 3, "Zur\365ck"                    , mFunc_back);
LCDML_langDef             (25, EN, "Back");
LCDML_langDef             (25, KR, "Nazad");
LCDML_add                 (26, LCDML_0_5, 3, "Datum und Uhrzeit"              , NULL);
LCDML_langDef             (26, EN, "Time and date");
LCDML_langDef             (26, KR, "Vrijeme i datum");
LCDML_add                 (27, LCDML_0_5_3, 1, "Zeit einstellen"              , mFunc_zeit_einstellen);
LCDML_langDef             (27, EN, "Set time");
LCDML_langDef             (27, KR, "Postavi vrijeme");
LCDML_add                 (28, LCDML_0_5_3, 2, "Datum einstellen"             , mFunc_datum_einstellen);
LCDML_langDef             (28, EN, "Set date");
LCDML_langDef             (28, KR, "Postavi datum");
LCDML_add                 (29, LCDML_0_5_3, 3, "Zur\365ck"                    , mFunc_back);
LCDML_langDef             (29, EN, "Back");
LCDML_langDef             (29, KR, "Nazad");
LCDML_add                 (30, LCDML_0_5, 4, "Dimmer"                         , NULL);
LCDML_langDef             (30, EN, "Dimmer");
LCDML_langDef             (30, KR, "Dimmer");
LCDML_add                 (31, LCDML_0_5_4, 1, "Dimmer einstellen"            , mFunc_set_dimmer);
LCDML_langDef             (31, EN, "Set dimmer");
LCDML_langDef             (31, KR, "Postavi dimmer");
LCDML_add                 (32, LCDML_0_5_4, 2, "Dimmer aus"                   , mFunc_licht_aus);
LCDML_langDef             (32, EN, "Dimmer off");
LCDML_langDef             (32, KR, "Ugasi dimmer");
LCDML_add                 (33, LCDML_0_5_4, 3, "Zur\365ck"                    , mFunc_back);
LCDML_langDef             (33, EN, "Back");
LCDML_langDef             (33, KR, "Nazad");
LCDML_add                 (34, LCDML_0_5, 5, "Zur\365ck"                      , mFunc_back);
LCDML_langDef             (34, EN, "Back");
LCDML_langDef             (34, KR, "Nazad");
LCDML_add                 (35, LCDML_0, 6, "Geoinformationen"                 , NULL);  
LCDML_langDef             (35, EN, "Geo information");
LCDML_langDef             (35, KR, "geo informacije");
LCDML_add                 (36, LCDML_0_6, 1, "Geodaten zeigen"                , mFunc_geo_info);
LCDML_langDef             (36, EN, "Show geo data");
LCDML_langDef             (36, KR, "Pokazi geo podatke");
LCDML_add                 (37, LCDML_0_6, 2, "Geodaten abrufen"               , mFunc_geo_reset);
LCDML_langDef             (37, EN, "Retrieve geodata");
LCDML_langDef             (37, KR, "Dohvati geopodatke");
LCDML_add                 (38, LCDML_0_6, 3, "Zur\365ck"                      , mFunc_back);
LCDML_langDef             (38, EN, "Back");
LCDML_langDef             (38, KR, "Nazad");
LCDML_add                 (39, LCDML_0, 7, "\365ber das Produkt"              , mFunc_information);
LCDML_langDef             (39, EN, "About the product");
LCDML_langDef             (39, KR, "O proizvodu");
LCDML_add                 (40, LCDML_0, 8, "Men\365 beenden"                  , mFunc_screensaver);
LCDML_langDef             (40, EN, "Close menu");
LCDML_langDef             (40, KR, "Zatvori izbornik");
//********************************************************************************************************************************************************************
LCDML_addAdvanced         (41, LCDML_0, 9, COND_hide, "mFunc_lichtwecker"     , mFunc_lichtwecker, 0,  _LCDML_TYPE_default);        //Ausgeblendet (nur Funktion callback)
LCDML_langDef             (41, EN, "dummy");
LCDML_langDef             (41, KR, "dummy");
LCDML_addAdvanced         (42, LCDML_0, 10, COND_hide, "mFunc_aufgang"        , mFunc_sonnenaufgang, 0,  _LCDML_TYPE_default);      //Ausgeblendet (nur Funktion callback)
LCDML_langDef             (42, EN, "dummy");
LCDML_langDef             (42, KR, "dummy");
LCDML_addAdvanced         (43, LCDML_0, 11, COND_hide, "mFunc_untergang"      , mFunc_sonnenuntergang, 0,  _LCDML_TYPE_default);    //Ausgeblendet (nur Funktion callback)
LCDML_langDef             (43, EN, "dummy");
LCDML_langDef             (43, KR, "dummy");

#define _LCDML_DISP_cnt 43                      // Dieser Wert muss derselbe sein wie der des letzten Menüelements
LCDML_createMenu(_LCDML_DISP_cnt);              // Menü erstellen Befehl

// *********************************************************************
// Sprachen definieren
// *********************************************************************

enum lang_types 
{
  LANG_DE = 0,  
  LANG_EN = 1,                                  // das letzte Element hat kein "," am Ende
  LANG_KR = 2
  // ...
};

lang_types g_lcdml_lang_select = LANG_DE;       // Festlegen der Standardsprache mit dem langen Namen

// Benutzerdefinierte Sprache mit kurzem Namen erstellen, nicht mit dem langen Namen
LCDML_createCustomLang(_LCDML_DISP_cnt, EN);    // EN = Englisch
LCDML_createCustomLang(_LCDML_DISP_cnt, KR);    // KR = Kroatisch

// *********************************************************************
// Setup LCD Menu
// *********************************************************************
void setup_menu() 
// *********************************************************************
{
  lcd.init();
  lcd.backlight();
  //lcd.createChar(0, (uint8_t*)scroll_bar[0]);             //*************************************************************//
  //lcd.createChar(1, (uint8_t*)scroll_bar[1]);             //                                                             //
  //lcd.createChar(2, (uint8_t*)scroll_bar[2]);             //                       Scrollbar Symbole                     //
  //lcd.createChar(3, (uint8_t*)scroll_bar[3]);             //                                                             //
  //lcd.createChar(4, (uint8_t*)scroll_bar[4]);             //*************************************************************//
  lcd.createChar(5, sonneauf);                              //*************************************************************//
  lcd.createChar(6, sonneunter);                            //                                                             //
  lcd.createChar(7, glocke);                                //                         Eigene Symbole                      //
  lcd.createChar(8, uhr);                                   //                                                             //
  lcd.createChar(9, wlan);                                  //                                                             //
  //lcd.createChar(10, check);                              //*************************************************************//                                                                                         
  LCDML_setup(_LCDML_DISP_cnt);                             //  Menü Bibliothek einrichten                                 
  //LCDML.MENU_enRollover();                                //  Dekommentieren, um die Menü-Rollover-Funktion zu aktivieren
  LCDML.SCREEN_enable(mFunc_screensaver, 20000);            //  Nach wie vielen Sekunden der Hauptbildschirm erscheint (mS)
}                                                           

// *********************************************************************
// Hauptmenu Loop
// *********************************************************************
void LCD_Menu() 
// *********************************************************************
{
  LCDML.loop();
  backlight_automatic_switch_OnOff();
}

// *********************************************************************
// Menüelement ausblenden
// *********************************************************************
boolean COND_hide(void)  
// *********************************************************************
{
  return false; 
}
