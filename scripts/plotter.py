import numpy as np 
import matplotlib.pyplot as plt 

plt.style.use('dark_background')
plt.rcParams["font.family"] = "monospace"

rk4 = np.loadtxt("logs/rk4_output.txt")
plt.plot(rk4[:,1], rk4[:,2])
plt.xlabel("Angle")
plt.ylabel("Angular Velocity")
plt.title("Pendulum Phase Portrait")

plt.savefig("plots/phase_portrait.png")