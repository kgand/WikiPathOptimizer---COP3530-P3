#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include <iostream>

int main() {
    // Initialize graph with articles and links data
    Graph graph("data/articles.tsv", "data/links.tsv");

    // Initialize BFS and DFS with the graph
    BFS bfs(graph);
    DFS dfs(graph);

    std::string source, target;

    // Prompt user for source and target articles
    std::cout << "Enter source article name: ";
    std::getline(std::cin, source);
    std::cout << "Enter target article name: ";
    std::getline(std::cin, target);

    // Perform BFS
    auto bfs_result = bfs.findPath(source, target);
    std::vector<std::string> bfs_path = bfs_result.first;
    BFSMetrics bfs_metrics = bfs_result.second;

    // Perform DFS
    auto dfs_result = dfs.findPath(source, target);
    std::vector<std::string> dfs_path = dfs_result.first;
    DFSMetrics dfs_metrics = dfs_result.second;

    // Display BFS results
    std::cout << "\nBFS Results:\n";
    if (!bfs_path.empty()) {
        std::cout << "Path: ";
        for (size_t i = 0; i < bfs_path.size(); ++i) {
            std::cout << bfs_path[i];
            if (i != bfs_path.size() - 1) std::cout << " -> ";
        }
        std::cout << "\nPath length: " << bfs_metrics.path_length;
    } else {
        std::cout << "No path found using BFS.";
    }
    std::cout << "\nNodes visited: " << bfs_metrics.nodes_visited;
    std::cout << "\nExecution time: " << bfs_metrics.execution_time << " microseconds\n";

    // Display DFS results
    std::cout << "\nDFS Results:\n";
    if (!dfs_path.empty()) {
        std::cout << "Path: ";
        for (size_t i = 0; i < dfs_path.size(); ++i) {
            std::cout << dfs_path[i];
            if (i != dfs_path.size() - 1) std::cout << " -> ";
        }
        std::cout << "\nPath length: " << dfs_metrics.path_length;
    } else {
        std::cout << "No path found using DFS.";
    }
    std::cout << "\nNodes visited: " << dfs_metrics.nodes_visited;
    std::cout << "\nExecution time: " << dfs_metrics.execution_time << " microseconds\n";

    return 0;
} 