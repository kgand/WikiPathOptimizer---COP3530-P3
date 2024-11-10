#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
using namespace std;

int main() {
    // create a graph with 5 articles
    Graph wikiGraph(5);

    // add some navigation paths
    wikiGraph.addEdge(0, 1);
    wikiGraph.addEdge(0, 4);
    wikiGraph.addEdge(1, 2);
    wikiGraph.addEdge(1, 3);
    wikiGraph.addEdge(1, 4);
    wikiGraph.addEdge(2, 3);
    wikiGraph.addEdge(3, 4);

    // display the adjacency list
    wikiGraph.displayGraph();

    // create BFS and DFS objects
    BFS bfs(wikiGraph);
    DFS dfs(wikiGraph);

    // define source and target
    int source = 0; // Article 0
    int target = 3; // Article 3

    // perform BFS traversal
    std::vector<int> bfsPath = bfs.traverse(source, target);
    std::cout << "BFS Path from " << source << " to " << target << ": ";
    for(auto const &node : bfsPath){
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // perform DFS traversal
    std::vector<int> dfsPath = dfs.traverse(source, target);
    std::cout << "DFS Path from " << source << " to " << target << ": ";
    for(auto const &node : dfsPath){
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
} 