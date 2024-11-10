#ifndef UI_H
#define UI_H

#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include "ArticleMapper.h"
#include <string>
using namespace std;

class UI {
public:
    UI(Graph &graph, BFS &bfsAlg, DFS &dfsAlg, ArticleMapper &mapper);
    void start();

private:
    Graph &g;
    BFS &bfs;
    DFS &dfs;
    ArticleMapper &articleMapper;
    
    void getInput(int &source, int &target);
    void displayMetrics(const string &algorithm, const vector<int> &path, 
                       const SearchMetrics &metrics);
    void displayPath(const vector<int> &path);
};

#endif // UI_H 