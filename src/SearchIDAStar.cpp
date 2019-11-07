#include <chrono>
#include <vector>

#include "Graph.h"
#include "Node.h"
#include "Search.h"
#include "SearchIDAStar.h"

SearchIDAStar::SearchIDAStar(Graph* graph) : Search(graph, "IDA*") {}

void SearchIDAStar::solve() {
    auto s = std::chrono::high_resolution_clock::now();

    std::shared_ptr<Node> root = this->graph->getRoot();
    root->setCost(0);
    root->setEstimate(this->heuristic(root->getState()));
    root->setVisited(true);

    const int MAX = 32;
    int depth = 0;
    int counter = 0;
    while (depth < MAX) {
        if (this->recurse(root, depth, counter)) {
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

bool SearchIDAStar::recurse(std::shared_ptr<Node> node, int depth, int& counter) {
    if (node->getCost() + node->getEstimate() > depth)
        return false;

    counter++;
    if (node->getEstimate() == 0) {
        this->found = node;
        return true;
    }
    
    for (const std::shared_ptr<Node>& neighbour : node->getNeighbours()) {
        int cost = node->getCost() + 1;
        if (!neighbour->getVisited()) {
            neighbour->setVisited(true);
            neighbour->setCost(cost);
            neighbour->setEstimate(this->heuristic(neighbour->getState()));
            
            if (this->recurse(neighbour, depth, counter)) {
                neighbour->setParent(node);
                return true;
            }
            neighbour->setVisited(false);
        }
    }
    return false;
}