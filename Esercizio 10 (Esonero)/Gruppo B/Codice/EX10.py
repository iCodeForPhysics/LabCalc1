import matplotlib.pyplot as plt
import numpy as np
plt.title('Somma valori mantissa')
x, y = np.loadtxt('numfpsum.dat', unpack=True)
plt.xlabel('N')
plt.ylabel('Somma')
plt.plot(x, y, '-', label='Somma valori Mantissa')
plt.legend()
plt.savefig('numfpsum.png')
plt.show()