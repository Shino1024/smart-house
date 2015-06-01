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
The variables of the pins which is connected to the sound sensors.
Zmienna dla pinow, do ktorych podlaczone sa sensory dzwieku.
*/
const byte soundPin0 = x;
const byte soundPin1 = y;

/*
The variables of the pins which are connected to the light sensor.
Zmienna dla pinow, do ktorego podlaczone sa sensory swiatla.
*/
const byte lightPin0 = x;
const byte lightPin1 = y;

/*
The variables of the pins which are connected to the distance sensors.
trigPin - the transmitter on the module.
echoPin - the receiver on the module.
Zmienne dla pinow, do ktorych podlaczone sa sensory odleglosci.
trigPin - nadajnik na sensorze.
echoPin - odbiornik na sensorze.
*/
const byte trigPin0 = x;
const byte echoPin0 = x;
const byte trigPin1 = y;
const byte echoPin1 = y;

/*
The variables of the pins which are connected to the temperature and
humidity sensor.
Zmienna dla pinow, do ktorych podlaczone sa sensory temperatury
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

/*
Variables for later usage.
Zmienne do uzytku pozniej.
*/

/*
The array of arrays of the characters which define the graphical
ASCII signs of the pressed buttons on the membrane keyboard.
Tablica tablic znakow, ktore definiuja graficzne znaki ASCII dla
poszczegolnych przyciskow na klawiaturze membranowej.
*/
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

/*
The keypad variable which is the Keypad class object. It'll be
used for accepting input from the membrane keyboard. The key
variable will be used for holding the value of the last pressed key.
Zmienna keypad, ktora jest obiektem klasy Keypad. Zostanie uzyta
do odebrania danych z klawiatury membranowej. Zmienna key bedzie
przechowywala wartosc ostatniego nacisnietego przycisku.
*/
Keypad keypad = Keypad(makeKeymap(keys), keypadRows, keypadCols, 4, 4);
char key;

/*
The variables for the humidity and temperature.
Zmienne wilgotnosci i temperatury.
*/
short temperature0;
short temperature1;
short humidity0;
short humidity1;

/*
The byte variables for the light and sound sensors.
Zmienne byte dla sensorow swiatla i dzwieku.
*/
byte light0;
byte light1;
byte sound0;
byte sound1;

/*
The variables for the proximity sensors.
Zmienne dla sensorow zblizeniowych.
*/
short distance0;
short distance0;

/*
Here I will define some helpful functions that I'll use further
in the sketch.
Zdefiniuje tutaj kilka przydatnych funkcji, ktorych bede uzywal
pozniej w skeczu.
*/

/*
void buzz() - produces a sound. Used when the button on the membrane
keypad is pressed.
void buzz() - wydaje dzwiek. Wywolywana za kazdym razem, gdy przycisk
na klawiaturze membranowej jest nacisniety.
*/
void buzz() {

/*
High state on the buzzer for a short while.
Stan wysoki na buzzerze na krotka chwile.
*/
	digitalWrite(buzzerPin, HIGH);
	delay(2);
	digitalWrite(buzzerPin, LOW);
}

/*
double fahrenheit(double) - converts the temperature from Celsius to
Fahrenheit degrees.
double fahrenheit(double) - konwertuje tempreature ze stopni Celsjusza
do stopni Fahrenheita.
*/
double fahrenheit(double celsius) {
	return 1.8 * celsius + 32;
}

#endif // MAIN_H
