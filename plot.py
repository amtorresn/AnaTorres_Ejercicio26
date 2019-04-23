import numpy as np
import matplotlib.pyplot as plt


data_01 = np.loadtxt("exp_01.dat")
data_001 = np.loadtxt("exp_001.dat")
data_1 = np.loadtxt("exp_1.dat")


#print(data_01[:,0])
#print(data_01[:,1])

plt.figure(figsize=(14,4))

plt.subplot(1,3,1)
plt.title("0.1")
plt.plot(data_01[:,0], data_01[:,1])
plt.subplot(1,3,2)
plt.title("0.01")
plt.plot(data_001[:,0], data_001[:,1])
plt.subplot(1,3,3)
plt.title("1")
plt.plot(data_1[:,0], data_1[:,1])

plt.savefig("fig.png")