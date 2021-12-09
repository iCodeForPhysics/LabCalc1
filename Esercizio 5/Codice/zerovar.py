import numpy as np
import matplotlib.pyplot as plt
plt.title('Frequenza Zeri')
x, y = np.loadtxt('zerovar.dat', unpack=True)
plt.plot(x, y, '-', label='f')
plt.xlabel('N')
plt.ylabel('Zeri')
plt.legend()
plt.savefig('zeri.png')
plt.show()
#Per N=3, 4, 5, 6 si hanno sempre 2 zeri, questo perché gli intervalli sono troppo grandi per
#avere un grafico preciso, questo insieme alle approssimazioni comporta una grande imprecisione
#per valori di N < 62 (che è anche il valore dove si raggiunge il numero massimo di zeri tra -100 
#e 100)