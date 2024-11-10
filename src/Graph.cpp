#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

// constructor to initialize the graph
Graph::Graph(const string& articlesFile, const string& linksFile, const string& matrixFile) {
    loadArticles(articlesFile);
    // initialize adjacency list with size equal to number of articles
    adjacency_list.resize(id_to_name.size());
    loadLinks(linksFile);
    if (!matrixFile.empty()) {
        loadShortestPathMatrix(matrixFile);
    }
}

// function to load articles from articles.tsv
void Graph::loadArticles(const string& articlesFile) {
    ifstream infile(articlesFile);
    if (!infile.is_open()) {
        cerr << "Error opening articles file: " << articlesFile << endl;
        return;
    }

    string line;
    int id = 0;
    while (getline(infile, line)) {
        // skip comment lines
        if (line.empty() || line[0] == '#') continue;
        
        // store mappings between IDs and names
        id_to_name[id] = line;
        name_to_id[line] = id;
        id++;
    }
    infile.close();
}

// function to add edge between two articles
void Graph::addEdge(const string& source, const string& target) {
    auto src_it = name_to_id.find(source);
    auto tgt_it = name_to_id.find(target);
    
    if (src_it != name_to_id.end() && tgt_it != name_to_id.end()) {
        adjacency_list[src_it->second].push_back(tgt_it->second);
    }
}

// function to get neighbors of an article
vector<string> Graph::getNeighbors(const string& article) const {
    vector<string> neighbors;
    auto it = name_to_id.find(article);
    
    if (it != name_to_id.end()) {
        int id = it->second;
        for (int neighbor_id : adjacency_list[id]) {
            neighbors.push_back(id_to_name.at(neighbor_id));
        }
    }
    
    return neighbors;
}

// function to get distance between two articles
int Graph::getDistance(const string& source, const string& target) const {
    auto src_it = name_to_id.find(source);
    auto tgt_it = name_to_id.find(target);
    
    if (src_it == name_to_id.end() || tgt_it == name_to_id.end() || 
        distance_matrix.empty()) {
        return -1;
    }
    
    return distance_matrix[src_it->second][tgt_it->second];
}

// function to load links from links.tsv
void Graph::loadLinks(const string& linksFile) {
    ifstream infile(linksFile);
    if (!infile.is_open()) {
        cerr << "Error opening links file: " << linksFile << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string source, target;
        if (getline(ss, source, '\t') && getline(ss, target)) {
            addEdge(source, target);
        }
    }
    infile.close();
}

// function to load shortest path matrix
void Graph::loadShortestPathMatrix(const string& matrixFile) {
    ifstream infile(matrixFile);
    if (!infile.is_open()) {
        cerr << "Error opening matrix file: " << matrixFile << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        vector<int> row;
        stringstream ss(line);
        int dist;
        while (ss >> dist) {
            row.push_back(dist);
        }
        if (!row.empty()) {
            distance_matrix.push_back(row);
        }
    }
    infile.close();
}