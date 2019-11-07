#ifndef SEARCHIDASTAR_H
#define SEARCHIDASTAR_H

#include <memory>

#include "Graph.h"
#include "Node.h"
#include "Search.h"

class SearchIDAStar : public Search {
private:
    std::shared_ptr<Node> found;
public:
    SearchIDAStar(Graph* graph);
    void solve();
private:
    bool recurse(std::shared_ptr<Node> node, int depth, int& counter);
};

#endif