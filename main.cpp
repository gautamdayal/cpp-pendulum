// // // ETUDE

#include <iostream>
#include <fstream>
#include <cmath>
#include "ODESolvers.hpp"

// Constants
const double g = 9.81;
const double L = 2.0;
const double c = 0.25;

// ODEs
double thetaODE(double t, double theta, double omega) {
    return omega;
}

double omegaODE(double t, double theta, double omega) {
    return (-g / L) * std::sin(theta) - (c * omega);
}

int main() {
    // Initial conditions
    double theta0 = 3;
    double omega0 = 0.0;

    // Step size and time
    double stepSize = 0.01;
    double t = 0.0;

    // Create ODESolver objects
    ODESolver<RUNGE_KUTTA_4, decltype(thetaODE), decltype(omegaODE)> solver(thetaODE, omegaODE, stepSize, t, theta0, omega0);

    // Simulation duration
    double endTime = 20.0;

    std::ofstream outfile;
    outfile.open("logs/pendulum_out.txt");
    outfile << g << " " << L << " " << c << std::endl;
    // Simulate and print results
    while (t < endTime) {
        solver.step();
        t = solver.get_t();
        double theta = solver.get_y1();
        double omega = solver.get_y2();

        outfile << t << " " << theta << " " << omega << std::endl;
    }

    outfile.close();
    return 0;
}
