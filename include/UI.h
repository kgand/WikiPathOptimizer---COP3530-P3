#ifndef UI_H
#define UI_H

// include necessary header files for graph operations and search algorithms
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include "ArticleMapper.h"
#include <string>

// use the standard namespace to simplify code
using namespace std;

// define the UI class to handle user interactions and display results
class UI {
public:
    // constructor to initialize ui with graph, bfs, dfs, and article mapper instances
    UI(Graph &graph, BFS &bfsAlg, DFS &dfsAlg, ArticleMapper &mapper);

    // starts the user interface loop
    void start();

private:
    // reference to the graph representing wikipedia articles
    Graph &g;

    // instance of breadth-first search algorithm
    BFS &bfs;

    // instance of depth-first search algorithm
    DFS &dfs;

    // instance of articlemapper to map article names to indices
    ArticleMapper &articleMapper;
    
    // prompts user and retrieves source and target article indices
    void getInput(int &source, int &target);

    // displays the performance metrics of the search algorithm
    void displayMetrics(const string &algorithm, const vector<int> &path, const SearchMetrics &metrics);

    // displays the found path between articles
    void displayPath(const vector<int> &path);
};

#endif // UI_H