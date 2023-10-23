#include "Graph.h"

int main() {
    Graph graph;

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);

    graph.addEdgeBetweenVertices(0, 1);
    graph.addEdgeBetweenVertices(0, 2);
    graph.addEdgeBetweenVertices(1, 0);
    graph.addEdgeBetweenVertices(1, 4);
    graph.addEdgeBetweenVertices(2, 3);
    graph.addEdgeBetweenVertices(3, 4);
    graph.addEdgeBetweenVertices(4, 2);
    graph.addEdgeBetweenVertices(4, 5);

    //std::vector<int> v = graph.topologicalSorting();
    //for(int i = 0; i < v.size();++i) {
    //    std::cout << v[i] << " ";
    //}

    std::vector<std::vector<int>> SCC = graph.KosorajuSCC();
    std::cout << "Strongly Connected Components:" << std::endl;
    for (const auto& component : SCC) {
        for (int vertex : component) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
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
