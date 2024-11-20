#include "../include/ArticleMapper.h"
#include <fstream>
#include <iostream>

using namespace std;

// loads articles from the specified file and maps their names to indices
bool ArticleMapper::loadArticles(const string &filePath) {
    ifstream file(filePath);
    // handle file opening failures
    if (!file.is_open()) {
        cerr << "Failed to open articles file: " << filePath << endl;
        return false;
    }

    string line;
    // read each line representing an article name
    while (getline(file, line)) {
        // skip empty lines and comments marked with '#'
        if (line.empty() || line[0] == '#') continue;
        
        // add the article name to the list and map it to its index
        articles.push_back(line);
        nameToIndex[line] = articles.size() - 1;
    }

    file.close();
    return true;
}

// retrieves the article name corresponding to the given index
string ArticleMapper::getArticleName(int index) const {
    // validate the index to prevent out-of-range errors
    if (index < 0 || index >= static_cast<int>(articles.size())) {
        return "";
    }
    return articles[index];
}

// retrieves the index corresponding to the given article name
int ArticleMapper::getArticleIndex(const string &name) const {
    auto it = nameToIndex.find(name);
    // return the index if the article exists, otherwise return -1
    return (it != nameToIndex.end()) ? it->second : -1;
}

// returns the total number of articles loaded
size_t ArticleMapper::size() const {
    return articles.size();
} 