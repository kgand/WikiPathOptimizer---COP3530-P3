#include "DFS.h"
#include <algorithm>
using namespace std;

// Constructor initializing DFS with the given graph
DFS::DFS(const Graph &graph) : g(graph), visited(graph.getVertices(), false), parent(graph.getVertices(), -1) {
    // initialize visited and parent vectors
}

// Helper recursive function for DFS
bool DFS::dfsUtil(int current, int target, SearchMetrics &metrics) {
    // mark the current node as visited and increment counter
    visited[current] = true;
    metrics.nodesVisited++;

    // if current node is the target, return true
    if(current == target) {
        metrics.pathFound = true;
        return true;
    }

    // iterate through all adjacent vertices
    for(auto const &adj : g.getAdjList()[current]) {
        if(!visited[adj]) {
            parent[adj] = current;
            // recursively visit the adjacent node
            if(dfsUtil(adj, target, metrics)){
                return true;
            }
        }
    }
    return false;
}

// Function to perform DFS and find path from source to target
vector<int> DFS::traverse(int source, int target, SearchMetrics &metrics) {
    // start timing
    auto start = chrono::high_resolution_clock::now();
    
    // reset visited and parent arrays
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    metrics = SearchMetrics(); // reset metrics
    
    // perform dfs
    dfsUtil(source, target, metrics);
    
    // reconstruct path if found
    vector<int> path;
    if(metrics.pathFound) {
        int crawl = target;
        path.push_back(crawl);
        while(parent[crawl] != -1) {
            path.push_back(parent[crawl]);
            crawl = parent[crawl];
        }
        reverse(path.begin(), path.end());
    }
    
    // calculate metrics
    auto end = chrono::high_resolution_clock::now();
    metrics.executionTime = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    metrics.pathLength = path.size();
    
    return path;
} 