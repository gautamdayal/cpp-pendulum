import numpy as np 
import matplotlib.pyplot as plt 

plt.style.use('dark_background')
plt.rcParams["font.family"] = "monospace"

# Angular position plotting
data = np.loadtxt("logs/pendulum_out.txt")
constants = data[0]
g, L, c = constants[0], constants[1], constants[2]
theta = data[:,1][1::]
omega = data[:,2][1::]
plt.plot(theta, omega)
plt.xlabel("Angle")
plt.ylabel("Angular Velocity")
plt.title("Pendulum Phase Portrait")

plt.savefig(f"plots/phase_portrait_g{g}_L{L}_c{c}.png")
plt.clf()

plt.plot(theta, label="Angle")
plt.plot(omega, label="Angular Velocity")
plt.xlabel("Time (s)")
plt.ylabel("Angles (rad)")
plt.legend()
plt.savefig(f"plots/timeseries_g{g}_L{L}_c{c}.png")
plt.clf()

# Linear position plotting
pos_data = np.loadtxt("logs/positions_out.txt")
x_series = pos_data[:,0][1::]
y_series = pos_data[:,1][1::]

plt.plot(x_series, label="X position")
plt.plot(y_series, label="Y position")
plt.xlabel("Time")
plt.ylabel("Position")
plt.legend()
plt.savefig("plots/position_timeseries.png")
plt.clf()