// *********************************************************************
// NTP Zeit Variablen
// *********************************************************************

static int datum;
static int monat;
static int jahr;

static int stunde;
static int minute;
static int sekunde;

// *********************************************************************
// Sonnen Unter/Aufgang Variablen
// *********************************************************************

String str_sonnenaufgang; 
String str_mittagssonne;
String str_sonnenuntergang;

double transit; 
double sunrise; 
double sunset;

//char sonnenaufgang;
//char sonnenuntergang;
//char mittagssonne;

char* sonnenaufgang;
char* mittagssonne;
char* sonnenuntergang;

//static int sonnenaufgang_stunde;
//static int sonnenaufgang_minute;
//static int mittagssonne_stunde;
//static int mittagssonne_minute;
//static int sonnenuntergang_stunde;
//static int sonnenuntergang_minute;

// *********************************************************************
// Stringspeicher für die Befehlen von Atmega
// *********************************************************************

String atmega;

// *********************************************************************
// Geolokalisierung - Abstract_API
// *********************************************************************

bool startup;

String geo_response;
String Key = "bb60f7a47fa04b18a3c3b34626e567de";

String ip_address;     
String city;                 
String country_code;

double longitude;
double latitude;

int postal_code;
int timezone_gmt_offset;
