// *********************************************************************
// Lichtwecker Startzeit
// *********************************************************************
static byte lw_on;                        //Lichtwecker 0=aus 1=in (in EEPROM gespeichert)

static byte lwstart_stunde;               //Lichtwecker Startzeit Stunde (in EEPROM gespeichert)
static byte lwstart_minute;               //Lichtwecker Startzeit Minute (in EEPROM gespeichert)
static byte lwstart_sekunde;              //Lichtwecker Startzeit Sekunde (in EEPROM gespeichert)

// *********************************************************************
// RTC Variablen
// *********************************************************************

static byte rtc_jahr;                     //RTC Jahr Einstellungsvariable
static byte rtc_monat;                    //RTC Monat Einstellungsvariable
static byte rtc_datum;                    //RTC Tag Einstellungsvariable
static byte rtc_stunde;                   //RTC Stunde Einstellungsvariable
static byte rtc_minute;                   //RTC Minute Einstellungsvariable
static byte rtc_sekunde;                  //RTC Sekunde Einstellungsvariable

bool century = false;                     
bool h12Flag;
bool pmFlag;

// *********************************************************************
// ESP Daten Variablen
// *********************************************************************

const byte numChars = 60;                  // Max Zeichenbytes für ESP Array

bool esp_data = false;                     // Boolean, um anzuzeigen, ob die ESP-Daten empfangen wurden
bool got_data_wlan = false;
bool got_data_geo = false;

char ESP_Data[numChars];                   // ein Array zum Speichern der empfangenen Daten

static byte esp_jahr;                      //ESP Jahr Variable
static byte esp_monat;                     //ESP Monat Variable
static byte esp_datum;                     //ESP Datum Variable
static byte esp_stunde;                    //ESP Stunde Variable
static byte esp_minute;                    //ESP Minute Variable
static byte esp_sekunde;                   //ESP Sekunde Variable

char ssid[21];
char ip_address[16];

static char country_code[3] = {0};
static char city[20] = {0};
static char postal_code[6] = {0};

static float longitude;
static float latitude;
static int timezone_gmt_offset;

// *********************************************************************
// Dimmer Variable
// *********************************************************************

float dim = 0.00;                               // Dimmstufe 0.00 - 1.00

// *********************************************************************
// Sprache Variable - Wird aus EEPROM ausgelesen 1=DE 2=EN 3=KR
// *********************************************************************

static byte sprache = 1;

// *********************************************************************
// Automatic modus 0=aus 1=ein 
// *********************************************************************

static byte auto_mode;                        

// *********************************************************************
// Sonnenunter-aufgang  0=aus 1=ein 
// *********************************************************************

static byte simulation;
bool simulation_on = false;

// *********************************************************************
// Sonnenunter-aufgang  Manuell Variablen
// *********************************************************************

static byte sa_start_std;
static byte sa_start_min;
static byte su_start_std;
static byte su_start_min;

static byte auto_sa_start_std;
static byte auto_sa_start_min;
static byte auto_su_start_std;
static byte auto_su_start_min;

byte man_dauer;
float inkrement;

// *********************************************************************
// RTC Daten in Integer speichern
// *********************************************************************
void setup_rtc_variablen() 
// *********************************************************************
{
rtc_stunde  = RTC.getHour(h12Flag, pmFlag), DEC;
rtc_minute  = RTC.getMinute(), DEC;
rtc_sekunde = RTC.getSecond(), DEC;
rtc_datum   = RTC.getDate(), DEC;
rtc_monat   = RTC.getMonth(century), DEC;
rtc_jahr    = RTC.getYear(), DEC;
auto_mode   = 0;
}
