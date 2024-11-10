#ifndef DFS_H
#define DFS_H

#include "Graph.h"
#include <vector>
#include <string>

struct DFSMetrics {
    int nodes_visited;
    double execution_time; // in microseconds
};

class DFS {
public:
    DFS(const Graph& graph);
    std::pair<std::vector<std::string>, DFSMetrics> findPath(const std::string& source, const std::string& target);

private:
    const Graph& graph;
};

#endif // DFS_H 