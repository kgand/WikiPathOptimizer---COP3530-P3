#ifndef METRICS_H
#define METRICS_H

// metrics struct to track search algorithm performance
struct SearchMetrics {
    int nodes_visited = 0;
    double execution_time = 0.0;  // in microseconds
    int path_length = 0;
    bool pathFound = false;
};

// use same metrics structure for both BFS and DFS
typedef SearchMetrics BFSMetrics;
typedef SearchMetrics DFSMetrics;

#endif // METRICS_H 