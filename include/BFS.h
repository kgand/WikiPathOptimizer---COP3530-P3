#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include <vector>
#include <string>
#include <utility>
#include "Metrics.h"

using namespace std;

class BFS {
public:
    // constructor takes our graph
    BFS(const Graph& graph);
    
    // finds path between two articles using BFS
    pair<vector<string>, BFSMetrics> findPath(const string& source, const string& target);

private:
    const Graph& graph;  // reference to our graph
};

#endif // BFS_H 