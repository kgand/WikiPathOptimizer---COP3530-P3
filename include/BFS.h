#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include <vector>
#include <queue>
using namespace std;
// BFS class to perform Breadth-First Search on the graph
class BFS {
public:
    // Constructor taking a graph reference
    BFS(const Graph &graph);

    // Function to perform BFS from a source node
    vector<int> traverse(int source, int target);

private:
    const Graph &g; // Reference to the graph
    vector<bool> visited; // Track visited nodes
    vector<int> parent; // Track parent nodes for path reconstruction
};

#endif // BFS_H 