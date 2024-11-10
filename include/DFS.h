#ifndef DFS_H
#define DFS_H

#include "Graph.h"
#include <vector>
using namespace std;

// DFS class to perform Depth-First Search on the graph
class DFS {
public:
    // Constructor taking a graph reference
    DFS(const Graph &graph);

    // Function to perform DFS from a source node
    vector<int> traverse(int source, int target);

private:
    const Graph &g; // Reference to the graph
    vector<bool> visited; // Track visited nodes
    vector<int> parent; // Track parent nodes for path reconstruction

    // Helper function for recursive DFS
    bool dfsUtil(int current, int target);
};

#endif // DFS_H 