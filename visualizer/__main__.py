'''
The following script opens the LOG.LOG log file from Arduino, which needs to be in the same folder
and analyzes it. Afterwards, it saves the results in the PNG files.
Nastepujacy skrypt otwiera plik logu z Arduino LOG.LOG, ktory musi byc w tym samym folderze, co skrypt,
a nastepnie analizuje go. Pozniej, zapisuje dane w plikach PNG,
'''

'''
Importing the modules:
matplotlib and submodules - for plotting the graphs.
Tkinter - needed for the class that saves the files.
Importowanie modulow:
matplotib i submoduly - tworzenie wykresow.
Tkinter - potrzebny dla klasy zapisujacej pliki.
'''
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
import Tkinter as tk

'''
The font should be readable.
Czcionka powinna byc widoczna.
'''
matplotlib.rcParams.update({"font.size": 24})

'''
The following code makes sure the file is closed after reading (RAII).
Nastepujacy kod daje gwarancje, ze plik zostanie zamkniety po odczytaniu (RAII).
'''
with open("LOG.LOG", 'r') as p:
	x = p.read()

'''
Splitting the data into readable portions.
Dzielenie danych na czesci.
'''
lines = x.splitlines()
dataArray = []
for b in lines:
	d = b.split(',')
	dataArray.append(d)

'''
This function converts the data into the arrays that are comprehensive for the matplotlib module.
Ta funkcja konwertuje dane na tablice, ktore modul matplotlib jest w stanie zinterpretowac.
'''
def getData(r):
	global dataArray
	retArr = []
	for a in range(len(dataArray)):
		if dataArray[a][r] == 'e':
			retArr.append(None)
		else:
			retArr.append(int(dataArray[a][r]))
	return retArr

'''
This variable is a ghost window that is needed only to call the constructor of Tk so that plotting
and saving the graphs becomes possible.
Ta zmienna to tymczasowe okno, ktore jest potrzebne tylko do wezwania konstruktora klasy Tk, zeby
kreslenie i zapisywanie wykresow stalo sie mozliwe.
'''
ghost = tk.Tk()

'''
The actual class for plotting and saving the graphs.
Wlasciwa klasa do kreslenia oraz zapisywania wykresow.
'''
class saveFile(tk.Frame):
	def __init__(self, parent):
		tk.Frame.__init__(self, parent)
		
		'''
		The names of the files and graphs' titles.
		Nazwy plikow oraz tytulow wykresow.
		'''
		graphsTitles = ["Light - room 1", "Light - room 2", "Sound - room 1", "Sound - room 2", "Distance - room 1", "Distance - room 2", "Closed - room 1", "Closed - room 2", "Temperature - room 1", "Temperature - room 2", "Humidity - room 1", "Humidity - room 2"]
		filenames = ["light0.png", "light1.png", "sound0.png", "sound1.png", "distance0.png", "distance1.png", "closed0.png", "closed1.png", "temperature0.png", "temperature1.png", "humidity0.png", "humidity1.png"]
		for it in range(0, 12):
			f = Figure(figsize=(16, 8), dpi=255)
			ff = f.add_subplot(111)
			ff.axes.get_xaxis().set_visible(False)
			ff.set_ylim([min(filter(lambda mini: mini != None, getData(it))) - 3, max(filter(lambda maxi: maxi != None, getData(it))) + 3])
			f.suptitle(graphsTitles[it])
			ff.plot(range(0, len(getData(it))),getData(it), linewidth='1')
			FigureCanvasTkAgg(f, self)
			f.savefig(filenames[it])
		parent.quit()

'''
Calling the saveFile class in order to perform the graph plotting and saving.
Uzycie klasy saveFile, zeby wykonac operacje kreslenia wykresow i zapisu.
'''
saveFile(ghost)
