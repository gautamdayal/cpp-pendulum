// ETUDE

#include <iostream>

#include "ODESolvers.hpp"

double f(double t, double y) {
    return std::pow(t, 2);
}



int main() {
    std::cout << "hello world" << std::endl;
    ODESolver<FORWARD_EULER, double (*)(double, double)> quadratic_solver = ODESolver<FORWARD_EULER, double (*)(double, double)>((double (*)(double, double))f, 0.1, 0, 0);
    for (int i = 0; i < 100; i++) {
        std::cout << quadratic_solver.get_t() << " " << quadratic_solver.get_y() << std::endl;
        quadratic_solver.step();
    }
}