import numpy as np 
import matplotlib.pyplot as plt 

# euler = np.loadtxt("euler_output.txt")
rk4 = np.loadtxt("rk4_output.txt")

# plt.plot(euler[:,1], label="Forward Euler")
plt.plot(rk4[:,1], label="RK4")
plt.plot(rk4[:,2])
# plt.plot((euler[:,0]**3)/3, label="Truth")
plt.legend()
plt.show()