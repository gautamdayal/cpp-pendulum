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

double get_x_pos(double theta, double L) {
    return L * std::sin(theta);
}

double get_y_pos(double theta, double L) {
    return L * std::cos(theta);
}

int main() {
    // Initial conditions
    double theta0 = 6;
    double omega0 = 0.0;

    // Step size and time
    double stepSize = 0.01;
    double t = 0.0;

    // Create ODESolver objects
    ODESolver<RUNGE_KUTTA_4, decltype(thetaODE), decltype(omegaODE)> solver(thetaODE, omegaODE, stepSize, t, theta0, omega0);

    // Simulation duration
    double endTime = 20.0;

    std::ofstream outfile;
    std::ofstream pos_out;
    outfile.open("logs/pendulum_out.txt");
    pos_out.open("logs/positions_out.txt");
    outfile << g << " " << L << " " << c << std::endl;
    // pos_out << "x y" << std::endl;
    // Simulate and print results
    while (t < endTime) {
        solver.step();
        t = solver.get_t();
        double theta = solver.get_y1();
        double omega = solver.get_y2();
        double x_pos = get_x_pos(theta, L);
        double y_pos = get_y_pos(theta, L);
        pos_out << x_pos << " " << y_pos << std::endl;
        outfile << t << " " << theta << " " << omega << std::endl;
    }

    outfile.close();
    return 0;
}
