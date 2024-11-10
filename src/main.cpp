#include <iostream>
#include "Graph.h"
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

    return 0;
} 