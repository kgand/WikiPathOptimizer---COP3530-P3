#include "DataLoader.h"
#include <iostream>
using namespace std;

// Function to load dataset from file and populate the graph
bool DataLoader::loadData(const string &filePath, Graph &graph) {
    ifstream infile(filePath);
    if(!infile.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return false;
    }

    string line;
    // read each line representing an edge
    while(getline(infile, line)) {
        stringstream ss(line);
        int src, dest;
        // assume each line has source and destination separated by space
        ss >> src >> dest;
        graph.addEdge(src, dest);
    }

    infile.close();
    return true;
} 