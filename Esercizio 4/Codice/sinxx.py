import numpy as np
import matplotlib.pyplot as plt
plt.title('f(x) = sin(x)/x')
x, y = np.loadtxt('sinxx.dat', unpack=True)
d = np.linspace(-100,100,1000) # Creo un asse delle ascisse
e = np.linspace(-0.3,1.1,1000) # Creo un asse delle ordinate
c = 0
plt.plot(d, c, '-', label='Asse Ascisse')
plt.plot(c, e, '-', label='Asse Ordinate') 
plt.plot(x, y, '-', label='f(x) = sin(x) / x')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.savefig('sinxx.png')
plt.show()