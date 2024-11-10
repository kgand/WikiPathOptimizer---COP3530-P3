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
    while(getline(infile, line)) {
        // skip empty lines
        if(line.empty()) continue;
        
        stringstream ss(line);
        string src_str, dest_str;
        
        // read source and destination as strings
        if(getline(ss, src_str, ',') && getline(ss, dest_str, ',')) {
            try {
                int src = stoi(src_str);
                int dest = stoi(dest_str);
                if(src >= 0 && dest >= 0 && src < graph.getVertices() && dest < graph.getVertices()) {
                    graph.addEdge(src, dest);
                }
            } catch(const exception& e) {
                cerr << "Error parsing line: " << line << endl;
                continue;
            }
        }
    }

    infile.close();
    return true;
} 