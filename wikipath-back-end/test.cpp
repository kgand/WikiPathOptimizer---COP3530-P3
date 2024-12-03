#include "include/Graph.h"
#include "BFS.h"
#include "include/DFS.h"
#include <restbed.h>
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using namespace restbed;

// initialize the graph
Graph graph("data/articles.tsv", "data/links.tsv", "data/shortest-path-distance-matrix.txt");
BFS bfs(graph);
DFS dfs(graph);

// format error response
string createErrorResponse(const string& errorMessage) {
    return "{\"error\": \"" + errorMessage + "\"}";
}

// format success response
string createSuccessResponse(const vector<string>& path, int executionTime, int nodesVisited, int pathLength) {
    stringstream response;
    response << "{";
    response << "\"path\": [";
    for (size_t i = 0; i < path.size(); ++i) {
        response << "\"" << path[i] << "\"";
        if (i != path.size() - 1) {
            response << ",";
        }
    }
    response << "],";
    response << "\"metrics\": {";
    response << "\"execution_time\": " << executionTime << ",";
    response << "\"nodes_visited\": " << nodesVisited << ",";
    response << "\"path_length\": " << pathLength;
    response << "}}";
    return response.str();
}

void bfs_handler(const shared_ptr<Session> session) {
    const auto request = session->get_request();
    string source = request->get_query_parameter("source", "");
    string target = request->get_query_parameter("target", "");

    if (source.empty() || target.empty()) {
        string response = createErrorResponse("Missing 'source' or 'target' query parameters.");
        session->close(BAD_REQUEST, response, {
            {"Content-Length", to_string(response.size())},
            {"Content-Type", "application/json"},
            {"Access-Control-Allow-Origin", "*"}
        });
        return;
    }

    auto [path, metrics] = bfs.findPath(source, target);

    string response;
    if (path.empty()) {
        response = createErrorResponse("No path found.");
    } else {
        response = createSuccessResponse(path, metrics.execution_time, metrics.nodes_visited, metrics.path_length);
    }

    session->close(OK, response, {
        {"Content-Length", to_string(response.size())},
        {"Content-Type", "application/json"},
        {"Access-Control-Allow-Origin", "*"}
    });
}

void dfs_handler(const shared_ptr<Session> session) {
    const auto request = session->get_request();
    string source = request->get_query_parameter("source", "");
    string target = request->get_query_parameter("target", "");

    if (source.empty() || target.empty()) {
        string response = createErrorResponse("Missing 'source' or 'target' query parameters.");
        session->close(BAD_REQUEST, response, {
            {"Content-Length", to_string(response.size())},
            {"Content-Type", "application/json"},
            {"Access-Control-Allow-Origin", "*"}
        });
        return;
    }

    auto [path, metrics] = dfs.findPath(source, target);

    string response;
    if (path.empty()) {
        response = createErrorResponse("No path found.");
    } else {
        response = createSuccessResponse(path, metrics.execution_time, metrics.nodes_visited, metrics.path_length);
    }

    session->close(OK, response, {
        {"Content-Length", to_string(response.size())},
        {"Content-Type", "application/json"},
        {"Access-Control-Allow-Origin", "*"}
    });
}

void options_handler(const shared_ptr<Session> session) {
    session->close(OK, "", {
        {"Access-Control-Allow-Origin", "*"},
        {"Access-Control-Allow-Methods", "GET, OPTIONS"},
        {"Access-Control-Allow-Headers", "Content-Type"}
    });
}

int main() {
    auto bfs_resource = make_shared<Resource>();
    bfs_resource->set_path("/bfs");
    bfs_resource->set_method_handler("GET", bfs_handler);
    bfs_resource->set_method_handler("OPTIONS", options_handler);

    auto dfs_resource = make_shared<Resource>();
    dfs_resource->set_path("/dfs");
    dfs_resource->set_method_handler("GET", dfs_handler);
    dfs_resource->set_method_handler("OPTIONS", options_handler);

    // restbed settings
    auto settings = make_shared<Settings>();
    settings->set_port(8070);

    Service service;
    service.publish(bfs_resource);
    service.publish(dfs_resource);
    service.start(settings);

    return 0;
}
