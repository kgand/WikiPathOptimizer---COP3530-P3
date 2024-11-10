#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

// this class represents our wikipedia article graph using an adjacency list
class Graph {
public:
    // constructor that takes file paths for articles, links, and an optional shortest path matrix
    Graph(const string& articlesFile, const string& linksFile, const string& matrixFile = "");
    
    // retrieves neighboring articles for a given article
    vector<string> getNeighbors(const string& article) const;
    
    // retrieves the shortest path distance between two articles
    int getDistance(const string& source, const string& target) const;

    // adds a directed edge between two articles in the graph
    void addEdge(const string& source, const string& target);

private:
    // loads article names and assigns unique IDs from the articles file
    void loadArticles(const string& articlesFile);
    
    // loads links between articles from the links file
    void loadLinks(const string& linksFile);
    
    // loads a pre-computed shortest path distance matrix from a file
    void loadShortestPathMatrix(const string& matrixFile);

    // maps for converting between article IDs and names
    unordered_map<int, string> id_to_name;
    unordered_map<string, int> name_to_id;
    
    // adjacency list representation where each list contains neighboring article IDs
    vector<list<int>> adjacency_list;
    
    // matrix storing shortest path distances between articles
    vector<vector<int>> distance_matrix;
};

#endif // graph_h 