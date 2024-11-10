#include "UI.h"
#include <iostream>
using namespace std;
// Constructor initializing UI with graph and algorithms
UI::UI(Graph &graph, BFS &bfsAlg, DFS &dfsAlg) : g(graph), bfs(bfsAlg), dfs(dfsAlg) {
    // constructor body
}

// Function to get user input for source and target articles
void UI::getInput(int &source, int &target){
    cout << "Enter source article number: ";
    cin >> source;
    cout << "Enter target article number: ";
    cin >> target;
}

// Function to start the user interface
void UI::start(){
    int source, target;
    getInput(source, target);

    // perform BFS traversal
    vector<int> bfsPath = bfs.traverse(source, target);
    cout << "BFS Path from " << source << " to " << target << ": ";
    for(auto const &node : bfsPath){
        cout << node << " ";
    }
    cout << endl;

    // perform DFS traversal
    vector<int> dfsPath = dfs.traverse(source, target);
    cout << "DFS Path from " << source << " to " << target << ": ";
    for(auto const &node : dfsPath){
        cout << node << " ";
    }
    cout << endl;
} 