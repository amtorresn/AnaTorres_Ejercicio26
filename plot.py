import numpy as np
import matplotlib.pyplot as plt


data_01 = np.loadtxt("exp_01.dat")
data_001 = np.loadtxt("exp_001.dat")
data_1 = np.loadtxt("exp_1.dat")


#print(data_01[:,0])
#print(data_01[:,1])


plt.figure(figsize=(15,15))

plt.subplot(3,3,1)
plt.title("$y$ vs $x$, 0.1")
plt.plot(data_01[:,0], data_01[:,1])
plt.subplot(3,3,2)
plt.title("$y$ vs $x$, 0.01")
plt.plot(data_001[:,0], data_001[:,1])
plt.subplot(3,3,3)
plt.title("$y$ vs $x$, 1")
plt.plot(data_1[:,0], data_1[:,1])



plt.subplot(3,3,4)
plt.title("$dy/dx$ vs $x$, 0.1")
plt.plot(data_01[:,0], data_01[:,2])
plt.subplot(3,3,5)
plt.title("$dy/dx$ vs $x$, 0.01")
plt.plot(data_001[:,0], data_001[:,2])
plt.subplot(3,3,6)
plt.title("$dy/dx$ vs $x$, 1")
plt.plot(data_1[:,0], data_1[:,2])


plt.subplot(3,3,7)
plt.title("$dy/dx$ vs $y$, 0.1")
plt.plot(data_01[:,1], data_01[:,2])
plt.subplot(3,3,8)
plt.title("$dy/dx$ vs $y$, 0.01")
plt.plot(data_001[:,1], data_001[:,2])
plt.subplot(3,3,9)
plt.title("$dy/dx$ vs $y$, 1")
plt.plot(data_1[:,1], data_1[:,2])



plt.savefig("fig.png")