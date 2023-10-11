#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H
#include <vector>

struct Vertex {
    int value;
    std::vector<int> neighbors;

    explicit Vertex(int val):value(val) {}
};

#endif //GRAPH_VERTEX_H
