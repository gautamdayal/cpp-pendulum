#pragma once

#include <cmath>

enum SolverTypes {
    FORWARD_EULER,
    RUNGE_KUTTA_4
};

template <SolverTypes solver, typename Function>
class ODESolver {
    public:
        ODESolver(double in_step_size, double in_t_init, double in_y_init);
        void forward_euler();
        void runge_kutta_4();
        void step();
    private:
        double step_size;
        double t;
        double y;
};

template <SolverTypes solver, typename Function>
ODESolver<solver, Function>::ODESolver(double in_step_size, double in_t_init, double in_y_init) {
    step_size = in_step_size;
    t = in_t_init;
    y = in_y_init;
}

template <SolverTypes solver, typename Function>
void ODESolver<solver, Function>::forward_euler() {
    t += step_size;
    y += step_size * 1;
}

template <SolverTypes solver, typename Function>
void ODESolver<solver, Function>::runge_kutta_4() {

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