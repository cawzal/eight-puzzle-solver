#ifndef SEARCHIDDFS_H
#define SEARCHIDDFS_H

#include <memory>

#include "Graph.h"
#include "Node.h"
#include "Search.h"

class SearchIDDFS : public Search {
public:
    SearchIDDFS(Graph* graph);
    std::shared_ptr<Node> solve();
private:
    bool recurse(std::shared_ptr<Node> node, int depth, int max, int& counter);
};

#endif