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
dht11.h - for the temperature and humidity sensor.
main.h - the file which contanins the essential data and declarations.
Biblioteki:
Keypad.h - dla klawiatury membranowej.
dht11.h - dla sensora temperatury i wilgotnosci.
main.h - plik zawierajacy potrzebne dane i deklaracje.
*/

#include <Keypad.h>
#include <dht11.h>

/*
The functions and variables needed for a proper LCD screen configuration.
Funkcje i zmienne, potrzebne do prawidlowego skonfigurowania ekranu LCD.
*/

/*
A few configuration definitions.
Kilka definicji konfiguracyjnych.
*/
#define LCD_C     LOW
#define LCD_D     HIGH
#define LCD_X     84
#define LCD_Y     48
#define LCD_CMD   0

/*
The variables of the pins which are connected to the LCD screen.
Zmienne dla pinow, do ktorych podlaczony jest wyswietlacz LCD.
*/
const byte PIN_SCLK = 36;
const byte PIN_SDIN = 37;
const byte PIN_DC = 38;
const byte PIN_RESET = 39;
const byte PIN_SCE = 40;

/*
The alphabet and some signs.
Alfabet i kilka znakow.
*/
static const byte ASCII[][5] =
{
 {0x00, 0x00, 0x00, 0x00, 0x00} // 20  
,{0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
,{0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
,{0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
,{0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
,{0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
,{0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
,{0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
,{0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
,{0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
,{0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
,{0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
,{0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
,{0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
,{0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
,{0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
,{0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
,{0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
,{0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
,{0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
,{0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
,{0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
,{0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
,{0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
,{0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
,{0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
,{0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
,{0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
,{0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
,{0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
,{0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
,{0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
,{0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
,{0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
,{0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
,{0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
,{0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
,{0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
,{0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
,{0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
,{0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
,{0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
,{0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
,{0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
,{0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
,{0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
,{0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
,{0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
,{0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
,{0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
,{0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
,{0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
,{0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
,{0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
,{0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
,{0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
,{0x02, 0x04, 0x08, 0x10, 0x20} // 5c ¥
,{0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
,{0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
,{0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
,{0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
,{0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
,{0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
,{0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
,{0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
,{0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
,{0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
,{0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
,{0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
,{0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
,{0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j 
,{0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
,{0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
,{0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
,{0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
,{0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
,{0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
,{0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
,{0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
,{0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
,{0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
,{0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
,{0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
,{0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
,{0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
,{0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
,{0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
,{0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
,{0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
,{0x10, 0x08, 0x08, 0x10, 0x08} // 7e ←
,{0x00, 0x06, 0x09, 0x09, 0x06} // 7f →
};

/*The function for writing a single character on the LCD display.
Funkcja wypisujaca znak na ekranie LCD.
*/
void LcdCharacter(char character)
{
  LcdWrite(LCD_D, 0x00);
  for (int index = 0; index < 5; index++)
  {
    LcdWrite(LCD_D, ASCII[character - 0x20][index]);
  }
  LcdWrite(LCD_D, 0x00);
}

/*
The function that clears the LCD display. Needed for refreshing.
Funkcja czyszczaca ekran LCD. Potrzebna przy odswiezaniu.
*/
void LcdClear(void)
{
  for (int index = 0; index < LCD_X * LCD_Y / 8; index++)
  {
    LcdWrite(LCD_D, 0x00);
  }
}

/*
The function for initializing the LCD display.
Funkcja inicjalizujaca ekran LCD.
*/
void LcdInitialise(void)
{
  pinMode(PIN_SCE,   OUTPUT);
  pinMode(PIN_RESET, OUTPUT);
  pinMode(PIN_DC,    OUTPUT);
  pinMode(PIN_SDIN,  OUTPUT);
  pinMode(PIN_SCLK,  OUTPUT);

  digitalWrite(PIN_RESET, LOW);
 // delay(1);
  digitalWrite(PIN_RESET, HIGH);

  LcdWrite( LCD_CMD, 0x21 );  // LCD Extended Commands.
  LcdWrite( LCD_CMD, 0xBf );  // Set LCD Vop (Contrast). //B1
  LcdWrite( LCD_CMD, 0x04 );  // Set Temp coefficent. //0x04
  LcdWrite( LCD_CMD, 0x14 );  // LCD bias mode 1:48. //0x13
  LcdWrite( LCD_CMD, 0x0C );  // LCD in normal mode. 0x0d for inverse
  LcdWrite(LCD_C, 0x20);
  LcdWrite(LCD_C, 0x0C);
}

/*
The function that outputs a character string on the LCD display.
Funkcja wypisujaca ciag znakow na ekranie LCD.
*/
void LcdString(char *characters)
{
  while (*characters)
  {
    LcdCharacter(*characters++);
  }
}

/*
The function which writes data to the LCD screen.
Funkcja wysylajaca dane do ekranu LCD.
*/
void LcdWrite(byte dc, byte data)
{
  digitalWrite(PIN_DC, dc);
  digitalWrite(PIN_SCE, LOW);
  shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, data);
  digitalWrite(PIN_SCE, HIGH);
}


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
const byte soundPin0 = 24;
const byte soundPin1 = 25;

/*
The variables of the pins which are connected to the light sensor.
Zmienna dla pinow, do ktorego podlaczone sa sensory swiatla.
*/
const byte lightPin0 = 26;
const byte lightPin1 = 27;

/*
The variables of the pins which are connected to the distance sensors.
trigPin - the transmitter on the module.
echoPin - the receiver on the module.
Zmienne dla pinow, do ktorych podlaczone sa sensory odleglosci.
trigPin - nadajnik na sensorze.
echoPin - odbiornik na sensorze.
*/
const byte trigPin0 = 2;
const byte echoPin0 = 3;
const byte trigPin1 = 4;
const byte echoPin1 = 5;

/*
The variables of the pins which are connected to the temperature and
humidity sensor.
Zmienna dla pinow, do ktorych podlaczone sa sensory temperatury
oraz wilgotnosci.
*/
const byte dht11Pin0 = 6;
const byte dht11Pin1 = 7;

/*
The variables of the pins which are connected to the LEDs.
LED0...4Pin - LEDs indexed from 0 to 4 (totalling 5).
Zmienne dla pinow, do ktorych podlaczone sa swiatelka LED.
LED0...4Pin - swiatelka LED, indeksowane od 0 do 4 (razem 5).
*/
const byte LED0Pin = 8;
const byte LED1Pin = 9;
const byte LED2Pin = 10;
const byte LED3Pin = 11;
const byte LED4Pin = 12;

/*
The variables of the pins which are connected to the membrane keypad.
They're defined as 2 arrays as it is the only correct input for the
constructor of the Keypad class.
Zmienne dla pinow, do ktorych podlaczona jest klawiatura membranowa.
Sa zdefiniowane jako 2 tablice, gdyz jest to wymagane przez
konstruktor klasy Keypad.
*/
byte keypadRows[] = {28, 29, 30, 31};
byte keypadCols[] = {32, 33, 34, 35};

/*
The variable of the pin which is connected to the buzzer.
Zmienna dla pinu, do ktorego podlaczony jest generator dzwieku.
*/
const byte buzzerPin = 13;

/*
The constant value for the proximity sensor.
Stala dla sensora odleglosci.
*/
const float distConst = 0.012027;

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
The variables of the dht11 class for the humidity and temperature sensors.
Zmienne klasy dht11 dla sensorow wilgotnosci i temperatury.
*/
dht11 dht110;
dht11 dht111;

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
short distance1;

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
The functions that calculate the distances, basing on the inputs from
the distance sensors.
Funkcja, ktora oblicza odleglosci na podstawie danych, wczytanych
z sensorow odleglosci.
*/
short getDistance0() {
  digitalWrite(trigPin0, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin0, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin0, LOW);
  return pulseIn(echoPin0, HIGH) * distConst;
}
short getDistance1() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  return pulseIn(echoPin1, HIGH) * distConst;
}
/*
The setup() function that runs only once just as Arduino has been connected.
Funkcja setup(), wywolywana tylko raz po podlaczeniu Arduino.
*/
void setup() {

/*
Firstly, the correct pin modes should be set.
Na poczatku, trzeba ustalic tryby poszczegolnych pinow.
*/
	pinMode(buzzerPin, OUTPUT); // Buzzer. - Generator dzwieku.

	pinMode(LED0Pin, OUTPUT); // Pins for the LEDs. - Piny dla swiatelek LED.
	pinMode(LED1Pin, OUTPUT);
	pinMode(LED2Pin, OUTPUT);
	pinMode(LED3Pin, OUTPUT);
	pinMode(LED4Pin, OUTPUT);

	pinMode(trigPin0, OUTPUT); // Transmitters on the proximity sensors. -
	pinMode(trigPin1, OUTPUT); // Nadajniki na sensorach odleglosci.

	pinMode(soundPin0, INPUT); // Sound sensors. - Sensory dzwieku.
	pinMode(soundPin1, INPUT);

	pinMode(lightPin0, INPUT); // Light sensors. - Sensory swiatla.
	pinMode(lightPin1, INPUT);

	pinMode(echoPin0, INPUT); // Receivers on the proximity sensors. -
	pinMode(echoPin1, INPUT); // Odbiorniki na sensorze odleglosci.

	pinMode(dht11Pin0, INPUT); // Temperature and humidity sensors. -
	pinMode(dht11Pin1, INPUT); // Sensory temperatury i wilgotnosci.

/*
Launching the serial communication between Arduino and PC.
Uruchomienie magistrali szeregowej pomiedzy Arduino i komputerem.
*/
	Serial.begin(9600);

/*
Procedures for initializing and clearing the LCD screen.
Procedury dla zainicjalizowania i wyczyszczenia ekranu LCD.
*/
	LcdInitialise();
	LcdClear();
}

/*
The set of instructions which will be run over and over.
Zestaw funkcji wywolywanych na okraglo.
*/
void loop() {
	light0 = digitalRead(lightPin0);
	light1 = digitalRead(lightPin1);

	sound0 = digitalRead(soundPin0);
	sound1 = digitalRead(soundPin1);

	distance0 = getDistance0();
	distance1 = getDistance1();

	temperature0 = dht110.temperature - 3;
	temperature1 = dht111.temperature - 3;
	humidity0 = dht110.humidity;
	humidity1 = dht111.humidity;
}
