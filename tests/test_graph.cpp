#include <iostream>
#include "../include/Graph.h"
using namespace std;

int main(){
    // create a graph with 3 nodes
    Graph testGraph(3);
    testGraph.addEdge(0,1);
    testGraph.addEdge(1,2);

    // display the graph
    testGraph.displayGraph();

    return 0;
} 