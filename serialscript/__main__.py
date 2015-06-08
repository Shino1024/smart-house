'''
The Python script that is responsible for downloading
the data from the Arduino Mega2560 board and processing it.
Skrypt w Pythonie, ktory sluzy do pobierania danych
z mikrokontrolera i przetwarzania ich.
'''

'''
Importing the modules:
serial - for the serial communication.
numpy - for processing the data.
matplotlib - for plotting the graphs from the data.
tkinter - for creating the graphical user interface.
Importowanie modulow:
serial - do komunikacji szeregowej.
numpy - do analizy danych.
matplotlib - do rysowania wykresow z danych.
tkinter - do tworzenia graficznego interfejsu uzytkownika.
'''
import serial
import numpy
import matplotlib
import tkinter

'''
Creating a serial object for communication with Arduino.
Tworzenie obiektu do komunikacji szeregowej z Arduino.
'''
arduino = serial.Serial("/dev/tty.usbserial", 9600)
