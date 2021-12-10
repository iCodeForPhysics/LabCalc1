import matplotlib.pyplot as plt
import numpy as np
plt.title('Simulatore lancio dei dadi')
plt.xlabel('k')
plt.ylabel('f')
x, y = np.loadtxt('lanci.dat', usecols=(1,0), unpack=True)
plt.plot(x, y, '-', label='N=20') # Non richiesto dall'esercizio, aiuta a visualizzare
plt.bar(x, y, color='c', label='Dadi')
plt.legend()
plt.show()