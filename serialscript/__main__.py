'''
The Python script that is responsible for downloading
the data from the Arduino Mega2560 board and processing it.
Skrypt w Pythonie, ktory sluzy do pobierania danych
z mikrokontrolera i przetwarzania ich.
'''

'''
Importing the modules:
time (sleep) - for the pause.
serial - for the serial communication.
os - for communication with the operating system.
Tkinter - for creating the graphical user interface (imported in arduinoApp.py).
arduinoApp - the GUI class that inherits from Tkinter.Tk and displays the window. It contains the page
classes for the window to display.
webbrowser - allows to use the hyperlinks in labels.
Importowanie modulow:
time (sleep) - dla pauzy.
serial - do komunikacji szeregowej.
os - do komunikacji z systemem operacyjnym.
Tkinter - do tworzenia graficznego interfejsu uzytkownika (zimportowany w arduinoApp.py).
arduinoApp - klasa graficznego interfejsu uzytkownika, ktora dziedziczy po Tkinter.Tk i wyswietla okno.
Zawiera klasy stron dla okna do wyswietlenia.
webbrowser - pozwala na uzycie linkow w etykietach.
'''
from Tkinter import *
from time import sleep
import serial
import os
import webbrowser

'''
Creating a serial object for communication with Arduino.
Tworzenie obiektu do komunikacji szeregowej z Arduino.
'''
arduino = serial.Serial("/dev/" + os.popen("dmesg | egrep ttyACM | cut -f3 -d: | tail -n1").read().strip(), 9600)

'''
The variable where the output from the serial is saved to.
Zmienna, do ktorej zostaja wczytane dane z Arduino.
'''
data = ""

'''
The array where the data from the previous variable are split and kept into.
Zmienna, ktora przechowuje rozdzielone dane z poprzedniej zmiennej.
'''
dataArray = []

'''
The label widgets that will be defined later in the page classes.
Widzety etykiet, ktore beda zdefiniowane pozniej w klasach stron.
'''
l1, l2, l3, l4, l5 = None, None, None, None, None
x1, x2, x3, x4, x5 = None, None, None, None, None
c1, c2, c3, c4, c5 = None, None, None, None, None

'''
The variable that determines the window page.
Zmienna okreslajaca strone w oknie.
'''
mode = 0

'''
The main window class of the application.
Glowna klasa okna aplikacji.
'''
class arduinoApp(Tk):
	def __init__(self, *args, **kwargs):
		Tk.__init__(self, *args, **kwargs)
		global mode
		container = Frame(self)
		container.pack(side = "top", fill = "both", expand = True)
		container.grid_rowconfigure(0, weight = 1)
		container.grid_columnconfigure(0, weight = 1)
		self.frames = {}
		for F in (welcomePage, sensorPage0, sensorPage1, devicePage, aboutPage):
			frame = F(container, self)
			self.frames[F] = frame
			frame.grid(row = 0, column = 0, sticky = "nsew")
		self.show_frame(welcomePage)

	'''
	The function for showing the appropriate frame and changing the window mode.
	Funkcja przelaczajaca okna oraz zmieniajaca tryb okna.
	'''
	def show_frame(self, cont):
		global mode
		if (cont == sensorPage0):
			mode = 1
		elif (cont == sensorPage1):
			mode = 2
		elif (cont == devicePage):
			mode = 3
		else:
			mode = 0
		frame = self.frames[cont]
		frame.tkraise()

class welcomePage(Frame):
	def __init__(self, parent, controller):
		Frame.__init__(self, parent)
		l0 = Label(self, text = "Pythonic Smart House Manager", font = ("Ubuntu Mono", 16))
		b0 = Button(self, text = "Room 1", command = lambda: controller.show_frame(sensorPage0))
		b1 = Button(self, text = "Room 2", command = lambda: controller.show_frame(sensorPage1))
		b2 = Button(self, text = "Devices", command = lambda: controller.show_frame(devicePage))
		b3 = Button(self, text = "About", command = lambda: controller.show_frame(aboutPage))
		b4 = Button(self, text = "Quit", command = lambda: exit())
		l0.grid(row = 0, columnspan = 2, sticky = "nsew")
		b0.grid(row = 1, column = 0, sticky = "nsew")
		b1.grid(row = 1, column = 1, sticky = "nsew")
		b2.grid(row = 2, column = 0, sticky = "nsew")
		b3.grid(row = 2, column = 1, sticky = "nsew")
		b4.grid(row = 3, columnspan = 2, sticky = "nsew")

'''
The room 1 page class.
Klasa strony pokoju pierwszego.
'''
class sensorPage0(Frame):
	def __init__(self, parent, controller):
		Frame.__init__(self, parent)
		global x1, x2, x3, x4, x5
		l0 = Label(self, text = "   Sensors from the room 1  ", font = ("Ubuntu Mono", 16))
		b0 = Button(self, command = lambda: controller.show_frame(welcomePage), text = "Go back")
		x1 = Label(self)
		x2 = Label(self)
		x3 = Label(self)
		x4 = Label(self)
		x5 = Label(self)
		l0.grid(row = 0, columnspan = 2, sticky = "nsew")
		b0.grid(row = 3, column = 1, sticky = "nsew")
		x1.grid(row = 1, column = 0, sticky = "nsew")
		x2.grid(row = 1, column = 1, sticky = "nsew")
		x3.grid(row = 2, column = 0, sticky = "nsew")
		x4.grid(row = 2, column = 1, sticky = "nsew")
		x5.grid(row = 3, column = 0, sticky = "nsew")

'''
The room 2 page class.
Klasa strony pokoju drugiego.
'''
class sensorPage1(Frame):
	def __init__(self, parent, controller):
		Frame.__init__(self, parent)
		global l1, l2, l3, l4, l5
		l0 = Label(self, text = "   Sensors from the room 2  ", font = ("Ubuntu Mono", 16))
		b0 = Button(self, command = lambda: controller.show_frame(welcomePage), text = "Go back")
		l1 = Label(self)
		l2 = Label(self)
		l3 = Label(self)
		l4 = Label(self)
		l5 = Label(self)
		l0.grid(row = 0, columnspan = 2, sticky = "nsew")
		b0.grid(row = 3, column = 1, sticky = "nsew")
		l1.grid(row = 1, column = 0, sticky = "nsew")
		l2.grid(row = 1, column = 1, sticky = "nsew")
		l3.grid(row = 2, column = 0, sticky = "nsew")
		l4.grid(row = 2, column = 1, sticky = "nsew")
		l5.grid(row = 3, column = 0, sticky = "nsew")

'''
The devices page class.
Klasa strony urzadzen.
'''
class devicePage(Frame):
	def __init__(self, parent, controller):
		Frame.__init__(self, parent)
		global c1, c2, c3, c4, c5
		l0 = Label(self, text = "           Devices          ", font = ("Ubuntu Mono", 16))
		b0 = Button(self, command = lambda: controller.show_frame(welcomePage), text = "Go back")
		c1 = Label(self)
		c2 = Label(self)
		c3 = Label(self)
		c4 = Label(self)
		c5 = Label(self)
		l0.grid(row = 0, columnspan = 2, sticky = "nsew")
		b0.grid(row = 3, column = 1, sticky = "nsew")
		c1.grid(row = 1, column = 0, sticky = "nsew")
		c2.grid(row = 1, column = 1, sticky = "nsew")
		c3.grid(row = 2, column = 0, sticky = "nsew")
		c4.grid(row = 2, column = 1, sticky = "nsew")
		c5.grid(row = 3, column = 0, sticky = "nsew")

'''
The information page class.
Klasa strony z informacjami.
'''
class aboutPage(Frame):
	def __init__(self, parent, controller):
		Frame.__init__(self, parent)
		l0 = Label(self, text = "            About           ", font = ("Ubuntu Mono", 16))
		b0 = Button(self, command = lambda: controller.show_frame(welcomePage), text = "Go back")
		p0 = Label(self, text = "Link to the project.", font = ("Ubuntu", 10), cursor = "hand2")
		p0.bind("<Button-1>", callback0)
		l0.grid(row = 0, columnspan = 2, sticky = "nsew")
		p0.grid(rowspan = 2, columnspan = 2, sticky = "nsew")
		b0.grid(row = 3, columnspan = 1, sticky = "nsew")

'''
The function that opens the project's website.
Funkcja otwierajaca strone projektu.
'''
def callback0(event):
	webbrowser.open_new(r"http://www.rpsdusu-sh.com/homepage")

'''
The function that gets the data from Arduino and saves it to the data files.
Funkcja, ktora pobiera dane z Arduino i zapisuje je do plikow danych.
'''
def getData():

	'''
	Getting the global variables and reading the input from Arduino.
	Pobieranie zmiennych globalnych oraz wczytywanie danych z Arduino.
	'''
	global data, dataArray, app, l0, l1, l2, l3, l4, mode
	data = arduino.readline()
	dataArray = data.split(',')

	'''
	The room 1 mode.
	Tryb pokoju pierwszego.
	'''
	if mode == 1:
		if data:
			if int(dataArray[0]):
				x1.configure(text = "Light!", background = "yellow")
			else:
				x1.configure(text = "...", background = "white")
			if int(dataArray[2]):
				x2.configure(text = "Sound!", background = "yellow")
			else:
				x2.configure(text = "...", background = "white")
			if dataArray[6] == 'e':
				x3.configure(text = "Error!", background = "blue")
			elif int(dataArray[6]):
				x3.configure(text = "Closed!", background = "red")
			else:
				x3.configure(text = "Open!", background = "green")
			if dataArray[8] == 'e':
				x4.configure(text = "Error!", background = "blue")
			else:
				x4.configure(text = str(dataArray[8]) + "C / " + str(1.8 * float(dataArray[8]) + 32) + 'F', background = "white")
			if dataArray[10] == 'e':
				x5.configure(text = "Error!", background = "blue")
			else:
				x5.configure(text = str(dataArray[10]) + '%', background = "white")

	'''
	The room 2 mode.
	Tryb pokoju drugiego.
	'''
	if mode == 2:
		if data:
			if int(dataArray[1]):
				l1.configure(text = "Light!", background = "yellow")
			else:
				l1.configure(text = "...", background = "white")
			if int(dataArray[3]):
				l2.configure(text = "Sound!", background = "yellow")
			else:
				l2.configure(text = "...", background = "white")
			if dataArray[7] == 'e':
				l3.configure(text = "Error!", background = "blue")
			elif int(dataArray[7]):
				l3.configure(text = "Closed!", background = "red")
			else:
				l3.configure(text = "Open!", background = "green")
			if dataArray[9] == 'e':
				l4.configure(text = "Error!", background = "blue")
			else:
				l4.configure(text = str(dataArray[9]) + "C / " + str(1.8 * float(dataArray[9]) + 32) + 'F', background = "white")
			if dataArray[11] == 'e':
				l5.configure(text = "Error!", background = "blue")
			else:
				l5.configure(text = str(dataArray[11]) + '%', background = "white")

	'''
	The device mode.
	Tryb urzadzen.
	'''
	if mode == 3:
		if data:
			if int(dataArray[12]):
				c1.configure(text = "On", background = "green")
			else:
				c1.configure(text = "Off", background = "red")
			if int(dataArray[13]):
				c2.configure(text = "On", background = "green")
			else:
				c2.configure(text = "Off", background = "red")
			if int(dataArray[14]):
				c3.configure(text = "On", background = "green")
			else:
				c3.configure(text = "Off", background = "red")
			if int(dataArray[15]):
				c4.configure(text = "On", background = "green")
			else:
				c4.configure(text = "Off", background = "red")
			if int(dataArray[16]):
				c5.configure(text = "On", background = "green")
			else:
				c5.configure(text = "Off", background = "red")

	'''
	Recurrence.
	Rekurencja.
	'''
	app.after(1, getData)

'''
The definition of the application.
Definicja aplikacji.
'''
app = arduinoApp()

'''
The application has to sleep for 3 seconds in order to avoid the messy data sent in the beginning. The
flushInput() method makes sure thre is no rubbish left.
Aplikacja musi poczekac 3 sekundy, by uniknac smieci wysylanych na poczatku. Metoda flushInput kasuje
wszystkie pozostalosci.
'''
sleep(3)
arduino.flushInput()

'''
The recurrent getData function is called moments before starting the loop of the application so that
the data is being updated live and nothing is interfering with anything else. The update rate is set
as one ms.
Funkcja rekurencyjna getData jest uzyta chwile przed rozpoczeciem glownej petli aplikacji, zeby dane
byly aktualizowane na zywo i nic nie interferowalo ze soba. Wspolczynnik aktualizacji wynosi 1 ms.
'''
app.after(1, getData)

'''
The window should not be resizable.
Okno nie moze umozliwiac zmiany swojej wielkosci.
'''
app.resizable(0, 0)

'''
The title of the program.
Tytul okna.
'''
app.wm_title("Smart House Manager")

'''
The main loop of the program.
Glowna petla programu.
'''
app.mainloop()
