
```markdown
# Graph Algorithms Implementation

This project implements various graph algorithms in C++. It provides functionalities for creating a graph, adding vertices and edges, performing breadth-first search (BFS), depth-first search (DFS), finding shortest paths, detecting cycles, and more.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Implemented Algorithms](#implemented-algorithms)
- [How to Run](#how-to-run)
- [Contributing](#contributing)

## Installation

Clone the repository to your local machine:

```
git clone https://github.com/RazmikManukyan/Graph.git
```

## Usage

This project provides a C++ implementation of various graph algorithms. You can include the `Graph.h` and `Vertex.h` files in your C++ project to use these algorithms.

Example usage:

```cpp
#include "Graph.h"

int main() {
    // Create a graph object
    Graph graph;

    // Add vertices and edges
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addEdgeBetweenVertices(0, 1);

    // Perform graph operations
    graph.BFS(0);
    graph.DFS(0);

    // More operations...

    return 0;
}
```

## Implemented Algorithms

- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Shortest Path (BFS-based)
- Connected Components Count
- Nodes at Level Count
- All Paths between Two Vertices
- Cycle Detection
- Topological Sorting (Kahn's Algorithm)
- Topological Sorting (DFS-based)

## How to Run

1. Make sure you have a C++ compiler installed on your system.
2. Clone the repository to your local machine.
3. Include `Graph.h` and `Vertex.h` files in your C++ project.
4. Use the implemented graph algorithms in your project as needed.
5. Compile and run your C++ program.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to create an issue or a pull request.
