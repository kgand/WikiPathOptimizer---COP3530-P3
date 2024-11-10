#ifndef METRICS_H
#define METRICS_H

#include <chrono>

struct SearchMetrics {
    int pathLength;
    double executionTime;
    size_t memoryUsed;
    bool pathFound;
    
    SearchMetrics() : pathLength(0), executionTime(0.0), memoryUsed(0), pathFound(false) {}
};

#endif // METRICS_H 