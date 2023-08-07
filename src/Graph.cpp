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
    DrawRectangle(this->screen_range_x.first, this->screen_range_y.first, 
                this->screen_range_x.second - this->screen_range_x.first, 
                this->screen_range_y.second - this->screen_range_y.first,(Color){173, 255, 231, 255});
    for (size_t i = 0; i < x_data.size(); i++) {
        double x_min = GetVectorMin(x_data);
        double x_max = GetVectorMax(x_data);
        double y_min = GetVectorMin(y_data);
        double y_max = GetVectorMax(y_data);
        double x_screen = mapToRange(x_data.at(i), x_min, x_max, screen_range_x.first, screen_range_x.second);
        double y_screen = mapToRange(y_data.at(i), y_min, y_max, screen_range_y.first, screen_range_y.second);
        DrawPixel(x_screen, y_screen, (Color){0, 0, 0, 255});
    }
}