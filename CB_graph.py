import numpy as np
import matplotlib.pyplot as plt
numero = np.genfromtxt("advection.txt", usecols = (0))
pos = np.genfromtxt("advection.txt", usecols = (0))
amp = np.genfromtxt("advection.txt", usecols = (1))
n = int(numero[0])
posicion = pos[1:n]
amp1 = amp[1:n]
amp2 = amp[n:2*n-1]
amp3 = amp[2*n:3*n-1]
amp4 = amp[3*n:4*n-1]
amp5 = amp[4*n:5*n-1]
plt.plot(posicion,amp1, label = "Tiempo 0")
plt.plot(posicion,amp2, label = "Tiempo 1")
plt.plot(posicion,amp3, label = "Tiempo 2")
plt.plot(posicion,amp4, label = "Tiempo 3")
plt.plot(posicion,amp5, label = "Tiempo 4")
plt.legend()
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.savefig("graf.png")

