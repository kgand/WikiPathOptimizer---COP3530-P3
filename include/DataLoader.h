#ifndef DATALOADER_H
#define DATALOADER_H
using namespace std;

#include "Graph.h"
#include <string>
#include <fstream>
#include <sstream>

// DataLoader class to load dataset from file into Graph
class DataLoader {
public:
    // Function to load data and populate the graph
    bool loadData(const string &filePath, Graph &graph);
};

#endif // DATALOADER_H 