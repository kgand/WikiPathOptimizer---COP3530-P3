#ifndef DFS_H
#define DFS_H

#include "Graph.h"
#include "Metrics.h"
#include <vector>
#include <string>

using namespace std;

class DFS {
public:
    DFS(const Graph& graph);
    pair<vector<string>, DFSMetrics> findPath(const string& source, const string& target);

private:
    const Graph& graph;
};

#endif // DFS_H 