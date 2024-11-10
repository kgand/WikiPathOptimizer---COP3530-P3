#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include <iostream>

using namespace std;

// entry point of the application
int main() {
    // initialize the graph with articles and links data files
    Graph graph("data/articles.tsv", "data/links.tsv");

    // create instances of BFS and DFS algorithms using the initialized graph
    BFS bfs(graph);
    DFS dfs(graph);

    string source, target;

    // prompt the user to enter the name of the source article
    cout << "Enter source article name: ";
    getline(cin, source);
    // prompt the user to enter the name of the target article
    cout << "Enter target article name: ";
    getline(cin, target);

    // execute BFS to find the path from source to target
    auto bfs_result = bfs.findPath(source, target);
    vector<string> bfs_path = bfs_result.first;
    BFSMetrics bfs_metrics = bfs_result.second;

    // execute DFS to find the path from source to target
    auto dfs_result = dfs.findPath(source, target);
    vector<string> dfs_path = dfs_result.first;
    DFSMetrics dfs_metrics = dfs_result.second;

    // display the results obtained from BFS
    cout << "\nBFS Results:\n";
    if (!bfs_path.empty()) {
        cout << "Path: ";
        for (size_t i = 0; i < bfs_path.size(); ++i) {
            cout << bfs_path[i];
            if (i != bfs_path.size() - 1) cout << " -> ";
        }
        cout << "\nPath Length: " << bfs_metrics.path_length;
    } else {
        cout << "No path found using BFS.";
    }
    cout << "\nNodes Visited: " << bfs_metrics.nodes_visited;
    cout << "\nExecution Time: " << bfs_metrics.execution_time << " microseconds\n";

    // display the results obtained from DFS
    cout << "\nDFS Results:\n";
    if (!dfs_path.empty()) {
        cout << "Path: ";
        for (size_t i = 0; i < dfs_path.size(); ++i) {
            cout << dfs_path[i];
            if (i != dfs_path.size() - 1) cout << " -> ";
        }
        cout << "\nPath Length: " << dfs_metrics.path_length;
    } else {
        cout << "No path found using DFS.";
    }
    cout << "\nNodes Visited: " << dfs_metrics.nodes_visited;
    cout << "\nExecution Time: " << dfs_metrics.execution_time << " microseconds\n";

    return 0;
} 