#include "UI.h"
#include <iostream>
#include <iomanip>
using namespace std;

// constructor to initialize the UI with graph, bfs, dfs, and article mapper instances
UI::UI(Graph &graph, BFS &bfsAlg, DFS &dfsAlg, ArticleMapper &mapper) 
    : g(graph), bfs(bfsAlg), dfs(dfsAlg), articleMapper(mapper) {}

// retrieves and validates user input for source and target article indices
void UI::getInput(int &source, int &target) {
    string sourceName, targetName;
    
    // prompt the user to enter the source article name
    cout << "enter source article name: ";
    getline(cin, sourceName);
    source = articleMapper.getArticleIndex(sourceName);
    
    // repeatedly prompt until a valid source article is entered
    while (source == -1) {
        cout << "article not found. please try again: ";
        getline(cin, sourceName);
        source = articleMapper.getArticleIndex(sourceName);
    }
    
    // prompt the user to enter the target article name
    cout << "enter target article name: ";
    getline(cin, targetName);
    target = articleMapper.getArticleIndex(targetName);
    
    // repeatedly prompt until a valid target article is entered
    while (target == -1) {
        cout << "article not found. please try again: ";
        getline(cin, targetName);
        target = articleMapper.getArticleIndex(targetName);
    }
}

// displays the sequence of articles constituting the found path
void UI::displayPath(const vector<int> &path) {
    for (size_t i = 0; i < path.size(); i++) {
        cout << articleMapper.getArticleName(path[i]);
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
}

// displays the performance metrics of the specified search algorithm
void UI::displayMetrics(const string &algorithm, const vector<int> &path, 
                       const SearchMetrics &metrics) {
    cout << "\n" << algorithm << " results:" << endl;
    cout << "path: ";
    if (metrics.pathFound) {
        displayPath(path);
    } else {
        cout << "no path found";
    }
    cout << "\npath length: " << metrics.pathLength << endl;
    cout << "nodes visited: " << metrics.nodesVisited << endl;
    cout << "execution time: " << fixed << setprecision(3) 
         << metrics.executionTime << "ms" << endl;
}

// starts the UI by getting user input and performing BFS and DFS searches
void UI::start() {
    int source, target;
    getInput(source, target);
    
    SearchMetrics bfsMetrics, dfsMetrics;
    
    // perform BFS traversal and collect metrics
    vector<int> bfsPath = bfs.traverse(source, target, bfsMetrics);
    displayMetrics("bfs", bfsPath, bfsMetrics);
    
    // perform DFS traversal and collect metrics
    vector<int> dfsPath = dfs.traverse(source, target, dfsMetrics);
    displayMetrics("dfs", dfsPath, dfsMetrics);
} 