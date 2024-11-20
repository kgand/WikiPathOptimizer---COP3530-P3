#include "../include/Graph.h"
#include "../include/BFS.h"
#include "../include/DFS.h"
#include "../include/UI.h"
#include "../include/ArticleMapper.h"
#include <filesystem> // Requires C++17

#include <iostream>

using namespace std;

// entry point of the application
int main() {
    // Initialize the graph with articles and links data files
    Graph graph("../../data/articles.tsv", "../../data/links.tsv");

    // Initialize the ArticleMapper
    ArticleMapper articleMapper;
    if (!articleMapper.loadArticles("../../data/articles.tsv")) {
        cerr << "Failed to load articles. Exiting." << endl;
        return -1;
    }

    // Create instances of BFS and DFS algorithms using the initialized graph
    BFS bfs(graph);
    DFS dfs(graph);

    // Initialize the UI with the graph, BFS, DFS, and ArticleMapper
    UI ui(graph, bfs, dfs, articleMapper);

    // Start the graphical UI
    ui.start();

    return 0;
}
