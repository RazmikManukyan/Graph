# Graph Algorithms Implementation

This C++ project implements various graph algorithms, including breadth-first search (BFS), depth-first search (DFS), shortest path algorithms, cycle detection, and topological sorting. It provides a set of functionalities to work with graph data structures.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Implemented Algorithms](#implemented-algorithms)
- [How to Run](#how-to-run)
- [Contributing](#contributing)
- [License](#license)

## Installation

To use this project, clone the repository to your local machine:

```bash
git clone https://github.com/RazmikManukyan/Graph.git

## Usage

Include the necessary header files in your C++ project to use the implemented graph algorithms. For example:

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

- **Breadth-First Search (BFS)**
- **Depth-First Search (DFS)**
- **Shortest Path Algorithms**
- **Cycle Detection**
- **Topological Sorting**

## How to Run

1. Make sure you have a C++ compiler installed on your system.
2. Clone the repository to your local machine.
3. Include `Graph.h` and `Vertex.h` files in your C++ project.
4. Use the implemented graph algorithms in your project as needed.
5. Compile and run your C++ program.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to create an issue or a pull request.
