import matplotlib.pyplot as plt
import numpy as np
plt.title('Complemento a 2')
x, y = np.loadtxt('compl2.dat', unpack=True)
plt.xlabel('M')
plt.ylabel('compl2')
plt.bar(x, y, color='c', label='Numero complemento a 2')
plt.legend()
plt.savefig('compl2.png')
plt.show()