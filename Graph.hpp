#pragma once

#include "raylib.h"
#include <vector>

class Graph {
    public:
        Graph();
        double GetXAt(size_t idx);
        double GetYAt(size_t idx);
        int GetXLim();
        int GetYLim();
    private:
        std::vector<double> x_data;
        std::vector<double> y_data;
        int x_axis_size;
        int y_axis_size;
};