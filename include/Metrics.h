#ifndef METRICS_H
#define METRICS_H

// struct to store metrics for comparing search algorithms
struct SearchMetrics {
    bool pathFound = false; // whether a path was found
    double executionTime = 0.0; // time taken in milliseconds
    size_t pathLength = 0; // length of path found
    size_t nodesVisited = 0; // number of nodes visited during search
};

#endif // METRICS_H 