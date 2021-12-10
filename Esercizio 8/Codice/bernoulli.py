import matplotlib.pyplot as plt
import numpy as np
#Per i commenti di questo codice fare riferimento al file LabCalc1/Esercizio 2/Codice/ex2_alternativo.py
print("Sono tanti perché so FIGO!!!")
plt.title('Distribuzione Binomiale')
plt.xlabel('k')
plt.ylabel('f')
x, y2 = np.loadtxt('bernoulli_2.dat', unpack=True)
plt.plot(x, y2, '-', label='N=2')
plt.bar(x, y2, color='c', label='Bernoulli')
plt.legend()
plt.show()
plt.clf()
plt.title('Distribuzione Binomiale')
plt.xlabel('k')
plt.ylabel('f')
x, y4 = np.loadtxt('bernoulli_4.dat', unpack=True)
plt.plot(x, y4, '-', label='N=4')
plt.bar(x, y4, color='c', label='Bernoulli')
plt.legend()
plt.show()
plt.clf()
plt.title('Distribuzione Binomiale')
plt.xlabel('k')
plt.ylabel('f')
x, y10 = np.loadtxt('bernoulli_10.dat', unpack=True)
plt.plot(x, y10, '-', label='N=10')
plt.bar(x, y10, color='c', label='Bernoulli')
plt.legend()
plt.show()
plt.clf()
plt.title('Distribuzione Binomiale')
plt.xlabel('k')
plt.ylabel('f')
x, y20 = np.loadtxt('bernoulli_20.dat', unpack=True)
plt.plot(x, y20, '-', label='N=20')
plt.bar(x, y20, color='c', label='Bernoulli')
plt.legend()
plt.show()
plt.clf()
plt.title('Simulatore lancio dei dadi')
plt.xlabel('k')
plt.ylabel('f')
x, y = np.loadtxt('lanci.dat', usecols=(1,0), unpack=True)
plt.plot(x, y, '-', label='N=20')
plt.bar(x, y, color='c', label='Dadi')
plt.legend()
plt.show()