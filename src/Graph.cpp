#include "Graph.h"
#include <iostream>
using namespace std;

// Constructor to initialize graph with given number of vertices
Graph::Graph(int vertices) : V(vertices), adjList(vertices) {
    // Initialize adjacency list for each vertex
}

// Function to add an edge from src to dest
void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest); // add dest to src's list
    adjList[dest].push_back(src); // assuming undirected graph
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