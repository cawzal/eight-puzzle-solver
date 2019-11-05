#ifndef SEARCHBFS_H
#define SEARCHBFS_H

#include <memory>

#include "Node.h"

class SearchBFS {
public:
    std::shared_ptr<Node> solve(std::shared_ptr<Node> root);
};

#endif