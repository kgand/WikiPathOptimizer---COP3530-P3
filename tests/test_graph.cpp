#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include <cassert>
#include <iostream>

int main() {
    // Initialize graph with test data
    Graph graph("data/articles.tsv", "data/links.tsv");

    // Initialize BFS and DFS
    BFS bfs(graph);
    DFS dfs(graph);

    // Test case: Algorithm to Computer_science
    std::string source = "Algorithm";
    std::string target = "Computer_science";

    auto bfs_result = bfs.findPath(source, target);
    std::vector<std::string> expected_bfs_path = {"Algorithm", "Computer_science"};
    assert(bfs_result.first == expected_bfs_path);
    assert(bfs_result.second.path_length == 2);
    std::cout << "BFS test passed.\n";

    auto dfs_result = dfs.findPath(source, target);
    std::vector<std::string> expected_dfs_path = {"Algorithm", "Programming_language", "Computer_science"};
    assert(dfs_result.first == expected_dfs_path);
    assert(dfs_result.second.path_length == 3);
    std::cout << "DFS test passed.\n";

    return 0;
}