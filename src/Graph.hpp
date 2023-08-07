#pragma once

#include "raylib.h"
#include <vector>
#include <utility>
#include "Equations.hpp"

struct GraphInputs {
    int screen_x_min;
    int screen_x_max;
    int screen_y_min;
    int screen_y_max;
};

class Graph {
    public:
        Graph(GraphInputs);
        void SetXAt(size_t idx, double data);
        void SetYAt(size_t idx, double data);
        int GetXPos();
        int GetYPos();
        void Draw();
        std::vector<double> x_data;
        std::vector<double> y_data;
    private:
        std::pair<double, double> screen_range_x;
        std::pair<double, double> screen_range_y;

        int pos_x;
        int pos_y;
};