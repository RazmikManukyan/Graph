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
    graph.addEdgeBetweenVertices(0, 1);
    graph.addEdgeBetweenVertices(0, 2);
    graph.addEdgeBetweenVertices(0, 3);
    graph.addEdgeBetweenVertices(1,0);
    graph.addEdgeBetweenVertices(1, 4);
    graph.addEdgeBetweenVertices(1, 5);
    graph.addEdgeBetweenVertices(2, 0);
    graph.addEdgeBetweenVertices(2, 5);
    graph.addEdgeBetweenVertices(3, 0);
    graph.addEdgeBetweenVertices(3, 6);
    graph.addEdgeBetweenVertices(4, 1);
    graph.addEdgeBetweenVertices(4, 7);
    graph.addEdgeBetweenVertices(5, 1);
    graph.addEdgeBetweenVertices(5, 2);
    graph.addEdgeBetweenVertices(5, 6);
    graph.addEdgeBetweenVertices(5, 7);
    graph.addEdgeBetweenVertices(6, 3);
    graph.addEdgeBetweenVertices(6, 7);
    graph.addEdgeBetweenVertices(7, 4);
    graph.addEdgeBetweenVertices(7, 5);
    graph.addEdgeBetweenVertices(7, 6);

    //graph.printAdjacencyList();
    //graph.DFS(0);
    graph.printAllPaths(4,3);

    return 0;
}
