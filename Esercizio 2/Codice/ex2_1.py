import matplotlib.pyplot as plt 
import numpy as np
plt.title('Moto circolare uniforme')
plt.xlabel('x')
plt.ylabel('y')
x, y = np.loadtxt('ex2.dat', usecols=(1,2), unpack=True) #Per graficare le velocità cambiare le colonne in (3, 4)
plt.plot(x, y, '-', label='Traiettoria')
plt.xlim(-10.0, 10.0)
plt.ylim(-10.0, 10.0)
plt.legend()
plt.show()