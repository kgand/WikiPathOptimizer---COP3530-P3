#include "BFS.h"
#include <chrono>
using namespace std;

// constructor to initialize bfs with given graph
BFS::BFS(const Graph &graph) : g(graph), visited(graph.getVertices(), false), parent(graph.getVertices(), -1) {}

// main traverse function that uses bfs to find path
vector<int> BFS::traverse(int source, int target, SearchMetrics &metrics) {
    // start timing
    auto start = chrono::high_resolution_clock::now();
    
    // reset arrays and metrics
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    metrics = SearchMetrics();
    
    // create queue for bfs
    queue<int> q;
    visited[source] = true;
    q.push(source);
    metrics.nodesVisited++;
    
    // perform bfs
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        
        if(current == target) {
            metrics.pathFound = true;
            break;
        }
        
        // explore neighbors
        for(auto const &adj : g.getAdjList()[current]) {
            if(!visited[adj]) {
                visited[adj] = true;
                metrics.nodesVisited++;
                parent[adj] = current;
                q.push(adj);
            }
        }
    }
    
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
    
    // calculate final metrics
    auto end = chrono::high_resolution_clock::now();
    metrics.executionTime = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    metrics.pathLength = path.size();
    
    return path;
} 