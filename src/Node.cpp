#include <memory>
#include <vector>

#include "Node.h"

Node::Node(int state[9], int space) {
    std::copy(state, state + 9, this->state);
    this->space = space;
}

bool Node::completed() {
    for (int i = 0; i < 8; i++) {
        if (this->state[i] != i + 1)
            return false;
    }
    return this->state[8] == 0;
}

void Node::slide(int index) {
    this->state[index] = this->state[this->space];
    this->state[this->space] = 0;
}

std::vector<std::shared_ptr<Node>>& Node::getNeighbours() {
    return this->neighbours;
}

int Node::getCost() {
    return this->cost;
}

void Node::setCost(int cost) {
    this->cost = cost;
}

int Node::getEstimate() {
    return this->estimate;
}

void Node::setEstimate(int estimate) {
    this->estimate = estimate;
}

int Node::getSpace() {
    return this->space;
}

int* Node::getState() {
    return this->state;
};

std::shared_ptr<Node> Node::getParent() {
    return this->parent;
}

void Node::setParent(std::shared_ptr<Node> parent) {
    this->parent = parent;
}

int Node::getVisited() {
    return this->visited;
}

void Node::setVisited(bool visited) {
    this->visited = visited;
}