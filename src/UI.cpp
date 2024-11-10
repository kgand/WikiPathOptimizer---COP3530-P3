#include "UI.h"
#include <iostream>
#include <iomanip>
using namespace std;

UI::UI(Graph &graph, BFS &bfsAlg, DFS &dfsAlg, ArticleMapper &mapper) 
    : g(graph), bfs(bfsAlg), dfs(dfsAlg), articleMapper(mapper) {}

void UI::getInput(int &source, int &target) {
    string sourceName, targetName;
    
    cout << "Enter source article name: ";
    getline(cin, sourceName);
    source = articleMapper.getArticleIndex(sourceName);
    
    while (source == -1) {
        cout << "Article not found. Please try again: ";
        getline(cin, sourceName);
        source = articleMapper.getArticleIndex(sourceName);
    }
    
    cout << "Enter target article name: ";
    getline(cin, targetName);
    target = articleMapper.getArticleIndex(targetName);
    
    while (target == -1) {
        cout << "Article not found. Please try again: ";
        getline(cin, targetName);
        target = articleMapper.getArticleIndex(targetName);
    }
}

void UI::displayPath(const vector<int> &path) {
    for (size_t i = 0; i < path.size(); i++) {
        cout << articleMapper.getArticleName(path[i]);
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
}

void UI::displayMetrics(const string &algorithm, const vector<int> &path, 
                       const SearchMetrics &metrics) {
    cout << "\n" << algorithm << " Results:" << endl;
    cout << "Path: ";
    if (metrics.pathFound) {
        displayPath(path);
    } else {
        cout << "No path found";
    }
    cout << "\nPath length: " << metrics.pathLength << endl;
    cout << "Nodes visited: " << metrics.nodesVisited << endl;
    cout << "Execution time: " << fixed << setprecision(3) 
         << metrics.executionTime << "ms" << endl;
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