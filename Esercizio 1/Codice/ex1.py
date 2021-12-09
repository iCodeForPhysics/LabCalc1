import matplotlib.pyplot as plt 
import numpy as np
plt.title('Un primo plot con Python')
x, y = np.loadtxt('ex1.dat', unpack=True)
plt.plot(x ,y, 'o-.b', label='Temperature Convertite') 
plt.xlim((-10,130)) # intervallo lungo asse x 
plt.ylim((10,250)) # intervallo lungo asse y
plt.xlabel('Temperature Celsius')
plt.ylabel('Temperature Fahrenheit')
plt.savefig('temp.png')
plt.legend()
plt.show()