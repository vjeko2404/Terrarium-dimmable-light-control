/*

KNOWN BUGS:
- **Wifi_reset Timer funktioniert nicht ***erledigt
- **Lichtwecker spinnt manschmal - Die LCD Beleuchtung geht manschmal nicht an ***erledigt
- **dim variable 128-0 - soll 0-100 sein. Map funktion? ***erledigt
- **Strings vom ESP_WlanManager in screensaver angezeigt - Suche noch nach lösung (soll debug in WifiManager on false gesetzt)***erledigt
- **Triac Ausgang flackert noch ein wenig - Anderer Triac und Optotriac verwenden? MOC 3051 oder 3024, BT134?! (schon gekauft)*** erledigt
- **Alternative für STRINGS finden. Die Strings are etwa langsam und Speicherschwer. *****erledigt
- **Datum und Zeiteinstellung soll visuel optimiert noch *erledigt
- Die Daten-Parsing ist Scheiße. Machmal funktioniert gut und manchmal sind die Werte nicht bis zum ende übernommen. Hierfür brauche ich die Experten!***hab was gemacht...muss getestet werden
- 



-TO DO
- **Speicher finden. Brauche 3% !!!!!!!!!** erl
- **EEPROM Sprachauswahl funktioniert nicht wenn Standalone Atmega. Evtl. Adresse ändern ***erl
- **Prüfen ob ich die temp_variablen weg lassen kann (Zeiteinstellung)** erledigt (müssen bleiben da die arbeitsvariablen ständig aktualisiert sind)
- Beim einstellungen auch (wert--); implementieren wenn überhaupt genug speicher bleibt
- **Dimmvorgang nach sa_start, su_start und dauer programieren - Noch keine Ahnung wie das geht**erl 
- ***Lichtwecker startzeit in EEPROM speichern***erl
- ***DS3231 Bibliothek instalieren*****erl
- ***Input möglichkeit mit lcdmenulib2 finden*****erl
- **json untersuchen und daten mit ESP empfangen // https://sunrise-sunset.org/api  **erledigt (einen Sonnenberechnung Bibliothek benutzt)
- ***Alle Hauptmenu NULL funktionen durch funktionen ersetzen. ***erl
- ***Globale Variable in separate File versetzen *****erl
- ***Sprache INTEGER in EEPROM speichern ****erl
- ***Lichtwecker startzeit programieren **erl
- ***Strings weg lassen bzw. into mehrere Char splitten! Wichtig! Speichersparend! ***erl



09.09.2022 -> 27.09.2022
- Zerocross und Dimmer programiert
- ESP Wlan Manager programiert
- NTP Zeiterfassung programiert
- SoftwareSerial programiert
  * SoftwareSerial NeoSW gefunden und implementiert
- Serialverbindung zwischen ESP und Atmega eingestellt

28.09.2022
-ESP Send-daten mit formatierter Zeit ergänzt

29.09.2022
-Parsing in Strings programiert

30.09.2022
-LCDMenu Bibliothek getestet: War OK aber viel RAM gefressen
-lcdmenulib2 gefunden und heruntergeladen

01.10.2022.
-Hauptmenu mit lcdmenulib2 aufgebaut
-auf EN und KR übersetzt
-Screensaver programiert (Hauptanzeige)
-über das Gerät programiert
-Übersetzungswechsel programiert
-

02.10.2022
-Der Code aufgeräumt (nicht alles)
-Lichtwecker menufunktion programiert
-Set Dimmer menufunktion programiert


03.10.2022
-LCD Hintergrundsbeleuchtung timout programiert
-WLAN Reset mit countdown programiert
-Triac-Ausgang Flackern reduziert
-Lichtwecker optimiert damit auch den LCD backlight blinkt

04.10.2022
-RTC DS3231 installiert
-Angefangen mit manuell Zeiteinstellung Funktion

05.10.2022
-manuelle Zeiteinstellung Funktion gemacht
-manuelle Datumeinstellung Funktion gemacht
-Tabs organisiert
-Sprache auswähl in EEPROM speicher 

06.10.2022
-manuelle Zeiteinstellungsfunktion optimiert und auf den letzten Stand gebracht
-manuelle Datumeinstellungsfunktion optimiert und auf den letzten Stand gebracht
-Variablen zuweisung von esp und rtc programiert
-Speicher optimiert mit entfernung von Strings (10% Speicher gespart)
-rtc variablen einstellung programiert

07.10.2022
-Lichtwecker Zeiteinstellung programiert
-Lichtwecker Ein Aus Variablen programier
-Lichtwecker Variablen mit EEPROM speicher programiert
-Nochmal alles umsortiert und umorganisiert (übersichtlicher gemacht)
-Lichtwecker fertig programiert

08.10.2022

-Glocke Symbol implementiert und in Bildschirmschoner programiert
-Automatic und manuell modus eeprom speicher programiert
-Schnapps getrunken und arbeit aufgegeben - Soll noch menu bearbeiten mit auto/manuell auswahl...muss überlegen.

09.10.2022
-Menu überbearbeitet, modus hinzugefügt, simulation ein/aus hinzugefügt, sonnen-auf/unt startzeit hinzugefügt
-Funktion sonnenaufgang start und ende mit eepromspeicher funktion programiert 
-ALLE Variablen überprüft und umorganisiert - viele globalen in lokalen umgestellt. 6% Speicherplatz gewonnen!
-Lichtwecker automatic von manual modus getrennt. Modus wird in Variable gespeichert -> Variable wird in EEPROM gespeichert 
-Screensaver umprogramiert damit der Alarm, Sonnenuntergang und Sonnenaufgang Zeit angezeig wird wenn die genannte Funkktionen eingeschaltet sind. Ansonsten wird nichts angezeigt.
-Korrigiert, dass der Lichtwecker, wenn Enter-Taste bestätigt wird, nicht in Hauptmenu sonder in Screensaver geht.
-Screensaver umprogramiert so das entweder ESP oder RTC Zeit angezeigt wird (je nach dem arbeitsmodus)
-Screensaver umgebaut, Symbole implementiert, schöner gemacht...
-Unnötige befehle aus dem Zeit/Datumeinstellung entfernt
-Kommentare aufgeräum, ergänzt und aktualisiert

10.10.2022

- Custom Symbole hinzugefügt
- Srollbar deaktiviert. 3,5 % mehr Speicherplatz. Da LCD nicht mehr als 8 benutzerdefinierte Symbole speichern kann, müsste diese sowieso verschwinden.


14.10.2022
- Also, der Speicher ist definitiv voll. Muss sehen, dass ich welche Funktionen auf ESP übertragen bekomme ansonsten sind wir am Arsch.

17.10.2022
- hab die Sonnen-Berechnungen erfolgreich auf ESP versetzt. Hab wenig Speicher gewonnen. Hoffentlich reicht das jetzt aus.
- Wlan Info Funktion programiert. Wird SSID und IP Adresse angezeigt.
- Wlan Reset Funktion repariert (Variablen sollten global sein (mein Fehler))
- Programiert Zeitsynchronisierung beim Automatischer Betrieb
- Hauptmenu umsortiert und eigene Symbole hinzugefügt
- Wenn kein WLAN verfügbar, keine Automatischer Betrieb möglich - Fehlermeldung mit 3 Sprachen programiert
- Wenn kein WLAN verfügbar, keine WLAN Info möglich - Fehlermeldung mit 3 Sprachen programiert
- Set dimmer in Einstellungen verschoben
- Geo Info programiert
- Alle funktionen nochmal überprüft, könnte keine Fehler finden.
- Eine Version ohne Kroatische Sprache gemacht.
- Nicht benutzte Befehle aus dem Bibliotheken gelöscht (1% Speicher gespart)
- WLAN Symbol hinzugefügt. Wenn Wlan aktiv ist wird vorne angezeigt.
- ALLES auser dimmvorgang beim Sonnenaufgang und Sonnenuntergangszeit fertig programiert. Jetzt schon wieder habe ich den Speicherproblem da der Sketch nimmt 95% von der Speicher weg.
  Ich muss noch einmal durch den ganzen Code durchgehen und sehen ob ich noch irgendwo speicher finden kann.
- Serial.begin(19200) auskommentiert und 3% Speicher gewonnen. 

18.10.2022
- Angefangen automatische dimmfunktion zu programieren.

19.10.2022
- Geschafft den Automatische, Zeitgesteuerte Simulation zu programieren. Muss den Code aufräumen und andere funktionen überprüfen da ich die dimm Variable in float geändert habe
- Programiert das wenn Simulation-Einstellung aktiv ist, die Sonnen-Vorgänge sind ausgeschaltet. 
- Korrigiert das Fehler, wenn den Sonnenvorgang aktiv ist, alle andere funktionen waren tod.
------------------------------------------------------------------------------------------------------------------------
- Stand heute sind alle funktionen programiert und i.O. Der Code muss aufgeräumt werden und für die Abgabe formatiert -
------------------------------------------------------------------------------------------------------------------------

22.10.2022
- Nochmal alle Variablen geprüft. Viele in byte geändert. 
- Eine Fehler mit "Automatic mode" endeckt. Der Zeit stellt sich nur einmal ein. Dannach wurden die Variablen nicht mehr dynamisch.
  So wird sich auch die Sonnenberechnung nicht aktualisieren! Das muss abgeändert werden.
- Fehler korrigiert
- ESP auf Hardware-Serial umgewandelt. BAUD 115200 fehlerfrei

23.10.2022
- Geodaten update funktion geschrieben
- Hauptmenu erweitert mit Geodaten Zeigen und Abrufen
- Dimmer eingeschränkt -> Sonnenaufgang beginnt mit ca 88 VAC (dim = 104), endet mit 230VAC (dim = 20). Die LED lampen funktioniert komisch wenn AC <= 80V
- Mit dem Dimmer rumexperimentiert...mit MOC3021 ist ein bisschen besser aber flacker kann nicht 100% verhindert werden.

- Eine Triac-Dimmer Bibliothek gefunden. Funktioniert herrvoragend! Keine Flackern mehr und dimmt sehr sauber! Offensichtlich is der Timer viel besser als TimerOne

24.10.2022
- Simulation für den neuen Dimmer angepast. 
- Simulation Vorgang LCD Anzeige hinzugefügt
- Simulation Vorgang - Zeit geblieben noch programiert
- Simulation Vorgang - Übersetzungen programiert
- EEPROM Fehler mit Auto/Manual korrigiert
- 28 Bytes von Speicher geblieben :)

25.10.2022.
-EEPROM Funktionen nochmal geprüft und optimiert. 

24.12.2022.
- Auto mode wird immer ausgeschalten, wenn das Gerät neu gestartet ist. 
- Speichern von Arbeitsmodus in EEPROM entfernt.
- korrigiert das Fehler wo sich Hintergrundbeleuchtung manschmal nich auschalten möchte
- Lichtwecker bearbeitet - Die lampe dimmt jetzt durch 3 minuten (fest) hoch

27.12.2022
- Lichtwecker timeout hinzugefügt. Nach 5 minuten wird die Lampe aus gehen und die Funktion wird gestoppt.
- Wenn Wlan-reset betätig wird, Arbeitsmodus wird auf Manuell gesetzt.

*/

