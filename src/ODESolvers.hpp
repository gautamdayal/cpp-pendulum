#pragma once

#include <cmath>
#include <map>
#include <string>

enum SolverTypes {
    FORWARD_EULER,
    RUNGE_KUTTA_4
};

std::map<int, std::string> solver_type_names = {{FORWARD_EULER, "Forward Euler"}, {RUNGE_KUTTA_4, "Runge Kutta 4"}};


template <SolverTypes solver, typename Function1, typename Function2>
class ODESolver {
public:
    ODESolver(Function1 in_f1, Function2 in_f2, double in_step_size, double in_t_init, double in_y1_init, double in_y2_init);
    void forward_euler();
    void runge_kutta_4();
    void step();
    double get_t() { return t; }
    double get_y1() { return y1; }
    double get_y2() { return y2; }
private:
    double step_size;
    double t;
    double y1;
    double y2;
    Function1* f1;
    Function2* f2;
};

template <SolverTypes solver, typename Function1, typename Function2>
ODESolver<solver, Function1, Function2>::ODESolver(Function1 in_f1, Function2 in_f2, double in_step_size, double in_t_init, double in_y1_init, double in_y2_init)
    : f1(in_f1), f2(in_f2), step_size(in_step_size), t(in_t_init), y1(in_y1_init), y2(in_y2_init) {}

template <SolverTypes solver, typename Function1, typename Function2>
void ODESolver<solver, Function1, Function2>::forward_euler() {
    double k1_1 = step_size * f1(t, y1, y2);
    double k1_2 = step_size * f2(t, y1, y2);

    y1 += k1_1;
    y2 += k1_2;
    t += step_size;
}

template <SolverTypes solver, typename Function1, typename Function2>
void ODESolver<solver, Function1, Function2>::runge_kutta_4() {
    double k1_1 = step_size * f1(t, y1, y2);
    double k1_2 = step_size * f2(t, y1, y2);
    double k2_1 = step_size * f1(t + step_size / 2, y1 + k1_1 / 2, y2 + k1_2 / 2);
    double k2_2 = step_size * f2(t + step_size / 2, y1 + k1_1 / 2, y2 + k1_2 / 2);
    double k3_1 = step_size * f1(t + step_size / 2, y1 + k2_1 / 2, y2 + k2_2 / 2);
    double k3_2 = step_size * f2(t + step_size / 2, y1 + k2_1 / 2, y2 + k2_2 / 2);
    double k4_1 = step_size * f1(t + step_size, y1 + k3_1, y2 + k3_2);
    double k4_2 = step_size * f2(t + step_size, y1 + k3_1, y2 + k3_2);

    y1 += (k1_1 + 2 * k2_1 + 2 * k3_1 + k4_1) / 6;
    y2 += (k1_2 + 2 * k2_2 + 2 * k3_2 + k4_2) / 6;
    t += step_size;
}

template <SolverTypes solver, typename Function1, typename Function2>
void ODESolver<solver, Function1, Function2>::step() {
    if (solver == FORWARD_EULER) {
        forward_euler();
    }
    else if (solver == RUNGE_KUTTA_4) {
        runge_kutta_4();
    }
}
