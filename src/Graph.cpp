#include "Graph.h"
#include <iostream>
using namespace std;

// Constructor to initialize graph with given number of vertices
Graph::Graph(int vertices) : V(vertices), adjList(vertices) {
    if(vertices <= 0) {
        throw invalid_argument("Number of vertices must be positive");
    }
}

// Function to add an edge from src to dest
void Graph::addEdge(int src, int dest) {
    if(src < 0 || src >= V || dest < 0 || dest >= V) {
        cerr << "Invalid vertex indices" << endl;
        return;
    }
    
    // check if edge already exists
    for(const auto &adj : adjList[src]) {
        if(adj == dest) return;
    }
    
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

// Function to display the adjacency list of the graph
void Graph::displayGraph() {
    for(int i = 0; i < V; ++i) {
        cout << "Article " << i << ": ";
        for(auto const &dest : adjList[i]) {
            cout << dest << " -> ";
        }
        cout << "NULL" << endl;
    }
}

// Function to get number of vertices
int Graph::getVertices() const {
    return V;
}

// Function to get the adjacency list
const vector<list<int>>& Graph::getAdjList() const {
    return adjList;
} 