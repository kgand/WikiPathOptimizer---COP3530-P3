#include "BFS.h"
using namespace std;

BFS::BFS(const Graph &graph) : g(graph), visited(graph.getVertices(), false), parent(graph.getVertices(), -1) {}

vector<int> BFS::traverse(int source, int target, SearchMetrics &metrics) {
    auto start = chrono::high_resolution_clock::now();
    
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    
    queue<int> q;
    visited[source] = true;
    q.push(source);
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        
        if(current == target) {
            metrics.pathFound = true;
            break;
        }
        
        for(auto const &adj : g.getAdjList()[current]) {
            if(!visited[adj]) {
                visited[adj] = true;
                parent[adj] = current;
                q.push(adj);
            }
        }
    }
    
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
    
    auto end = chrono::high_resolution_clock::now();
    metrics.executionTime = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    metrics.pathLength = path.size();
    
    return path;
} 