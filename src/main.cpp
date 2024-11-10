#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include "DataLoader.h"
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

    // display the graph (optional, can be large)
    // wikiGraph.displayGraph();

    // create BFS and DFS objects
    BFS bfs(wikiGraph);
    DFS dfs(wikiGraph);

    // define source and target
    int source = 0; // Example: Article 0
    int target = 3000; // Example: Article 3000

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

    return 0;
} 