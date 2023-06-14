// // // ETUDE

#include <iostream>

#include "ODESolvers.hpp"

// double f(double t, double y) {
//     return std::pow(t, 2);
// }



// // int main() {
// //     ODESolver<RUNGE_KUTTA_4, decltype(f)> quadratic_solver = 
// //                     ODESolver<RUNGE_KUTTA_4, decltype(f)>(f, 0.1, 0, 0);
// //     for (int i = 0; i < 100; i++) {
// //         std::cout << quadratic_solver.get_t() << " " << quadratic_solver.get_y() << std::endl;
// //         quadratic_solver.step();
// //     }
// // }

// double g = 9.81;
// double L = 5;
// double c = 2;
// double theta = M_PI / 4;
// double omega = 1;

// double thetaODE(double t, double in_omega) {
//     return in_omega;
// }

// double omegaODE(double t, double in_omega) {
//     theta += in_omega * 0.01;
//     double omega_dot = (-2 * c * sqrt(g/L) * in_omega) - (g/L * sin(theta));
//     omega += omega_dot * 0.01;
//     return omega_dot;
// }


// int main() {
//     ODESolver<RUNGE_KUTTA_4, decltype(thetaODE)> theta_solver = ODESolver<RUNGE_KUTTA_4, decltype(thetaODE)>(thetaODE, 0.01, 0, theta);
//     ODESolver<RUNGE_KUTTA_4, decltype(omegaODE)> omega_solver = ODESolver<RUNGE_KUTTA_4, decltype(omegaODE)>(omegaODE, 0.01, 0, omega);
//     for (int i = 0; i < 1000; i++) {
//         theta_solver.step();
//         omega_solver.step();
//         theta = theta_solver.get_y();
//         omega = omega_solver.get_y();

//         double x = L * sin(theta);
//         double y = L * cos(theta);

//         std::cout << theta_solver.get_t() << " " << theta << " " << omega << std::endl;
//     }
// }

#include <iostream>
#include <cmath>
#include "ODESolvers.hpp"

// Constants
const double g = 9.81;
const double L = 2.0;
const double c = 0.5;

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

    // Simulate and print results
    while (t < endTime) {
        solver.step();
        t = solver.get_t();
        double theta = solver.get_y1();
        double omega = solver.get_y2();

        std::cout << t << " " << theta << " " << omega << std::endl;
    }

    return 0;
}
