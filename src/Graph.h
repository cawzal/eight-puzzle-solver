#ifndef GRAPH_H
#define GRAPH_H

#include <memory>
#include <unordered_set>

#include "Node.h"

class Graph {
private:
    std::unordered_set<std::shared_ptr<Node>, NodeHasher, NodeComparator> nodes;
    std::shared_ptr<Node> root;
    const std::vector<std::vector<int>> moves = {
        std::vector<int>{1, 3},
        std::vector<int>{0, 2, 4},
        std::vector<int>{1, 5},
        std::vector<int>{0, 4, 6},
        std::vector<int>{1, 3, 5, 7},
        std::vector<int>{2, 4, 8},
        std::vector<int>{3, 7},
        std::vector<int>{4, 6, 8},
        std::vector<int>{5, 7}
    };
public:
    Graph(int board[9]);
    std::shared_ptr<Node> getRoot();
private:
    void generate();
};

#endif