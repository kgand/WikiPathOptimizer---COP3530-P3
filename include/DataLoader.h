#ifndef DATALOADER_H
#define DATALOADER_H

#include "Graph.h"
#include "ArticleMapper.h"
#include <string>

class DataLoader {
public:
    // Function to load dataset from file and populate the graph using ArticleMapper
    bool loadData(const std::string &filePath, Graph &graph, const ArticleMapper &mapper);
};

#endif // DATALOADER_H 