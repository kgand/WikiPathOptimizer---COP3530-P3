#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Function to load dataset from file and populate the graph using ArticleMapper
bool DataLoader::loadData(const string &filePath, Graph &graph, const ArticleMapper &mapper) {
    ifstream infile(filePath);
    if(!infile.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return false;
    }

    string line;
    while(getline(infile, line)) {
        // skip comment lines
        if(line.empty() || line[0] == '#') continue;

        stringstream ss(line);
        string src_str, dest_str;

        // read source and destination as strings separated by tab
        if(getline(ss, src_str, '\t') && getline(ss, dest_str, '\t')) {
            // decode URL-encoded strings if necessary
            // Assuming articles.tsv has URL-encoded names as well
            // If not, remove URL decoding

            // get indices from ArticleMapper
            int src = mapper.getArticleIndex(src_str);
            int dest = mapper.getArticleIndex(dest_str);

            if(src != -1 && dest != -1) {
                graph.addEdge(src, dest);
            } else {
                cerr << "Invalid article names in line: " << line << endl;
            }
        }
    }

    infile.close();
    return true;
} 