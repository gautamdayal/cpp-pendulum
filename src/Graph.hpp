#pragma once

#include "raylib.h"
#include <vector>

class Graph {
    public:
        Graph(int, int, int, int);
        double GetXAt(size_t idx);
        double GetYAt(size_t idx);
        int GetXSize();
        int GetYSize();
        int GetXPos();
        int GetYPos();
        void Draw();
    private:
        std::vector<double> x_data;
        std::vector<double> y_data;
        int xMin;
        int xMax;
        int yMin;
        int yMax;

        int pos_x;
        int pos_y;
};