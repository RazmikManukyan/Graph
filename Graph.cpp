#include "Graph.h"

void Graph::addVertex(int val) {
    Vertex newVertex(val);
    vertices.push_back(newVertex);
    inDegree.push_back(0);// Initialize in-degree for the new vertex.
    outDegree.push_back(0);// Initialize out-degree for the new vertex.
}

void Graph::addEdgeBetweenVertices(int vertex1, int vertex2) {
    vertices[vertex1].neighbors.push_back(vertex2);// Add vertex2 to the neighbors of vertex1.
    //vertices[vertex2].neighbors.push_back(vertex1); // For undirected graph
    outDegree[vertex1]++;// Increase out-degree of vertex1.
    inDegree[vertex2]++;// Increase in-degree of vertex1.
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

void Graph::printDegrees() {
    for(int i = 0; i < vertices.size(); ++i) {
        std::cout << "Vertex " << i << ": In-Degree = " << inDegree[i] << ", Out-Degree = " << outDegree[i] << std::endl;
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

void Graph::KosorajuDFS(int vertex, std::vector<bool> &visited, std::stack<int>& stack) {
    visited[vertex] = true;

    for (int neighbor : vertices[vertex].neighbors) {
        if (!visited[neighbor]) {
            KosorajuDFS(neighbor, visited, stack);
        }
    }

    stack.push(vertex);
}

void Graph::KosorajuDFS(int vertex, std::vector<bool> &visited, std::vector<int> &component) {
    visited[vertex] = true;
    component.push_back(vertex);

    for(int neighbor : vertices[vertex].neighbors) {
        if(!visited[neighbor]) {
            KosorajuDFS(neighbor, visited, component);
        }
    }
}

std::vector<std::vector<int>> Graph::KosorajuSCC() {
    std::vector<bool> visited(vertices.size(), false);
    std::stack<int> stack;

    // First DFS to fill the stack with vertices in order of their finish times
    for(int i = 0; i < vertices.size(); ++i) {
        if(!visited[i]) {
            KosorajuDFS(i, visited, stack);
        }
    }

    // Transpose the graph
    Graph transposedGraph = getTranspose();

    // Reset visited array for the second DFS
    std::fill(visited.begin(), visited.end(), false);

    std::vector<std::vector<int>> stronglyConnectedComponents;

    // Second DFS on the transposed graph to find strongly connected components
    while(!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        if(!visited[vertex]) {
            std::vector<int> component;
            transposedGraph.KosorajuDFS(vertex, visited, component);
            stronglyConnectedComponents.push_back(component);
        }
    }

    return stronglyConnectedComponents;
}



std::vector<std::vector<int>> Graph::TarjanSCC() {
    std::vector<std::vector<int>> SCCs;
    std::vector<int> ids(vertices.size(), -1);
    std::vector<int> low(vertices.size(), 0);
    std::vector<bool> onStack(vertices.size(), false);
    std::stack<int> stack;

    for(int i = 0; i < vertices.size(); ++i) {
        if(ids[i] == -1) {
            TarjanDFS(i, i, ids, low, onStack, stack, SCCs);
        }
    }

    return SCCs;
}

void Graph::TarjanDFS(int startVertex, int vertex, std::vector<int> &ids, std::vector<int> &low,
                      std::vector<bool> &onStack, std::stack<int> &stack, std::vector<std::vector<int>> &SCCs) {

    stack.push(vertex);
    onStack[vertex] = true;
    static int id = 0;
    ids[vertex] = low[vertex] = id++;

    for(int neighbor : vertices[vertex].neighbors) {
        if(ids[neighbor] == -1) {
            TarjanDFS(startVertex, neighbor, ids, low, onStack, stack, SCCs);
        }
        if(onStack[neighbor]){
            low[vertex] = std::min(low[vertex], low[neighbor]);
        }
    }

    if(low[vertex] == ids[vertex]) {
        std::vector<int> scc;
        int stackTop;

        do {
            stackTop = stack.top();
            stack.pop();
            onStack[stackTop] = false;
            scc.push_back(stackTop);
        } while (stackTop != vertex);

        // If the SCC contains more than one vertex or if it is not the start vertex, add it to the result
        if(scc.size() > 1 || stackTop != startVertex) {
            SCCs.push_back(scc);
        }
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

Graph Graph::getTranspose() {
    Graph transposedGraph;

    // Add vertices to the transposed graph
    for(int i = 0; i < vertices.size(); ++i) {
        transposedGraph.addVertex(i);
    }

    // Add reversed edges to the transposed graph
    for(int i = 0; i < vertices.size(); ++i) {
        for(int neighbor : vertices[i].neighbors) {
            transposedGraph.addEdgeBetweenVertices(neighbor, i);
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

int Graph::countComponents() {
    std::vector<bool> visited(vertices.size(), false);
    int components = 0;

    for(int i = 0; i < vertices.size(); ++i) {
        if(!visited[i]) {
            std::stack<int> stack;
            stack.push(i);
            visited[i] = true;

            while (!stack.empty()) {
                int current = stack.top();
                stack.pop();

                for (int neighbor: vertices[current].neighbors) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            components++;
        }
    }
    return components;
}

int Graph::countNodesAtLevel(int start, int targetLevel) {
    std::vector<int> levels(vertices.size(), -1);
    std::queue<int> queue;

    queue.push(start);
    levels[start] = 0;

    while(!queue.empty()) {
        int current = queue.front();
        queue.pop();

        for(int neighbor : vertices[current].neighbors) {
            if(levels[neighbor] == -1) {
                levels[neighbor] = levels[current] + 1;
                queue.push(neighbor);
            }
        }
    }

    int count = 0;
    for(int level : levels) {
        if(level == targetLevel) {
            count++;
        }
    }
    return count;
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

bool Graph::hasCycle() {
    std::vector<bool> visited(vertices.size(), false);
    std::unordered_set<int> recursionStack;

    for(int i = 0; i < vertices.size(); ++i) {
        if(!visited[0] && isCyclicUtil(i, visited, recursionStack)) {
            return true;
        }
    }
    return false;
}

bool Graph::isCyclicUtil(int node, std::vector<bool> &visited, std::unordered_set<int> &recursionStack) {
    visited[node] = true;
    recursionStack.insert(node);

    for(int neighbor : vertices[node].neighbors) {
        if(!visited[neighbor] && isCyclicUtil(neighbor, visited, recursionStack)) {
            return true;
        } else if(recursionStack.count(neighbor)) {
            return true;
        }
    }

    recursionStack.erase(node);
    return false;
}

std::vector<int> Graph::topologicalSorting() {
    int numVertices = vertices.size();
    std::vector<int> InDegree = inDegree;

    std::queue<int> queue;
    for(int i = 0; i < InDegree.size(); ++i) {
        if(InDegree[i] == 0) {
            queue.push(i);
        }
    }
    std::vector<int> result;
    while(!queue.empty()) {
        int current = queue.front();
        queue.pop();
        result.push_back(current);

        for(int neighbor : vertices[current].neighbors) {
            InDegree[neighbor]--;
            if(InDegree[neighbor] == 0) {
                queue.push(neighbor);
            }
        }
    }

    // Check for cycles
    if(result.size() != numVertices) {
        // Graph has a cycle
        return {};
    }
    return result;
}

std::stack<int> Graph::topologicalSort() {
    std::vector<bool> visited(vertices.size(), false);
    std::stack<int> result;

    for(int i = 0; i < vertices.size(); ++i) {
        if(!visited[i]) {
            topologicalSortUtil(i, visited, result);
        }
    }
    return result;
}

std::stack<int> Graph::topologicalSort(int source) {
    std::vector<bool> visited(vertices.size(), false);
    std::stack<int> result;

    topologicalSortUtil(source, visited, result);

    return result;
}

void Graph::topologicalSortUtil(int node, std::vector<bool> &visited, std::stack<int> &result) {
    visited[node] = true;

    for(int neighbor : vertices[node].neighbors) {
        if(!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, result);
        }
    }

    result.push(node);
}

