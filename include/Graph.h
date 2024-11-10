#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

// this class represents our wikipedia article graph using adjacency list
class Graph {
public:
    // constructor that takes file paths for articles and links
    Graph(const string& articlesFile, const string& linksFile, const string& matrixFile = "");
    
    // gets neighboring articles for a given article
    vector<string> getNeighbors(const string& article) const;
    
    // gets shortest path distance between two articles
    int getDistance(const string& source, const string& target) const;

    // adds an edge between two articles
    void addEdge(const string& source, const string& target);

private:
    // loads article names and IDs from file
    void loadArticles(const string& articlesFile);
    
    // loads links between articles from file
    void loadLinks(const string& linksFile);
    
    // loads pre-computed shortest path matrix
    void loadShortestPathMatrix(const string& matrixFile);

    // maps for converting between article names and IDs
    unordered_map<int, string> id_to_name;
    unordered_map<string, int> name_to_id;
    
    // adjacency list representation
    vector<list<int>> adjacency_list;
    
    // matrix storing shortest path distances
    vector<vector<int>> distance_matrix;
};

#endif // GRAPH_H 