#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include "DataLoader.h"
#include "UI.h"
using namespace std;

int main() {
    // define number of articles (nodes)
    int numArticles = 4604; // total articles in dataset

    // create a graph with the number of articles
    Graph wikiGraph(numArticles);

    // create DataLoader object
    DataLoader loader;

    // path to dataset file
    string datasetPath = "data/wikispeedia-data.txt";

    // load data into graph
    if(!loader.loadData(datasetPath, wikiGraph)){
        cerr << "Error loading data." << endl;
        return -1;
    }

    // create BFS and DFS objects
    BFS bfs(wikiGraph);
    DFS dfs(wikiGraph);

    // create UI object
    UI userInterface(wikiGraph, bfs, dfs);

    // start the user interface
    userInterface.start();

    return 0;
} 