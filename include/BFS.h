#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include "Metrics.h"
#include <vector>
#include <queue>
using namespace std;

class BFS {
public:
    BFS(const Graph &graph);
    vector<int> traverse(int source, int target, SearchMetrics &metrics);

private:
    const Graph &g;
    vector<bool> visited;
    vector<int> parent;
};

#endif // BFS_H 