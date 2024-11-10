#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// constructor to initialize the graph with articles, links, and an optional shortest path matrix
Graph::Graph(const string& articlesFile, const string& linksFile, const string& matrixFile) {
    loadArticles(articlesFile);
    // initialize the adjacency list with a size matching the number of articles
    adjacency_list.resize(id_to_name.size());
    loadLinks(linksFile);
    // load the shortest path matrix if a file path is provided
    if (!matrixFile.empty()) {
        loadShortestPathMatrix(matrixFile);
    }
}

// function to load articles from the specified TSV file
void Graph::loadArticles(const string& articlesFile) {
    ifstream infile(articlesFile);
    // handle file opening errors
    if (!infile.is_open()) {
        cerr << "Error opening articles file: " << articlesFile << endl;
        return;
    }

    string line;
    int id = 0;
    // read each line representing an article name
    while (getline(infile, line)) {
        // skip empty lines and comments
        if (line.empty() || line[0] == '#') continue;
        
        // map article ID to name and vice versa
        id_to_name[id] = line;
        name_to_id[line] = id;
        id++;
    }
    infile.close();
}

// function to add a directed edge from source to target article within the graph
void Graph::addEdge(const string& source, const string& target) {
    auto src_it = name_to_id.find(source);
    auto tgt_it = name_to_id.find(target);
    
    // ensure both source and target articles exist before adding the edge
    if (src_it != name_to_id.end() && tgt_it != name_to_id.end()) {
        adjacency_list[src_it->second].push_back(tgt_it->second);
    }
}

// function to retrieve all neighboring articles for a given article
vector<string> Graph::getNeighbors(const string& article) const {
    vector<string> neighbors;
    auto it = name_to_id.find(article);
    
    // ensure the article exists in the graph
    if (it != name_to_id.end()) {
        int id = it->second;
        // iterate through all adjacent nodes and map their IDs back to names
        for (int neighbor_id : adjacency_list[id]) {
            neighbors.push_back(id_to_name.at(neighbor_id));
        }
    }
    
    return neighbors;
}

// function to get the pre-computed shortest distance between two articles
int Graph::getDistance(const string& source, const string& target) const {
    auto src_it = name_to_id.find(source);
    auto tgt_it = name_to_id.find(target);
    
    // validate the existence of both articles and the availability of the distance matrix
    if (src_it == name_to_id.end() || tgt_it == name_to_id.end() || 
        distance_matrix.empty()) {
        return -1;
    }
    
    // return the distance from the matrix using article indices
    return distance_matrix[src_it->second][tgt_it->second];
}

// function to load links between articles from the specified TSV file
void Graph::loadLinks(const string& linksFile) {
    ifstream infile(linksFile);
    // handle file opening errors
    if (!infile.is_open()) {
        cerr << "Error opening links file: " << linksFile << endl;
        return;
    }

    string line;
    // read each line representing a link between two articles
    while (getline(infile, line)) {
        stringstream ss(line);
        string source, target;
        // parse the source and target article names separated by a tab
        if (getline(ss, source, '\t') && getline(ss, target)) {
            addEdge(source, target);
        }
    }
    infile.close();
}

// function to load the pre-computed shortest path distance matrix from a file
void Graph::loadShortestPathMatrix(const string& matrixFile) {
    ifstream infile(matrixFile);
    // handle file opening errors
    if (!infile.is_open()) {
        cerr << "Error opening matrix file: " << matrixFile << endl;
        return;
    }

    string line;
    // read each line representing a row in the distance matrix
    while (getline(infile, line)) {
        vector<int> row;
        stringstream ss(line);
        int dist;
        // parse each distance value in the row
        while (ss >> dist) {
            row.push_back(dist);
        }
        // add the row to the distance matrix if it's not empty
        if (!row.empty()) {
            distance_matrix.push_back(row);
        }
    }
    infile.close();
}