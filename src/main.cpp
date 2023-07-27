// // // ETUDE

#include <iostream>
#include <fstream>
#include <string>
#include "ODESolvers.hpp"
#include "raylib.h"
#include "Equations.hpp"


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
    // double endTime = 20.0;

    std::ofstream outfile;
    std::ofstream pos_out;
    outfile.open("../logs/pendulum_out.txt");
    pos_out.open("../logs/positions_out.txt");
    outfile << g << " " << L << " " << c << std::endl;
    // pos_out << "x y" << std::endl;
    // Simulate and print results
    InitWindow(kScreenWidth, kScreenHeight, "Real Pendulum Simulation");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
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
            double x_screen = mapToRange(x_pos, -3, 3, 0, kScreenWidth);
            double y_screen = mapToRange(y_pos, 0, 4, 0, kScreenHeight);
            double x0_screen = mapToRange(0, -3, 3, 0, kScreenWidth);
            double y0_screen = mapToRange(0, 0, 4, 0, kScreenHeight);

            DrawLine(x_screen, y_screen, x0_screen, y0_screen, (Color){0, 0, 0, 255});
            DrawCircle(static_cast<int>(x_screen), static_cast<int>(y_screen), 20, (Color){83, 94, 86, 255});

            DrawText("unclechairoh", kScreenWidth-135, kScreenHeight-20, 20, (Color){101, 140, 119, 255});
            DrawText("Real Pendulum Simulation", 20, 20, 35, (Color){3, 135, 120, 255});

            // Constants and data
            DrawText(("g: " + std::to_string(g)).c_str(), 20, 60, 20, (Color){140, 140, 140, 255});
            DrawText(("L: " + std::to_string(L)).c_str(), 20, 80, 20, (Color){140, 140, 140, 255});
            DrawText(("c: " + std::to_string(c)).c_str(), 20, 100, 20, (Color){140, 140, 140, 255});

            DrawText(("x: " + std::to_string(x_pos)).c_str(), 20, 140, 20, (Color){160, 160, 160, 255});
            DrawText(("y: " + std::to_string(y_pos)).c_str(), 20, 160, 20, (Color){160, 160, 160, 255});
            DrawText(("theta: " + std::to_string(theta)).c_str(), 20, 180, 20, (Color){160, 160, 160, 255});
        EndDrawing(); 
    }
    CloseWindow();
    outfile.close();
    return 0;
}