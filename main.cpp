// ETUDE

#include <iostream>

#include "ODESolvers.hpp"

double f(double t, double y) {
    return std::pow(t, 2);
}



int main() {
    ODESolver<RUNGE_KUTTA_4, decltype(f)> quadratic_solver = 
                    ODESolver<RUNGE_KUTTA_4, decltype(f)>(f, 0.1, 0, 0);
    for (int i = 0; i < 100; i++) {
        std::cout << quadratic_solver.get_t() << " " << quadratic_solver.get_y() << std::endl;
        quadratic_solver.step();
    }
}
