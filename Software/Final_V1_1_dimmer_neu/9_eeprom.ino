// *********************************************************************
// Beim einschalten - Daten aus EEPROM auslesen
// *********************************************************************
void get_eeprom()
// *********************************************************************
{
  EEPROM.get(0, sprache);               //Daten aus EEPROM-Adresse 0 auslesen und als Integer speichern
  EEPROM.get(2, lw_on);                 //Daten aus EEPROM-Adresse 2 auslesen und als Byte speichern
  EEPROM.get(4, lwstart_stunde);        //Daten aus EEPROM-Adresse 4 auslesen und als Integer speichern
  EEPROM.get(6, lwstart_minute);        //Daten aus EEPROM-Adresse 6 auslesen und als Integer speichern
  EEPROM.get(8, lwstart_sekunde);       //Daten aus EEPROM-Adresse 8 auslesen und als Integer speichern
  //EEPROM.get(10, auto_mode);            //Daten aus EEPROM-Adresse 10 auslesen und als Integer speichern
  EEPROM.get(12, simulation);           //Daten aus EEPROM-Adresse 12 auslesen und als Integer speichern
  EEPROM.get(14, sa_start_std);         //Daten aus EEPROM-Adresse 14 auslesen und als Integer speichern
  EEPROM.get(16, sa_start_min);         //Daten aus EEPROM-Adresse 16 auslesen und als Integer speichern
  EEPROM.get(18, su_start_std);         //Daten aus EEPROM-Adresse 18 auslesen und als Integer speichern
  EEPROM.get(20, su_start_min);         //Daten aus EEPROM-Adresse 20 auslesen und als Integer speichern 
  EEPROM.get(22, man_dauer);            //Daten aus EEPROM-Adresse 22 auslesen und als Integer speichern 
}


void erster_start()
{
  EEPROM.write(0, 1);                 // Sprache einstellen 1=DE, 2=EN, 3=KR
  EEPROM.write(2, 0);                 // Lichtwecker Aus
  EEPROM.write(4, 7);                 // Lichtwecker Stunde
  EEPROM.write(6, 0);                 // Lichtwecker Minute
  EEPROM.write(8, 0);                 // Lichtwecker Sekunde
  EEPROM.write(10, 0);                // Automode ausschalten
  EEPROM.write(12, 1);                // Simulation einschalten
  EEPROM.write(14, 7);                // Sonnenaufgang Stunde
  EEPROM.write(16, 0);                // Sonnenaufgang Minute
  EEPROM.write(18, 20);               // Sonnenuntergang Stunde
  EEPROM.write(20, 0);                // Sonnenuntergang Minute
  EEPROM.write(22, 5.0);              // Manuelle Dauern einstellen
}

