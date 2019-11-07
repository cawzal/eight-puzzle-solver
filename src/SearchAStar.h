#ifndef SEARCHASTAR_H
#define SEARCHASTAR_H

#include <memory>

#include "Graph.h"
#include "Node.h"
#include "Search.h"

class SearchAStar : public Search {
public:
    SearchAStar(Graph* graph);
    void solve();
};

struct AStarComparator {
    size_t operator() (const std::shared_ptr<Node>& n1, const std::shared_ptr<Node>& n2) {
        return (n1->getCost() + n1->getEstimate()) > (n2->getCost() + n2->getEstimate());
    }
};

#endif
