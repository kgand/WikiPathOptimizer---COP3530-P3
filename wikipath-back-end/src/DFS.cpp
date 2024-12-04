#include "DFS.h"
#include <stack>
#include <unordered_set>
#include <chrono>
#include <algorithm>

using namespace std;

// DFS constructor
DFS::DFS(const Graph& graph) : graph(graph) {}

// function to perform DFS and return the path along with metrics
pair<vector<string>, DFSMetrics> DFS::findPath(const string& source, const string& target) {
    DFSMetrics metrics;
    vector<string> path;
    stack<string> s;
    unordered_set<string> visited;
    unordered_map<string, string> parent;

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    s.push(source);
    visited.insert(source);
    metrics.nodes_visited++;

    while (!s.empty()) {
        string current = s.top();
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