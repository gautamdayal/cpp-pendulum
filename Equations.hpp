#include <cmath>

// Constants
constexpr double g = 20;
constexpr double L = 2.0;
constexpr double c = 0.1;

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