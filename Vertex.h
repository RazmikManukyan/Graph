#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H
#include <vector>

// Definition of a Vertex structure representing a node in the graph.
struct Vertex {
    int value;// The value associated with the vertex.
    std::vector<int> neighbors;// Vector to store indices of neighboring vertices.

    // Constructor to initialize the vertex with a given value.
    explicit Vertex(int val):value(val) {}
};

#endif //GRAPH_VERTEX_H
