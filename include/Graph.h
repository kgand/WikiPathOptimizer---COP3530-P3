#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <string>
using namespace std;

// Graph class to represent Wikipedia articles and navigation paths
class Graph {
public:
    // Constructor to initialize the graph with a given number of nodes
    Graph(int vertices);

    // Function to add an edge between two nodes
    void addEdge(int src, int dest);

    // Function to display the adjacency list
    void displayGraph();

    // Get number of vertices
    int getVertices() const;

    // Get adjacency list
    const vector<list<int>>& getAdjList() const;

private:
    int V; // Number of vertices
    vector<list<int>> adjList; // Adjacency list
};

#endif // GRAPH_H 