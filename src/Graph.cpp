#include "Graph.hpp"

Graph::Graph(int x_min_in, int x_max_in, int y_min_in, int y_max_in) {
    xMin = x_min_in;
    xMax = x_max_in;
    yMin = y_min_in;
    yMax = y_max_in;
}

double Graph::GetXAt(size_t idx) {
    return x_data.at(idx);
}

double Graph::GetYAt(size_t idx) {
    return y_data.at(idx);
}

int Graph::GetXSize() {
    return xMax - xMin;
}

int Graph::GetYSize() {
    return yMax - yMin;
}

int Graph::GetXPos() {
    return pos_x;
}

int Graph::GetYPos() {
    return pos_y;
}

void Graph::Draw() {
    
}