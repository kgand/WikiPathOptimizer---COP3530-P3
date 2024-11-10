#include "DFS.h"
using namespace std;

// Constructor initializing DFS with the given graph
DFS::DFS(const Graph &graph) : g(graph), visited(graph.getVertices(), false), parent(graph.getVertices(), -1) {
    // initialize visited and parent vectors
}

// Helper recursive function for DFS
bool DFS::dfsUtil(int current, int target) {
    // mark the current node as visited
    visited[current] = true;

    // if current node is the target, return true
    if(current == target){
        return true;
    }

    // iterate through all adjacent vertices
    for(auto const &adj : g.getAdjList()[current]) {
        if(!visited[adj]) {
            parent[adj] = current;
            // recursively visit the adjacent node
            if(dfsUtil(adj, target)){
                return true;
            }
        }
    }
    return false;
}

// Function to perform DFS and find path from source to target
vector<int> DFS::traverse(int source, int target) {
    // start DFS from the source node
    dfsUtil(source, target);

    // reconstruct the path from source to target
    vector<int> path;
    int crawl = target;
    path.push_back(crawl);
    while(parent[crawl] != -1) {
        path.push_back(parent[crawl]);
        crawl = parent[crawl];
    }

    // reverse the path to get correct order
    reverse(path.begin(), path.end());

    return path;
} 