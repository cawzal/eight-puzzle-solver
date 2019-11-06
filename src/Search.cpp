#include <cmath>
#include <memory>
#include <string>

#include "Graph.h"
#include "Node.h"
#include "Search.h"

Search::Search(Graph* graph, std::string algorithm) {
    this->graph = graph;
    this->algorithm = algorithm;
}

int Search::heuristic(int state[9]) {
    int total = 0;
    for (int i = 0; i < 9; i++) {
        if (state[i] == 0)
            continue;
        total += std::abs((i / 3) - ((state[i] - 1) / 3)) + std::abs((i % 3) - ((state[i] - 1) % 3));
    }
    return total;
}

std::string Search::getAlgorithm() {
    return this->algorithm;
}

int Search::getCount() {
    return this->count;
}

std::shared_ptr<Node> Search::getResult() {
    return this->result;
}

double Search::getTime() {
    return this->time;
}