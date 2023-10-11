#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
#include "Vertex.h"
#include <queue>
#include <stack>
#include <algorithm>

class Graph {
private:
    std::vector<Vertex> vertices;
public:
    void addVertex(int val);
    void addEdgeBetweenVertices(int vertex1, int vertex2);
    void printAdjacencyList();

    void BFS(int);
    void DFS(int);

    std::vector<int> shortestPath(int, int);
    void findAllPaths(int, int, std::vector<bool>&, std::vector<int>&);
    void printAllPaths(int, int);
};

#endif //GRAPH_GRAPH_H
