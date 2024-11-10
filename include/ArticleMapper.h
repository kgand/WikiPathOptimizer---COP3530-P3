#ifndef ARTICLEMAPPER_H
#define ARTICLEMAPPER_H

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class ArticleMapper {
public:
    // load article names from file
    bool loadArticles(const string &filePath);
    
    // get article name from index
    string getArticleName(int index) const;
    
    // get index from article name
    int getArticleIndex(const string &name) const;
    
    // get total number of articles
    size_t size() const;

private:
    vector<string> articles;  // store article names
    unordered_map<string, int> nameToIndex;  // map names to indices
};

#endif // ARTICLEMAPPER_H 