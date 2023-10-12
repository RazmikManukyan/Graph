#include "Graph.h"

int main() {
    Graph graph;

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addEdgeBetweenVertices(0, 1);
    graph.addEdgeBetweenVertices(1, 2);
    graph.addEdgeBetweenVertices(1,3);
    graph.addEdgeBetweenVertices(4, 0);

    //graph.printAdjacencyList();
    //graph.DFS(0);
    //graph.printAllPaths(4,3);
    /*std::vector<std::vector<int>> t = graph.transpose();
    for(int i = 0; i < t.size(); ++i) {
        std::cout << "Vertex " << i << " is connected to: ";
        for(int j = 0; j < t[i].size(); ++j) {
            std::cout << t[i][j] << " ";
        }
        std::cout << std::endl;
    }/*
    //graph.printAdjacencyList();

    return 0;
}
