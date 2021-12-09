import matplotlib.pyplot as plt 
import numpy as np
plt.title('Grafico della traiettoria con i vettori velocità')
plt.xlabel('x')
plt.ylabel('y')
x, y = np.loadtxt('ex2.dat', usecols=(1,2), unpack=True)
plt.plot(x, y, '-', label='Traiettoria')
plt.xlim(-10.0, 10.0)
plt.ylim(-10.0, 10.0)
x, y, vx, vy = np.loadtxt('ex2.dat', usecols=(1,2,3,4), unpack=True)
for cc in range(0, len(x)):
  xi = x[cc]
  yi = y[cc]
  vxi = vx[cc]
  vyi = vy[cc]
  plt.arrow(xi, yi, vxi, vyi, width=0.1, head_width=0.3, head_length=0.2, fc='r', ec='r')
plt.legend()
plt.savefig('ex2.png')
plt.show()