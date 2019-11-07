#ifndef SEARCHBFS_H
#define SEARCHBFS_H

#include <memory>

#include "Graph.h"
#include "Node.h"
#include "Search.h"

class SearchBFS : public Search {
public:
    SearchBFS(Graph* graph);
    void solve();
};

#endif