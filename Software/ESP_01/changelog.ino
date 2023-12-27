/*
TODO
-**Variablen zusammen in einen string fassen und nach dem Befehl zur Arduino senden. Dort wird aufgeteilt ** ENTFÄLLT

KNOWN BUGS
- Mein Wlan lässt den ESP nicht online. 

01.09.2022 - 01.10.2022
- NTP Server und WiFi Manager programiert

10.10.2022 
- Der Code komplett aufgeräumt und übersichtlicher gemacht. 
- Kommentare hinzugefügt
- Quellen hinzugefügt
- Angefangen der Abruf von Geodaten zu programieren. Funktioniert nicht

1 1.10.2022
- Endlich geschafft die Daten abzurufen
- Angefangen die Sonnenaufgang und Sonnenuntergang nach Geoposition Abruf zu programieren.
- Sonnenaufgangs/untergangszeit berechnung implementiert. Ist auch immer aktuell ;)
- Der Code is OK. Die Daten sind abgerufen, die Berechnungen sind auch ok, die Variablen sollen auch jetzt richtig aufgeteilt werden. 
  Leider ist mein Programmer irgendwie defekt. Manschmal funktioniert er gut aber meistens spinnt er. Habe gerade den neuen bestellt. Danach geht es weiter 
 
12.10.2022
- Sieht so aus, als funktioniert wieder alles wenn ich die Berechnungen auf atmega umgezogen habe. Das bleibt dann so. Ist auch besser da die Daten werden immer aktuell bleiben
- Wlan Info String programiert (zeigt SSID, IP, Gateway und DNS)
- funktionen WLAN_RST, GEO_SYNC, GEO_GET, TIME_SYNC und SHOW_WLAN_INFO programiert
- Code aufgeräumt

13.10.2022
- funktionen WLAN_RST, GEO_SYNC, GEO_GET, TIME_SYNC und SHOW_WLAN_INFO "umgebaut" damit die Daten Zeitlichgesteuert an ATMEGA gesendet sind
- Umgeswitcht auf Atmega und dort weiter gearbeitet

17.10.2022
- Der Fehler wieso den ESP in Exception(28) immer gegangen ist lag an Data parsing. Muss nach alternative suchen, wie nehme ich die Daten aus dem String raus
- Hab den TIME_SHOW funktion mit dem Sonnenaufgang/Untergang daten ergänzt. 
- Es geht weiter mit dem ATMEGA jetzt.


