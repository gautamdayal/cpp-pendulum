#include "Graph.hpp"

Graph::Graph() {

}

double Graph::GetXAt(size_t idx) {
    return x_data.at(idx);
}

double Graph::GetYAt(size_t idx) {
    return y_data.at(idx);
}

int Graph::GetXLim() {
    return 0;
}

int Graph::GetYLim() {
    return 0;
}

void Graph::Draw() {
    
}