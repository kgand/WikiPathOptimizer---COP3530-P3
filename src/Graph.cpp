#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

// constructor to initialize the graph
Graph::Graph(const std::string& articlesFile, const std::string& linksFile, const std::string& matrixFile) {
    loadArticles(articlesFile);
    loadLinks(linksFile);
    loadShortestPathMatrix(matrixFile);
}

// function to load articles from articles.tsv
void Graph::loadArticles(const std::string& articlesFile) {
    std::ifstream infile(articlesFile);
    if (!infile.is_open()) {
        std::cerr << "Error opening articles file: " << articlesFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        // Assuming each line has an article ID and name separated by a tab
        std::stringstream ss(line);
        std::string id, name;
        if (std::getline(ss, id, '\t') && std::getline(ss, name)) {
            id_to_name[std::stoi(id)] = name;
            name_to_id[name] = std::stoi(id);
            add_vertex(name, graph);
        }
    }
    infile.close();
}

// function to load links from links.tsv
void Graph::loadLinks(const std::string& linksFile) {
    std::ifstream infile(linksFile);
    if (!infile.is_open()) {
        std::cerr << "Error opening links file: " << linksFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        // Assuming each line has source and target article names separated by a tab
        std::stringstream ss(line);
        std::string source, target;
        if (std::getline(ss, source, '\t') && std::getline(ss, target)) {
            int src_id = name_to_id[source];
            int tgt_id = name_to_id[target];
            add_edge(src_id, tgt_id, graph);
        }
    }
    infile.close();
}

// function to get neighbors (used in BFS and DFS)
std::vector<std::string> Graph::getNeighbors(const std::string& article) const {
    std::vector<std::string> neighbors;
    auto it = name_to_id.find(article);
    if (it == name_to_id.end()) {
        return neighbors;
    }
    int id = it->second;
    auto edge_range = out_edges(id, graph);
    for (auto edge_it = edge_range.first; edge_it != edge_range.second; ++edge_it) {
        int tgt = target(*edge_it, graph);
        neighbors.push_back(id_to_name.at(tgt));
    }
    return neighbors;
}

// Function to load shortest-path distance matrix
void Graph::loadShortestPathMatrix(const std::string& matrixFile) {
    std::ifstream infile(matrixFile);
    if (!infile.is_open()) {
        std::cerr << "Error opening shortest-path distance matrix file: " << matrixFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        // Each line represents distances from a source to all targets
        std::vector<char> distances(line.begin(), line.end());
        distance_matrix.push_back(distances);
    }
    infile.close();
}

// function to get the distance between two articles
int Graph::getDistance(const std::string& source, const std::string& target) const {
    auto it_src = name_to_id.find(source);
    auto it_tgt = name_to_id.find(target);
    if (it_src == name_to_id.end() || it_tgt == name_to_id.end()) {
        return -1; // indicates no path
    }
    int src_id = it_src->second;
    int tgt_id = it_tgt->second;
    if (src_id >= distance_matrix.size() || tgt_id >= distance_matrix[src_id].size()) {
        return -1; // invalid indices
    }
    char dist_char = distance_matrix[src_id][tgt_id];
    if (dist_char == '_') return -1;
    return dist_char - '0';
}