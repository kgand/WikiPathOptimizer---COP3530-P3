#ifndef UI_H
#define UI_H

#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include <string>
using namespace std;
// UI class to handle user interactions
class UI {
public:
    // Constructor taking references to Graph, BFS, and DFS
    UI(Graph &graph, BFS &bfsAlg, DFS &dfsAlg);

    // Function to start the UI
    void start();

private:
    Graph &g; // Reference to the graph
    BFS &bfs; // Reference to BFS algorithm
    DFS &dfs; // Reference to DFS algorithm

    // Function to get user input for source and target
    void getInput(int &source, int &target);
};

#endif // UI_H 