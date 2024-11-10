#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

// Helper function to validate path
bool isValidPath(const vector<string>& path, const Graph& graph) {
    if (path.empty()) return false;
    
    // Check each pair of consecutive nodes in the path
    for (size_t i = 0; i < path.size() - 1; i++) {
        vector<string> neighbors = graph.getNeighbors(path[i]);
        // Check if next node in path is a neighbor of current node
        if (find(neighbors.begin(), neighbors.end(), path[i + 1]) == neighbors.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    // Create our graph with data files
    Graph graph("data/articles.tsv", "data/links.tsv", "data/shortest-path-distance-matrix.txt");

    // Create our search algorithms
    BFS bfs(graph);
    DFS dfs(graph);

    // Test case: find path from Algorithm to Computer_science
    string source = "Algorithm";
    string target = "Computer_science";

    // Run BFS and check results
    auto bfs_result = bfs.findPath(source, target);
    vector<string> expected_bfs_path = {"Algorithm", "Computer_science"};
    assert(bfs_result.first == expected_bfs_path);
    assert(bfs_result.second.path_length == 2);
    cout << "BFS test passed.\n";

    // Run DFS and check results
    auto dfs_result = dfs.findPath(source, target);
    
    // Verify that DFS found a path
    assert(!dfs_result.first.empty());
    
    // Verify start and end points
    assert(dfs_result.first.front() == source);
    assert(dfs_result.first.back() == target);
    
    // Verify that the path is valid (each node connects to the next)
    assert(isValidPath(dfs_result.first, graph));
    
    // Verify path length is recorded correctly
    assert(dfs_result.second.path_length == dfs_result.first.size());
    
    cout << "DFS test passed.\n";

    return 0;
}