#include <iostream>
#include <cassert>
#include <iomanip>
#include "../include/Graph.h"
#include "../include/BFS.h"
#include "../include/DFS.h"
using namespace std;

// test basic graph construction
void testGraphConstruction() {
    Graph g(5);
    assert(g.getVertices() == 5);
    cout << "graph construction test passed" << endl;
}

// test path finding with both bfs and dfs
void testPathFinding() {
    // create a simple test graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    
    BFS bfs(g);
    DFS dfs(g);
    SearchMetrics bfsMetrics, dfsMetrics;
    
    // test bfs path finding
    vector<int> bfsPath = bfs.traverse(0, 3, bfsMetrics);
    assert(bfsMetrics.pathFound);
    assert(bfsPath.size() == 4);
    
    // test dfs path finding
    vector<int> dfsPath = dfs.traverse(0, 3, dfsMetrics);
    assert(dfsMetrics.pathFound);
    assert(dfsPath.size() == 4);
    
    // compare and display metrics
    cout << "\nPath Finding Metrics Comparison:" << endl;
    cout << fixed << setprecision(3);
    cout << "BFS: Time=" << bfsMetrics.executionTime << "ms, Nodes=" << bfsMetrics.nodesVisited << endl;
    cout << "DFS: Time=" << dfsMetrics.executionTime << "ms, Nodes=" << dfsMetrics.nodesVisited << endl;
    
    cout << "pathfinding test passed" << endl;
}

int main() {
    testGraphConstruction();
    testPathFinding();
    cout << "all tests passed!" << endl;
    return 0;
} 