import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Ellipse              # Importo le ellissi da matplotlib.patches
a = plt.subplot(1,1,1, aspect='equal')              # Genero un subplot 
a.add_patch(Ellipse((0, 0), 4, 2, 0, fill=False))   # Disegno la prima ellisse
a.add_patch(Ellipse((0, 0), 4, 2, 90,fill=False))   # Disegno la seconda ellisse (Girata di 90 gradi)
plt.title('Monte Carlo')
plt.xlabel('x')
plt.ylabel('y')
plt.grid()
x, y = np.loadtxt('punti.dat', unpack=True)         # Carico i valori dal File
plt.plot(x, y, 'o', label='Punti nell\'Area')       # Disegno il plot (\' mi permette di usare l'apice singolo)
plt.legend()
plt.savefig('hitmiss.png')
plt.show()