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
    graph.addVertex(9);
    graph.addVertex(10);
    graph.addVertex(11);
    graph.addVertex(12);


    graph.addEdgeBetweenVertices(0, 2);
    graph.addEdgeBetweenVertices(1, 0);
    graph.addEdgeBetweenVertices(1, 3);
    graph.addEdgeBetweenVertices(2, 7);
    graph.addEdgeBetweenVertices(2, 4);
    graph.addEdgeBetweenVertices(3, 2);
    graph.addEdgeBetweenVertices(4, 5);
    graph.addEdgeBetweenVertices(5, 6);
    graph.addEdgeBetweenVertices(7, 8);
    graph.addEdgeBetweenVertices(7, 5);
    graph.addEdgeBetweenVertices(8, 9);
    graph.addEdgeBetweenVertices(8, 6);
    graph.addEdgeBetweenVertices(10, 8);
    graph.addEdgeBetweenVertices(11, 8);
    graph.addEdgeBetweenVertices(11, 10);
    graph.addEdgeBetweenVertices(12, 0);
    graph.addEdgeBetweenVertices(12, 2);
    graph.addEdgeBetweenVertices(12, 11);

    std::vector<int> v = graph.topologicalSorting();
    for(int i = 0; i < v.size();++i) {
        std::cout << v[i] << " ";
    }
    //graph.printDegrees();
    //std::stack<int> st = graph.topologicalSort(0);
    //while(!st.empty()) {
    //    std::cout << st.top() << " ";
    //    st.pop();
    //}
    //graph.addEdgeBetweenVertices(0, 1);
    //int c = graph.countNodesAtLevel(1, 3);
    //int count = graph.countComponents();
    //bool b = graph.hasCycle();
    //std::cout << b;
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
    }*/
    //graph.printAdjacencyList();

    return 0;
}
