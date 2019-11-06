#ifndef SEARCHIDASTAR_H
#define SEARCHIDASTAR_H

#include <memory>

#include "Graph.h"
#include "Node.h"
#include "Search.h"

class SearchIDAStar : public Search {
public:
    SearchIDAStar(Graph* graph);
    std::shared_ptr<Node> solve();
private:
    bool recurse(std::shared_ptr<Node> node, int depth, int& counter);
};

#endif