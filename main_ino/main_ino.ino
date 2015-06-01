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

#include "../include/keypad/Keypad.cpp"
#include "../include/pcd8544/PCD8544.h"
#include "../include/dht11/dht11.cpp"
#include "../include/main.h"

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

	pinMode(lcdSCLKPin, OUTPUT); // The LCD screen. - Ekran LCD.
	pinMode(lcdSNPin, OUTPUT);
	pinMode(lcdDCPin, OUTPUT);
	pinMode(lcdRSTPin, OUTPUT);
	pinMode(lcdSCEPin, OUTPUT);

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
}
