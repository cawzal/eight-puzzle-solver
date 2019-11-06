#include <memory>
#include <queue>
#include <unordered_set>
#include <vector>

#include "Graph.h"
#include "Node.h"

Graph::Graph(int state[9]) {
    int index = 0;
    for (; index < 9; index++) {
        if (state[index] == 0)
            break;
    }
    this->root = std::make_shared<Node>(state, index);
    this->generate();
}

std::shared_ptr<Node> Graph::getRoot() {
    return this->root;
}

void Graph::generate() {
    this->nodes.insert(this->root);
    std::queue<std::shared_ptr<Node>> queue;
    queue.push(this->root);
    
    while (!queue.empty()) {
        std::shared_ptr<Node> front = queue.front(); queue.pop();
        for (const int& move : moves.at(front->getSpace())) {
            std::shared_ptr<Node> neighbour = std::make_shared<Node>(front->getState(), move);
            neighbour->slide(front->getSpace());
            if (this->nodes.find(neighbour) == this->nodes.end()) {
                this->nodes.insert(neighbour);
                queue.push(neighbour);
            }
        }
    }
    
    for (const std::shared_ptr<Node>& front : this->nodes) {
        for (const int& move : moves.at(front->getSpace())) {
            std::shared_ptr<Node> neighbour = std::make_shared<Node>(front->getState(), move);
            neighbour->slide(front->getSpace());
            auto target = this->nodes.find(neighbour);
            if (target != this->nodes.end()) {
                front->getNeighbours().push_back(*target);
            }
        }
    }
}