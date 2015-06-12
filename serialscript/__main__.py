'''
The Python script that is responsible for downloading
the data from the Arduino Mega2560 board and processing it.
Skrypt w Pythonie, ktory sluzy do pobierania danych
z mikrokontrolera i przetwarzania ich.
'''

'''
Importing the modules:
serial - for the serial communication.
os - for communication with the operating system.
Tkinter - for creating the graphical user interface.
Importowanie modulow:
serial - do komunikacji szeregowej.
os - do komunikacji z systemem operacyjnym.
Tkinter - do tworzenia graficznego interfejsu uzytkownika.
'''
import serial
import os
import Tkinter
import sys

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

data = ""
dataArray = []
b0, l1, l2, l3, l4, l5 = None, None, None, None, None, None

class arduinoApp(Tk):
	def __init__(self, *args, **kwargs):
		Tk.__init__(self, *args, **kwargs)
		container = Frame(self)
		container.pack(side = "top", fill = "both", expand = True)
		container.grid_rowconfigure(0, weight = 1)
		container.grid_columnconfigure(0, weight = 1)
		self.frames = {}
		for F in (welcomePage, sensorPage):
			frame = F(container, self)
			self.frames[F] = frame
			frame.grid(row = 0, column = 0, sticky = "nsew")
		self.show_frame(welcomePage)
	def show_frame(self, cont):
		frame = self.frames[cont]
		frame.tkraise()

class welcomePage(Frame):
	def __init__(self, parent, controller):
		Frame.__init__(self, parent)
		Label(self, text = "Pythonic Smart House Manager", font = ("Ubuntu Mono", 16)).grid(row = 0, columnspan = 2, sticky = "nsew")
		b0 = Button(self, command = lambda: controller.show_frame(sensorPage), text = "Sensor Page!")
		l1 = Label(self, text = "Nigga!")
		l2 = Label(self, text = "Nigga!")
		l3 = Label(self, text = "Nigga!")
		l4 = Label(self, text = "Nigga!")
		l5 = Label(self, text = "Nigga!")
		b0.grid(row = 1, column = 0, sticky = "nsew")
		l1.grid(row = 1, column = 1, sticky = "nsew")
		l2.grid(row = 2, column = 0, sticky = "nsew")
		l3.grid(row = 2, column = 1, sticky = "nsew")
		l4.grid(row = 3, column = 0, sticky = "nsew")
		l5.grid(row = 3, column = 1, sticky = "nsew")

class sensorPage(Frame):
	def __init__(self, parent, controller):
		global b0, l1, l2, l3, l4, l5
		Frame.__init__(self, parent)
		Label(self, text = "          Sensors!          ", font = ("Ubuntu Mono", 16)).grid(row = 0, columnspan = 2, sticky = "nsew")
		b0 = Button(self, command = lambda: controller.show_frame(welcomePage), text = "Go back!")
		l1 = Label(self)
		l2 = Label(self)
		l3 = Label(self)
		l4 = Label(self)
		l5 = Label(self)
		b0.grid(row = 3, column = 1, sticky = "nsew")
		l1.grid(row = 1, column = 0, sticky = "nsew")
		l2.grid(row = 1, column = 1, sticky = "nsew")
		l3.grid(row = 2, column = 0, sticky = "nsew")
		l4.grid(row = 2, column = 1, sticky = "nsew")
		l5.grid(row = 3, column = 0, sticky = "nsew")

def getData():
	global data, dataArray, app, b0, l1, l2, l3, l4, l5
	data = arduino.readline()
	dataArray = data.split(',')
	if data:
		print data
		dataArray = data.split(',')
		if int(dataArray[0]):
			l1.configure(text = "Light!")
		else:
			l1.configure(text = "...")
		if int(dataArray[2]):
			l2.configure(text = "Sound!")
		else:
			l2.configure(text = "...")
		if dataArray[4] == 'e':
			l3.configure(text = "Error!", background = "blue")
		elif int(dataArray[6]):
			l3.configure(text = "Closed!", background = "red")
		else:
			l3.configure(text = "Open!", background = "green")
		if dataArray[8] == 'e':
			l4.configure(text = "Error!")
		else:
			l4.configure(text = dataArray[8])
		if dataArray[10] == 'e':
			l5.configure(text = "Error!")
		else:
			l5.configure(text = dataArray[10])
	app.after(1, getData)

arduino = Serial("/dev/" + popen("dmesg | egrep ttyACM | cut -f3 -d: | tail -n1").read().strip(), 9600)
sleep(3)
arduino.flushInput()

app = arduinoApp()
app.after(1, getData)
app.mainloop()
