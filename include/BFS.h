#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include <vector>
#include <string>

struct BFSMetrics {
    int nodes_visited;
    double execution_time; // in microseconds
};

class BFS {
public:
    BFS(const Graph& graph);
    std::pair<std::vector<std::string>, BFSMetrics> findPath(const std::string& source, const std::string& target);

private:
    const Graph& graph;
};

#endif // BFS_H 