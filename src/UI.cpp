#include "UI.h"
#include <iostream>
#include <iomanip>
using namespace std;

UI::UI(Graph &graph, BFS &bfsAlg, DFS &dfsAlg) : g(graph), bfs(bfsAlg), dfs(dfsAlg) {}

void UI::getInput(int &source, int &target) {
    do {
        cout << "Enter source article number (0-" << g.getVertices()-1 << "): ";
        cin >> source;
    } while(source < 0 || source >= g.getVertices());
    
    do {
        cout << "Enter target article number (0-" << g.getVertices()-1 << "): ";
        cin >> target;
    } while(target < 0 || target >= g.getVertices());
}

void UI::displayMetrics(const string &algorithm, const vector<int> &path, const SearchMetrics &metrics) {
    cout << "\n" << algorithm << " Results:" << endl;
    cout << "Path: ";
    if(metrics.pathFound) {
        for(auto const &node : path) {
            cout << node << " ";
        }
    } else {
        cout << "No path found";
    }
    cout << "\nPath length: " << metrics.pathLength;
    cout << "\nExecution time: " << fixed << setprecision(3) << metrics.executionTime << "ms" << endl;
}

void UI::start() {
    int source, target;
    getInput(source, target);
    
    SearchMetrics bfsMetrics, dfsMetrics;
    
    vector<int> bfsPath = bfs.traverse(source, target, bfsMetrics);
    displayMetrics("BFS", bfsPath, bfsMetrics);
    
    vector<int> dfsPath = dfs.traverse(source, target, dfsMetrics);
    displayMetrics("DFS", dfsPath, dfsMetrics);
} 