import matplotlib.pyplot as plt 
import numpy as np
plt.title('Cerchio PI')
plt.xlabel('x')
plt.ylabel('y')
x, y = np.loadtxt('pi_calcolo.dat', unpack=True)
plt.plot(x, y, 'o', label='Cerchio')
plt.legend()
plt.show()