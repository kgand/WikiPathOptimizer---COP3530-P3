#include "ArticleMapper.h"
#include <fstream>
#include <iostream>

bool ArticleMapper::loadArticles(const string &filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Failed to open articles file: " << filePath << endl;
        return false;
    }

    string line;
    // skip header lines
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        
        articles.push_back(line);
        nameToIndex[line] = articles.size() - 1;
    }

    file.close();
    return true;
}

string ArticleMapper::getArticleName(int index) const {
    if (index < 0 || index >= static_cast<int>(articles.size())) {
        return "";
    }
    return articles[index];
}

int ArticleMapper::getArticleIndex(const string &name) const {
    auto it = nameToIndex.find(name);
    return (it != nameToIndex.end()) ? it->second : -1;
}

size_t ArticleMapper::size() const {
    return articles.size();
} 