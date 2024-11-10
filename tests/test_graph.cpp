#include <iostream>
#include <cassert>
#include "../include/Graph.h"
#include "../include/BFS.h"
#include "../include/DFS.h"
using namespace std;

void testGraphConstruction() {
    Graph g(5);
    assert(g.getVertices() == 5);
    cout << "Graph construction test passed" << endl;
}

void testPathFinding() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    
    BFS bfs(g);
    DFS dfs(g);
    SearchMetrics metrics;
    
    vector<int> bfsPath = bfs.traverse(0, 3, metrics);
    assert(metrics.pathFound);
    assert(bfsPath.size() == 4);
    
    vector<int> dfsPath = dfs.traverse(0, 3, metrics);
    assert(metrics.pathFound);
    assert(dfsPath.size() == 4);
    
    cout << "Pathfinding test passed" << endl;
}

int main() {
    testGraphConstruction();
    testPathFinding();
    cout << "All tests passed!" << endl;
    return 0;
} 