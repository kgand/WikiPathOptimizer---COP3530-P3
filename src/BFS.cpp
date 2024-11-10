#include "BFS.h"
#include <queue>
#include <unordered_set>
#include <chrono>
#include <algorithm>

// BFS constructor
BFS::BFS(const Graph& graph) : graph(graph) {}

// function to perform BFS and return the path along with metrics
std::pair<std::vector<std::string>, BFSMetrics> BFS::findPath(const std::string& source, const std::string& target) {
    BFSMetrics metrics;
    std::vector<std::string> path;
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;
    std::unordered_map<std::string, std::string> parent;

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    q.push(source);
    visited.insert(source);
    metrics.nodes_visited++;

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        if (current == target) {
            break;
        }

        for (const auto& neighbor : graph.getNeighbors(current)) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
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