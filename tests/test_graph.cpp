#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

// helper function to validate the integrity of a path within the graph
bool isValidPath(const vector<string>& path, const Graph& graph) {
    if (path.empty()) return false;
    
    // iterate through each consecutive pair of nodes in the path
    for (size_t i = 0; i < path.size() - 1; i++) {
        vector<string> neighbors = graph.getNeighbors(path[i]);
        // verify that the next node in the path is a direct neighbor of the current node
        if (find(neighbors.begin(), neighbors.end(), path[i + 1]) == neighbors.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    // initialize the graph with provided data files
    Graph graph("data/articles.tsv", "data/links.tsv", "data/shortest-path-distance-matrix.txt");

    // create instances of BFS and DFS algorithms using the initialized graph
    BFS bfs(graph);
    DFS dfs(graph);

    // define test case articles: source and target
    string source = "Algorithm";
    string target = "Computer_science";

    // execute BFS to find the path between source and target
    auto bfs_result = bfs.findPath(source, target);
    vector<string> expected_bfs_path = {"Algorithm", "Computer_science"};
    // assert that BFS found the expected path
    assert(bfs_result.first == expected_bfs_path);
    // verify that BFS recorded the correct path length
    assert(bfs_result.second.path_length == 2);
    cout << "BFS Test Passed.\n";

    // execute DFS to find the path between source and target
    auto dfs_result = dfs.findPath(source, target);
    
    // ensure that DFS found a non-empty path
    assert(!dfs_result.first.empty());
    
    // confirm that the path starts with the source and ends with the target
    assert(dfs_result.first.front() == source);
    assert(dfs_result.first.back() == target);
    
    // validate the continuity of the path within the graph
    assert(isValidPath(dfs_result.first, graph));
    
    // check that DFS correctly recorded the path length
    assert(dfs_result.second.path_length == dfs_result.first.size());
    
    cout << "DFS Test Passed.\n";

    return 0;
}