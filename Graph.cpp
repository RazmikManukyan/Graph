#include "Graph.h"

void Graph::addVertex(int val) {
    Vertex newVertex(val);
    vertices.push_back(newVertex);
}

void Graph::addEdgeBetweenVertices(int vertex1, int vertex2) {
    vertices[vertex1].neighbors.push_back(vertex2);
    //vertices[vertex2].neighbors.push_back(vertex1); // For undirected graph
}

void Graph::printAdjacencyList() {
    for(int i = 0; i < vertices.size(); ++i) {
        std::cout << "Vertex " << vertices[i].value << " is connected to: ";
        for(int j = 0; j < vertices[i].neighbors.size(); ++j) {
            std::cout << vertices[i].neighbors[j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::BFS(int start) {
    std::vector<bool> visited(vertices.size(), false);
    std::queue<int> queue;
    visited[start] = true;
    queue.push(start);

    while(!queue.empty()) {
        int current = queue.front();
        std::cout << current << " ";
        queue.pop();

        for(int neighbor : vertices[current].neighbors) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
        std::cout << std::endl;
    }
}

void Graph::DFS(int start) {
    std::vector<bool> visited(vertices.size(), false);
    std::stack<int> stack;
    visited[start] = true;
    stack.push(start);

    while(!stack.empty()) {
        int current = stack.top();
        std::cout << current << " ";
        stack.pop();

        for(int neighbor : vertices[current].neighbors) {
            if(!visited[neighbor]) {
                stack.push(neighbor);
                visited[neighbor] = true;
            }
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> Graph::transpose() {
    int size = vertices.size();
    std::vector<std::vector<int>> transposedGraph(size);

    for(int i = 0; i < size; ++i) {
        for(int vertex : vertices[i].neighbors) {
            transposedGraph[vertex].push_back(i);
        }
    }

    return transposedGraph;
}

std::vector<int> Graph::shortestPath(int vertex1, int vertex2) {
    std::vector<int> parent(vertices.size(), -1);
    std::queue<int> queue;
    queue.push(vertex1);

    while(!queue.empty()) {
        int current = queue.front();
        queue.pop();

        if(current == vertex2) break;

        for(int neighbor : vertices[current].neighbors) {
            if(parent[neighbor] == -1) {
                parent[neighbor] = current;
                queue.push(neighbor);
            }
        }
    }

    std::vector<int> path;
    if(parent[vertex2] != -1) {
        int current = vertex2;
        while(current != vertex1) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(vertex1);
        std::reverse(path.begin(), path.end());
    }
    return path;
}

void Graph::findAllPaths(int current, int target, std::vector<bool> &visited, std::vector<int> &path) {
    visited[current] = true;
    path.push_back(current);

    if (current == target) {
        std::cout << "Path: ";
        for (int vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    } else {
        for (int neighbor : vertices[current].neighbors) {
            if (!visited[neighbor]) {
                findAllPaths(neighbor, target, visited, path);
            }
        }
    }

    // Backtrack
    path.pop_back();
    visited[current] = false;
}

void Graph::printAllPaths(int vertex1, int vertex2) {
    std::vector<bool> visited(vertices.size(), false);
    std::vector<int> path;
    findAllPaths(vertex1, vertex2, visited, path);
}