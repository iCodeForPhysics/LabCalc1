import matplotlib.pyplot as plt 
import numpy as np
# Grafico la traiettoria del corpo
plt.title('Moto circolare uniforme')
plt.xlabel('x')
plt.ylabel('y')
x, y = np.loadtxt('ex2.dat', usecols=(1,2), unpack=True) 
plt.plot(x, y, '-', label='Traiettoria')
plt.xlim(-10.0, 10.0)
plt.ylim(-10.0, 10.0)
plt.legend()
plt.show()
plt.clf() # Pulisco il grafico corrente
# Grafico la variazione della componente x rispetto al tempo
plt.title('Grafico x/t')
plt.xlabel('t')
plt.ylabel('x')
x, y = np.loadtxt('ex2.dat', usecols=(0,1), unpack=True)
plt.plot(x, y, '-', label='Variazione x')
plt.xlim(0.0, 999.0)
plt.ylim(-8.0, 8.0)
plt.legend()
plt.show()
plt.clf()
# Grafico la variazione di velocità (sulla x) rispetto al tempo
plt.title('Grafico v/t')
plt.xlabel('t')
plt.ylabel('v(x)')
x, y = np.loadtxt('ex2.dat', usecols=(0,3), unpack=True)
plt.plot(x, y, '-', label='Variazione V(x)')
plt.xlim(0.0, 999.0)
plt.ylim(-1.0, 1.0)
plt.legend()
plt.show()
plt.clf()
# Grafico la traiettoria del corpo con annessi i vettori velocità per ogni punto graficato
plt.title('Grafico della traiettoria con i vettori velocità')
plt.xlabel('x')
plt.ylabel('y')
x, y = np.loadtxt('ex2.dat', usecols=(1,2), unpack=True)
plt.plot(x, y, '-', label='Traiettoria')
plt.xlim(-10.0, 10.0)
plt.ylim(-10.0, 10.0)
x, y, vx, vy = np.loadtxt('ex2.dat', usecols=(1,2,3,4), unpack=True)
for cc in range(0, len(x)/2): # Divido per avere un grafico visibile dei vettori v
  xi = x[cc]
  yi = y[cc]
  vxi = vx[cc]
  vyi = vy[cc]
  plt.arrow(xi, yi, vxi, vyi, width=0.1, head_width=0.3, head_length=0.2, fc='r', ec='r')
plt.legend()
plt.savefig('ex2_alternativo.png')
plt.show()
