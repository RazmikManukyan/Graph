#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
#include "Vertex.h"
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>

// Definition of the Graph class, which represents a graph data structure.
class Graph {
private:
    std::vector<Vertex> vertices;// Vector to store vertices in the graph.
    std::vector<int> inDegree;// Vector to store in-degrees of vertices.
    std::vector<int> outDegree;// Vector to store out-degrees of vertices.
public:
    // Function prototypes for various graph operations.
    // Details of these functions are implemented in Graph.cpp file.

    void addVertex(int val);// Function to add a new vertex to the graph.
    void addEdgeBetweenVertices(int vertex1, int vertex2);// Function to add an edge between two vertices in the graph.
    void printAdjacencyList(); // Function to print the adjacency list of the graph.
    void printDegrees();// Function to print the in-degree and out-degree of each vertex.

    void BFS(int); // Breadth-first search algorithm starting from a specific vertex.
    void DFS(int);// Depth-first search algorithm starting from a specific vertex.

    void KosorajuDFS(int vertex, std::vector<bool>& visited, std::stack<int>& stack);
    void KosorajuDFS(int vertex, std::vector<bool>& visited, std::vector<int>& component);
    void TarjanDFS(int startVertex, int vertex, std::vector<int>& ids, std::vector<int>& low,
                   std::vector<bool>& onStack, std::stack<int>& stack, std::vector<std::vector<int>>& SCCs);
    std::vector<std::vector<int>> KosorajuSCC();
    std::vector<std::vector<int>> TarjanSCC();
    std::vector<std::vector<int>> transpose();// Function to calculate the transpose of the graph.
    Graph getTranspose();
    std::vector<int> shortestPath(int, int); // Function to find the shortest path between two vertices using BFS.
    int countComponents();// Function to count the connected components in the graph.
    int countNodesAtLevel(int, int);// Function to count the number of nodes at a specific level from a starting vertex.
    void findAllPaths(int, int, std::vector<bool>&, std::vector<int>&);// Function to find all paths between two vertices in the graph.
    void printAllPaths(int, int);// Function to print all paths between two vertices in the graph.
    bool hasCycle();// Function to check if the graph has a cycle.
    bool isCyclicUtil(int, std::vector<bool>&, std::unordered_set<int>&);// Utility function for cycle detection using DFS.

    std::vector<int> topologicalSorting();// Function to perform topological sorting using Kahn's algorithm.
    std::stack<int> topologicalSort();// Function to perform topological sorting using DFS.
    std::stack<int> topologicalSort(int);// Function to perform topological sorting starting from a specific vertex using DFS.
    void topologicalSortUtil(int, std::vector<bool>&, std::stack<int>&);// Utility function for DFS-based topological sorting.To
};

#endif //GRAPH_GRAPH_H
