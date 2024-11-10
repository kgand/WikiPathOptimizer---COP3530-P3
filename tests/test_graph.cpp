#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include <cassert>
#include <iostream>

using namespace std;

int main() {
    // create our graph with data files
    Graph graph("data/articles.tsv", "data/links.tsv", "data/shortest-path-distance-matrix.txt");

    // create our search algorithms
    BFS bfs(graph);
    DFS dfs(graph);

    // test case: find path from Algorithm to Computer_science
    string source = "Algorithm";
    string target = "Computer_science";

    // run BFS and check results
    auto bfs_result = bfs.findPath(source, target);
    vector<string> expected_bfs_path = {"Algorithm", "Computer_science"};
    assert(bfs_result.first == expected_bfs_path);
    assert(bfs_result.second.path_length == 2);
    cout << "BFS test passed.\n";

    // run DFS and check results
    auto dfs_result = dfs.findPath(source, target);
    vector<string> expected_dfs_path = {"Algorithm", "Programming_language", "Computer_science"};
    assert(dfs_result.first == expected_dfs_path);
    assert(dfs_result.second.path_length == 3);
    cout << "DFS test passed.\n";

    return 0;
}