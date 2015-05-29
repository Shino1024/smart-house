/*
The sketch for Arduino Mega 2560 board.
It is the core file of the whole project.
The whole following code is thoroughly documented in order to assure
the reader's convenience.

Skecz dla plytki Arduino Mega 2560.
Ten plik jest rdzeniem calego projektu.
Caly ponizszy kod jest udokumentowany, by zapewnic jego
czytelnosc.
*/

/*
Includes:
Keypad.h - for the membrane keyboard.
PCD8544.h - for the LCD screen.
dht11.h - for the temperature and humidity sensor.
main.h - the file which contanins the essential data and declarations.

Biblioteki:
Keypad.h - dla klawiatury membranowej.
PCD8544.h - dla ekranu LCD.
dht11.h - dla sensora temperatury i wilgotnosci.
main.h - plik zawierajacy potrzebne dane i deklaracje.
*/

#include "../include/keypad/Keypad.h"
#include "../include/pcd8544/PCD8544.h"
#include "../include/dht11/dht11.h"
#include "../include/main.h"

/*
Here I will define some helpful functions that I'll use farther
in the code. The declarations and 
