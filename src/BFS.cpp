#include "../include/BFS.h"
#include <queue>
#include <unordered_set>
#include <chrono>
#include <algorithm>
#include <ratio>

using namespace std;

// BFS constructor
BFS::BFS(const Graph& graph) : graph(graph) {}

// function to perform BFS and return the path along with metrics
pair<vector<string>, BFSMetrics> BFS::findPath(const string& source, const string& target) {
    BFSMetrics metrics;
    vector<string> path;
    queue<string> q;
    unordered_set<string> visited;
    unordered_map<string, string> parent;

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    q.push(source);
    visited.insert(source);
    metrics.nodes_visited++;

    while (!q.empty()) {
        string current = q.front();
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

    // End timing and calculate duration in microseconds
    auto end = chrono::high_resolution_clock::now();
    metrics.execution_time = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Reconstruct path
    if (visited.find(target) != visited.end()) {
        string crawl = target;
        path.push_back(crawl);
        while (parent.find(crawl) != parent.end()) {
            crawl = parent[crawl];
            path.push_back(crawl);
        }
        reverse(path.begin(), path.end());
        metrics.path_length = path.size();
    }

    return {path, metrics};
} 