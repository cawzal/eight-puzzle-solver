#ifndef SEARCH_H
#define SEARCH_H

#include <memory>
#include <string>

#include "Graph.h"
#include "Node.h"

class Search {
protected:
    Graph* graph;
    std::string algorithm;
    std::shared_ptr<Node> result = nullptr;
    int count = 0;
    double time = 0;
public:
    Search(Graph* graph, std::string algorithm);
    virtual std::shared_ptr<Node> solve() = 0;
    std::string getAlgorithm();
    int getCount();
    std::shared_ptr<Node> getResult();
    double getTime();
protected:
    int heuristic(int state[9]);
};

#endif