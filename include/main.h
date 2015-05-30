#ifndef MAIN_H
#define MAIN_H

/*
This file contains the essential data for the sketch.
Lots of declarations, definitions and functions are here.

Ten plik zawiera potrzebne dane dla skeczu. Jest tutaj wiele
deklaracji, definicji i funkcji.
*/

/*
In this section I'm going to define constants which are mainly
the pins that I'll be using later. In order to save memory, the
byte variable type will be used. Notice that there are pairs of
sensors as well (for example, for different rooms or having
a different usage) and henceforth, two variables are going to
be used.

W tej czesci pliku zdefiniuje stale, przede wszystkim piny,
z ktorych bede korzystal pozniej. W celu oszczednosci pamieci
uzyje zmiennych typu byte. Prosze zauwazyc, ze w projekcie
uzywane sa pary sensorow (na przyklad dla roznych pokoi badz
majace rozne przeznaczenia) i dlatego zostana wykorzystane
2 zmienne.
*/

/*
The variable of the pin which is connected to the sound sensor.

Zmienna dla pinu, do ktorego podlaczony jest sensor dzwieku.
*/
const byte soundPin0 = x;
const byte soundPin1 = y;

/*
The variable of the pin which is connected to the light sensor.

Zmienna dla pinu, do ktorego podlaczony jest sensor swiatla.
*/
const byte lightPin0 = x;
const byte lightPin1 = y;

/*
The variables of the pins which are connected to the distance sensor.
trigPin - the transmitter on the module.
echoPin - the receiver on the module.

Zmienne dla pinow, do ktorych podlaczony jest sensor odleglosci.
trigPin - nadajnik na sensorze.
echoPin - odbiornik na sensorze.
*/
const byte trigPin0 = x;
const byte echoPin0 = x;
const byte trigPin1 = y;
const byte echoPin1 = y;

/*
The variable of the pin which is connected to the temperature and
humidity sensor.

Zmienna dla pinu, do ktorego podlaczony jest sensor temperatury
oraz wilgotnosci.
*/
const byte dht11Pin0 = x;
const byte dht11Pin1 = y;

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

/*
The variables of the pins which are connected to the LCD screen.

Zmienne dla pinow, do ktorych podlaczony jest wyswietlacz LCD.
*/
const byte lcdSCLKPin = x;
const byte lcdSNPin = x;
const byte lcdDCPin = x;
const byte lcdRSTPin = x;
const byte lcdSCEPin = x;

/*
The variable of the pin which is connected to the buzzer.

Zmienna dla pinu, do ktorego podlaczony jest generator dzwieku.
*/
const byte buzzerPin = x;

#endif // MAIN_H