#ifndef SEARCH_H
#define SEARCH_H

#include <memory>
#include <string>
#include <vector>

#include "Graph.h"
#include "Node.h"

class Search {
protected:
    Graph* graph;
    std::string algorithm;
    std::vector<std::shared_ptr<Node>> result;
    int count = 0;
    double time = 0;
public:
    Search(Graph* graph, std::string algorithm);
    virtual void solve() = 0;
    std::string getAlgorithm();
    int getCount();
    std::vector<std::shared_ptr<Node>> getResult();
    double getTime();
protected:
    int heuristic(int state[9]);
};

#endif