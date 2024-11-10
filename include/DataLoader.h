#ifndef DATALOADER_H
#define DATALOADER_H

#include "Graph.h"
#include "ArticleMapper.h"
#include <string>

using namespace std;

// dataloader class handles the parsing and loading of wikipedia article data
// into our graph data structure. it acts as a bridge between raw data files
// and our internal graph representation
class DataLoader {
public:
    // loads article relationships from a tsv file into the graph
    // parameters:
    //   - filepath: path to the tsv file containing article relationships
    //   - graph: reference to the graph object to populate
    //   - mapper: reference to articlemapper for name-to-id conversion
    // returns:
    //   - bool indicating success/failure of data loading operation
    bool loadData(const string &filePath, Graph &graph, const ArticleMapper &mapper);
};

#endif // DATALOADER_H 