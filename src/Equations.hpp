#pragma once
#include <cmath>
// #include <vector>

// Constants
constexpr double g = 30;
constexpr double L = 1.5;
constexpr double c = 0.5;

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

// double GetVectorMax(std::vector<double> input_vec) {
//     double curr_max = (double) INT16_MIN;
//     for (double item : input_vec) {
//         if (item > curr_max) {
//             curr_max = item;
//         }
//     }
//     return curr_max;
// }

// double GetVectorMin(std::vector<double> input_vec) {
//     double curr_min = (double) INT16_MAX;
//     for (double item : input_vec) {
//         if (item < curr_min) {
//             curr_min = item;
//         }
//     }
//     return curr_min;
// }