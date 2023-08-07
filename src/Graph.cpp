#include "Graph.hpp"

// #include <algorithm>

Graph::Graph(GraphInputs initializer) {
    screen_range_x.first = initializer.screen_x_min;
    screen_range_x.second = initializer.screen_x_max;
    screen_range_y.first = initializer.screen_y_min;
    screen_range_y.second = initializer.screen_y_max;
}

void Graph::SetXAt(size_t idx, double data) {
    x_data[idx] = data;
}

void Graph::SetYAt(size_t idx, double data) {
    y_data[idx] = data;
}

int Graph::GetXPos() {
    return pos_x;
}

int Graph::GetYPos() {
    return pos_y;
}

void Graph::Draw() {
    // DrawRectangle(1000, 600, 200, 200, (Color){173, 255, 231, 255});

    DrawRectangle(this->screen_range_x.first, this->screen_range_y.first, 
                this->screen_range_x.second - this->screen_range_x.first, 
                this->screen_range_y.second - this->screen_range_y.first,(Color){173, 255, 231, 255});
    double x_prev, y_prev;
    double x_min, y_min = (double) INT16_MAX;
    double x_max, y_max = (double) INT16_MIN;
    for (size_t i = 0; i < x_data.size(); i++) {
        if (x_data.at(i) > x_max) {
            x_max = x_data.at(i);
        }
        if (x_data.at(i) < x_min) {
            x_min = x_data.at(i);
        }
        if (y_data.at(i) > y_max) {
            y_max = y_data.at(i);
        }
        if (y_data.at(i) < y_min) {
            y_min = y_data.at(i);
        }

        double x_screen = mapToRange(x_data.at(i), x_min, x_max, screen_range_x.first, screen_range_x.second);
        double y_screen = mapToRange(y_data.at(i), y_min, y_max, screen_range_y.first, screen_range_y.second);
        double x_prev = x_screen;
        double y_prev = y_screen;

        DrawPixel(x_screen, y_screen, (Color){0, 0, 0, 255});
    }
}