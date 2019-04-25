import numpy as np
import matplotlib.pyplot as plt
data_euler = np.loadtxt("euler.dat")
data_rk4 = np.loadtxt("rk4.dat")
# data_frog = np.loadtxt("frog.dat")


plt.figure(figsize=(12,12))





plt.subplot(3,3,1)
plt.xlabel("Time")
plt.ylabel("Position")
plt.ylim((-1.5,1.5))
plt.xlim((0,15))
plt.plot(data_euler[:,0], data_euler[:,1])
plt.title("Euler")



plt.subplot(3,3,2)
plt.xlabel("Time")
# plt.ylabel("Position")
plt.ylim((-1.5,1.5))
plt.xlim((0,15))
plt.plot(data_rk4[:,0], data_rk4[:,1])
plt.title("RK")




# plt.subplot(3,3,3)
# plt.xlabel("Time")
## plt.ylabel("Position")
# plt.ylim((-1.5,1.5))
# plt.xlim((0,15))
# plt.plot(data_frog[:,0], data_frog[:,1])
# plt.title("Leap Frog")

plt.subplot(3,3,4)
plt.xlabel("Time")
plt.ylabel("Velocity")
plt.ylim((-1.5,1.5))
plt.xlim((0,15))
plt.plot(data_euler[:,0], data_euler[:,2])

plt.subplot(3,3,5)
plt.xlabel("Time")
# plt.ylabel("Velocity")
plt.ylim((-1.5,1.5))
plt.xlim((0,15))
plt.plot(data_rk4[:,0], data_rk4[:,2])

# plt.subplot(3,3,6)
# plt.xlabel("Time")
## plt.ylabel("Velocity")
# plt.ylim((-1.5,1.5))
# plt.xlim((0,15))
# plt.plot(data_frog[:,0], data_frog[:,2])


plt.subplot(3,3,7)
plt.xlabel("Time")
plt.ylabel("Velocity")
plt.ylim((-2,2))
plt.xlim((-2,2))
plt.plot(data_euler[:,1], data_euler[:,2])

plt.subplot(3,3,8)
plt.xlabel("Time")
# plt.ylabel("Velocity")
plt.ylim((-2,2))
plt.xlim((-2,2))
plt.plot(data_rk4[:,1], data_rk4[:,2])

# plt.subplot(3,3,9)
# plt.xlabel("Time")
## plt.ylabel("Velocity")
# plt.ylim((-2,2))
# plt.xlim((-2,2))
# plt.plot(data_frog[:,1], data_frog[:,2])

plt.savefig("fig.png")