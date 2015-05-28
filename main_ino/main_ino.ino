/*
[ENGLISH]
  The sketch for Arduino Mega 2560 board.
  It is the core file of the whole project.
  The whole following code is thoroughly documented in order to assure
  the reader's convenience.
  
[POLSKI]
  Skecz dla plytki Arduino Mega 2560.
  Ten plik jest rdzeniem calego projektu.
  Caly ponizszy kod jest udokumentowany, by zapewnic jego
  czytelnosc.
*/

/*
Includes:
Keypad.h - for the membrane keyboard.
SD.h - for the SD card reader.
PCD8544.h - for the LCD screen.
dht11.h - for the temperature and humidity sensor.

Biblioteki:
Keypad.h - dla klawiatury membranowej.
SD.h - dla czytnika kart SD.
PCD8544.h - dla ekranu LCD.
dht11.h - dla sensora temperatury i wilgotnosci.
*/

#include <Keypad.h>
#include <SD.h>
#include <PCD8544.h>
#include <dht11.h>

/*
In this section I'm going to define constants which are mainly
the pins that I'll be using later. In order to save memory, the
byte variable type will be used.

W tej czesci programu zdefiniuje stale, przede wszystkim piny,
z ktorych bede korzystal pozniej. W celu oszczednosci pamieci
uzyje zmiennych typu byte.
*/

/*
The variable of the pin which is connected to the sound sensor.

Zmienna dla pinu, do ktorego podlaczony jest sensor dzwieku.
*/
const byte soundPin = x;

/*
The variable of the pin which is connected to the light sensor.

Zmienna dla pinu, do ktorego podlaczony jest sensor swiatla.
*/
const byte lightPin = x;

/*
The variables of the pins which are connected to the distance sensor.
trigPin - the transmitter on the module.
echoPin - the receiver on the module.

Zmienne dla pinow, do ktorych podlaczony jest sensor odleglosci.
trigPin - nadajnik na sensorze.
echoPin - odbiornik na sensorze.
*/
const byte trigPin = x;
const byte echoPin = x;

/*
The variable of the pin which is connected to the temperature and
humidity sensor.

Zmienna dla pinu, do ktorego podlaczony jest sensor temperatury
oraz wilgotnosci.
*/
const byte dht11Pin = x;

/*
The variables of the pins which are connected to the LEDs.
LED0...4Pin - LEDs indexed from 0 to 4 (totalling 5).

Zmienne dla pinow, do ktorych podlaczone sa swiatelka LED.
LED0...4Pin - swiatelka LED, indeksowane od 0 do 4 (razem 5).
*/
const byte LED0Pin = x;
const byte LED1Pin = x;
const byte LED2Pin = x;
const byte LED3Pin = x;
const byte LED4Pin = x;

/*
The variables of the pins which are connected to the membrane keypad.
They're defined as 2 arrays as it is the only correct input for the
constructor of the Keypad class.

Zmienne dla pinow, do ktorych podlaczona jest klawiatura membranowa.
Sa zdefiniowane jako 2 tablice, gdyz jest to wymagane przez
konstruktor klasy Keypad.
*/
const byte keypadRows = {x, x, x, x};
const byte keypadCols = {x, x, x, x};
