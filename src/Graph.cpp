#include "Graph.hpp"
// #include "Equations.hpp"
// #include <algorithm>

Graph::Graph(GraphInputs initializer) {
    x_range.first = initializer.x_min;
    x_range.second = initializer.x_max;
    y_range.first = initializer.y_min;
    y_range.second = initializer.y_max;
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
    // Calculating screen coordinates:
    
    // double screen_x = mapToRange();
}