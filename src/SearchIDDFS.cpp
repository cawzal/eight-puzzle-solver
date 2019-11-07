#include <chrono>
#include <memory>

#include "Graph.h"
#include "Node.h"
#include "Search.h"
#include "SearchIDDFS.h"

SearchIDDFS::SearchIDDFS(Graph* graph) : Search(graph, "IDDFS") {}

void SearchIDDFS::solve() {
    auto s = std::chrono::high_resolution_clock::now();
    
    std::shared_ptr<Node> root = this->graph->getRoot();
    root->setVisited(true);
    const int MAX = 32;
    int depth = 0;
    int counter = 0;
    
    while (depth < MAX) {
        if (this->recurse(root, 0, depth, counter)) {
            auto f = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> t = f - s;
            
            this->count = counter;
            this->time = t.count();
            
            break;
        }
        depth++;
    }
    
    std::vector<std::shared_ptr<Node>> nodes;
    std::shared_ptr<Node> current = this->found;
    while (current != nullptr) {
        nodes.push_back(current);
        current = current->getParent();
    }
    this->result = nodes;
}

bool SearchIDDFS::recurse(std::shared_ptr<Node> node, int depth, int max, int& counter) {
    if (depth > max)
        return false;

    counter++;
    if (node->completed()) {
        this->found = node;
        return true;
    }
    
    for (const std::shared_ptr<Node>& neighbour : node->getNeighbours()) {
        if (!neighbour->getVisited()) {
            neighbour->setVisited(true);
            if (this->recurse(neighbour, depth + 1, max, counter)) {
                neighbour->setParent(node);
                return true;
            }
            neighbour->setVisited(false);
        }
    }
    return false;
}