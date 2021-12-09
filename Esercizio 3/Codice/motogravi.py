import matplotlib.pyplot as plt 
import numpy as np
plt.title('Moto Parabolico')
plt.xlabel('Gittata (m)')
plt.ylabel('Alfa (rad)')
x, y = np.loadtxt('motogravi.dat', usecols=(1,0), unpack=True)
plt.plot(x, y, 'x-', label='Gittata')
plt.legend()
plt.show()