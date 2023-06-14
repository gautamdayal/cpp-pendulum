import numpy as np 
import matplotlib.pyplot as plt 

plt.style.use('dark_background')
plt.rcParams["font.family"] = "monospace"

data = np.loadtxt("logs/pendulum_out.txt")
constants = data[0]
g, L, c = constants[0], constants[1], constants[2]
plt.plot(data[:,1][1::], data[:,2][1::])
plt.xlabel("Angle")
plt.ylabel("Angular Velocity")
plt.title("Pendulum Phase Portrait")

plt.savefig(f"plots/phase_portrait_g{g}_L{L}_c{c}.png")