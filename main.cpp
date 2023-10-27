#include <iostream>
#include "Graph.h"

int main() {
    Graph graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);
    graph.addVertex(7);
    graph.addVertex(8);

    // Add vertices and edges to the graph
    graph.addEdgeBetweenVertices(0, 1);
    graph.addEdgeBetweenVertices(1, 2);
    graph.addEdgeBetweenVertices(2, 0);
    graph.addEdgeBetweenVertices(1, 3);
    graph.addEdgeBetweenVertices(3, 4);
    graph.addEdgeBetweenVertices(4, 5);
    graph.addEdgeBetweenVertices(5, 3);
    graph.addEdgeBetweenVertices(6, 7);
    graph.addEdgeBetweenVertices(7, 8);
    graph.addEdgeBetweenVertices(8, 6);

    std::vector<std::vector<int>> stronglyConnectedComponents = graph.TarjanSCC();

    // Output the strongly connected components
    std::cout << "Strongly Connected Components:\n";
    for (const auto& component : stronglyConnectedComponents) {
        for (int vertex : component) {
            std::cout << vertex << " ";
        }
        std::cout << "\n";
    }

    return 0;
}