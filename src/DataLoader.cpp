#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// implementation of the data loading functionality
// this function reads a tsv file containing article relationships
// and populates the graph structure accordingly
bool DataLoader::loadData(const string &filePath, Graph &graph, const ArticleMapper &mapper) {
    // attempt to open the data file using ifstream for efficient file handling
    ifstream infile(filePath);
    if(!infile.is_open()) {
        cerr << "Critical Error: Failed to open data file: " << filePath << endl;
        return false;
    }

    string line;
    // process the file line by line
    while(getline(infile, line)) {
        // skip empty lines and comments (marked with #)
        if(line.empty() || line[0] == '#') continue;

        // use stringstream for efficient string parsing
        stringstream ss(line);
        string src_str, dest_str;

        // parse tab-separated values: source_article <tab> destination_article
        if(getline(ss, src_str, '\t') && getline(ss, dest_str, '\t')) {
            // convert article names to internal indices using mapper
            int src_vertex = mapper.getArticleIndex(src_str);
            int dest_vertex = mapper.getArticleIndex(dest_str);

            // validate indices and add edge to graph if valid
            if(src_vertex != -1 && dest_vertex != -1) {
                graph.addEdge(src_vertex, dest_vertex);
            }
        }
    }

    infile.close();
    return true;
} 