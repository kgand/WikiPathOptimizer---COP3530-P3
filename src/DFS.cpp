#include "DFS.h"
#include <stack>
#include <unordered_set>
#include <chrono>
#include <algorithm>

// DFS constructor
DFS::DFS(const Graph& graph) : graph(graph) {}

// function to perform DFS and return the path along with metrics
std::pair<std::vector<std::string>, DFSMetrics> DFS::findPath(const std::string& source, const std::string& target) {
    DFSMetrics metrics;
    std::vector<std::string> path;
    std::stack<std::string> s;
    std::unordered_set<std::string> visited;
    std::unordered_map<std::string, std::string> parent;

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    s.push(source);
    visited.insert(source);
    metrics.nodes_visited++;

    while (!s.empty()) {
        std::string current = s.top();
        s.pop();

        if (current == target) {
            break;
        }

        for (const auto& neighbor : graph.getNeighbors(current)) {
            if (visited.find(neighbor) == visited.end()) {
                s.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current;
                metrics.nodes_visited++;
            }
        }
    }

    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    metrics.execution_time = std::chrono::duration<double, std::micro>(end - start).count();

    // Reconstruct path
    if (visited.find(target) != visited.end()) {
        std::string crawl = target;
        path.push_back(crawl);
        while (parent.find(crawl) != parent.end()) {
            crawl = parent[crawl];
            path.push_back(crawl);
        }
        std::reverse(path.begin(), path.end());
        metrics.path_length = path.size();
    }

    return {path, metrics};
} 