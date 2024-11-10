#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

// constructor to initialize the graph
Graph::Graph(const std::string& articlesFile, const std::string& linksFile) {
    loadArticles(articlesFile);
    loadLinks(linksFile);
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