// *********************************************************************
// Bibliotheken laden
// *********************************************************************
#include <SolarCalculator.h>      // https://github.com/jpb10/SolarCalculator
#include <ArduinoJson.h>          // https://github.com/bblanchon/ArduinoJson
#include <WiFiManager.h>          // https://github.com/tzapu/WiFiManager
#include <ESP8266WiFi.h>          // https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi
#include <ESP8266WebServer.h>     // https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer
#include <DNSServer.h>            // https://github.com/esp8266/Arduino/tree/master/libraries/DNSServer
#include <NTPClient.h>            // https://github.com/arduino-libraries/NTPClient
#include <WiFiUdp.h>              // https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi
#include <ESP8266HTTPClient.h>    // https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient
#include <time.h>                 // Standard C Bibliothek

IPAddress dns1(8, 8, 8, 8);  //Google dns
IPAddress dns2(8, 8, 4, 4);  //Alternate dns

// *********************************************************************
// Setup Allgemein
// *********************************************************************
void setup()
// *********************************************************************
{
  Serial.begin(115200);                        
  delay(100);
  setup_wlan_manager();
  setup_geodaten();
  setup_ntpdaten();
}

// *********************************************************************
// Setup Wlan-Manager
// *********************************************************************
bool wm_nonblocking = false;                  // change to true to use non blocking
WiFiManager wm;                               // global wm instance
WiFiManagerParameter custom_field;            // global param ( for non blocking w params )
// *********************************************************************
void setup_wlan_manager()
// *********************************************************************
{
  wm.setClass("invert");                                        //**********************************************//
  WiFi.begin();                                                 //                                              //
  delay(3000);                                                  //                   Startet den                //
  WiFi.mode(WIFI_STA);                                          //                   Wifi-Manager               //
  delay(1000);                                                  //                                              //
  WiFiManager wifiManager;                                      //**********************************************//
  wifiManager.setDebugOutput(false);                            // Debug-Ausgabe des Wifi-Managers ausschalten
  wifiManager.autoConnect("Terra-Lichtcontrol", "12345678");    // Standart Wlan Einstellung - SSID und Kennwort                               
}

// *********************************************************************
// Loop
// *********************************************************************
void loop()
// *********************************************************************
{
  showTime();
  atmega_read();
  Wifi_manager_reset();
  reconnect();
  geodaten();
  geo_reconnect();
  sonnendaten_berechnen();
  sonnendaten();
  time_sync();
  geo_sync();
  wlan_status();
  //parsing();
}