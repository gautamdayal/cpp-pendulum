#pragma once

#include <cmath>

enum SolverTypes {
    FORWARD_EULER,
    RUNGE_KUTTA_4
};

template <SolverTypes solver, typename Function>
class ODESolver {
    public:
        ODESolver(Function in_f, double in_step_size, double in_t_init, double in_y_init);
        void forward_euler();
        void runge_kutta_4();
        void step();
        double get_t() {return t;}
        double get_y() {return y;}
    private:
        double step_size;
        double t;
        double y;
        Function f;
};

template <SolverTypes solver, typename Function>
ODESolver<solver, Function>::ODESolver(Function in_f, double in_step_size, double in_t_init, double in_y_init) {
    f = in_f;
    step_size = in_step_size;
    t = in_t_init;
    y = in_y_init;
}

template <SolverTypes solver, typename Function>
void ODESolver<solver, Function>::forward_euler() {
    y += step_size * f(t, y);
    t += step_size;
}

template <SolverTypes solver, typename Function>
void ODESolver<solver, Function>::runge_kutta_4() {
    double k1 = step_size * f(t, y);
    double k2 = step_size * f(t + step_size / 2, y + k1 / 2);
    double k3 = step_size * f(t + step_size / 2, y + k2 / 2);
    double k4 = step_size * f(t + step_size, y + k3);

    y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    t += step_size;
}

template <SolverTypes solver, typename Function>
void ODESolver<solver, Function>::step() {
    if (solver == FORWARD_EULER) {
        forward_euler();
    } 
    else if (solver == RUNGE_KUTTA_4) {
        runge_kutta_4();
    }
}