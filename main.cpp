// // // ETUDE

#include <iostream>
#include <fstream>
#include <cmath>
#include "ODESolvers.hpp"
#include "raylib.h"

// Constants
constexpr double g = 9.81;
constexpr double L = 2.0;
constexpr double c = 0.25;

constexpr uint16_t kScreenWidth = 1200;
constexpr uint16_t kScreenHeight = 800;

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

double mapToRange(double value, double minFrom, double maxFrom, double minTo, double maxTo) {
    double result = (value - minFrom) * (maxTo - minTo) / (maxFrom - minFrom) + minTo;
    return result;
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
    InitWindow(kScreenWidth, kScreenHeight, "Real Pendulum Simulation");
    SetTargetFPS(60);

    while (t < endTime) {
        solver.step();
        t = solver.get_t();
        double theta = solver.get_y1();
        double omega = solver.get_y2();
        double x_pos = get_x_pos(theta, L);
        double y_pos = get_y_pos(theta, L);
        pos_out << x_pos << " " << y_pos << std::endl;
        outfile << t << " " << theta << " " << omega << std::endl;

        BeginDrawing();
            ClearBackground((Color){245, 245, 245, 255});
            double x_screen = mapToRange(x_pos, -1, 1, 0, 1200);
            double y_screen = mapToRange(y_pos, 1, 3, 0, 800);
            DrawCircle(static_cast<int>(x_screen), static_cast<int>(y_screen), 10, (Color){245, 96, 66, 255});
        EndDrawing();
    }
    CloseWindow();
    outfile.close();
    return 0;
}
