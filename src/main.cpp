#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include "DataLoader.h"
#include "UI.h"
#include "ArticleMapper.h"
using namespace std;

int main() {
    // create article mapper and load articles
    ArticleMapper articleMapper;
    if (!articleMapper.loadArticles("data/articles.tsv")) {
        cerr << "Error loading articles." << endl;
        return -1;
    }

    // create graph with number of articles
    Graph wikiGraph(articleMapper.size());

    // create and load data
    DataLoader loader;
    if (!loader.loadData("data/wikispeedia-data.txt", wikiGraph)) {
        cerr << "Error loading graph data." << endl;
        return -1;
    }

    // create algorithm objects
    BFS bfs(wikiGraph);
    DFS dfs(wikiGraph);

    // create and start UI
    UI userInterface(wikiGraph, bfs, dfs, articleMapper);
    userInterface.start();

    return 0;
} 