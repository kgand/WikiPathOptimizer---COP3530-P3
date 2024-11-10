#include "BFS.h"
using namespace std;
// Constructor initializing BFS with the given graph
BFS::BFS(const Graph &graph) : g(graph), visited(graph.getVertices(), false), parent(graph.getVertices(), -1) {
    // initialize visited and parent vectors
}

// Function to perform BFS from source to target
vector<int> BFS::traverse(int source, int target) {
    // create a queue for BFS
    queue<int> q;

    // mark the source node as visited and enqueue it
    visited[source] = true;
    q.push(source);

    // loop until the queue is empty
    while(!q.empty()) {
        // dequeue a vertex from the queue
        int current = q.front();
        q.pop();

        // if the target is found, stop BFS
        if(current == target){
            break;
        }

        // get all adjacent vertices of the dequeued vertex
        for(auto const &adj : g.getAdjList()[current]) {
            if(!visited[adj]) {
                // mark as visited and set parent
                visited[adj] = true;
                parent[adj] = current;
                q.push(adj);
            }
        }
    }

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