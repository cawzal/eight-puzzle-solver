#include <iomanip>
#include <iostream>
#include <memory>
#include <stack>

#include "Display.h"
#include "Node.h"
#include "Search.h"

Display::Display(Search* search) {
    this->search = search;
}

void Display::print() {
    std::cout << "Algorithm: " << this->search->getAlgorithm() << "\n";
    std::cout << std::fixed << std::setprecision(5) << "Time: " << this->search->getTime() << "s\n";
    std::cout << "Nodes examined: " << this->search->getCount() << "\n";

    std::shared_ptr<Node> node = this->search->getResult();
    std::stack<std::shared_ptr<Node>> states;
    std::stack<int> moves;
    while (node != nullptr) {
        states.push(node);
        if (node->getParent() != nullptr)
            moves.push(node->getState()[node->getParent()->getSpace()]);
        node = node->getParent();
    }
    
    int total = moves.size();
    std::cout << "Moves required: " << total << "\n\n";
    
    while (!moves.empty()) {
        node = states.top(); states.pop();
        int move = moves.top(); moves.pop();
        int* state = node->getState();
        std::cout << "Move: " << total - moves.size() << "\n";
        for (int i = 0; i < 9; i++) {
            if (state[i] == move) {
                std::cout << "[" << state[i] << "]";
            } else {
                std::cout << " " << state[i] << " ";
            }
            if ((i + 1) % 3 == 0) {
                std::cout << "\n";
            }
        }
        std::cout << "\n";
    }
    
    node = states.top(); states.pop();
    std::cout << "Completed\n";
    int* state = node->getState();
    for (int i = 0; i < 9; i++) {
        std::cout << " " << state[i] << " ";
        if ((i + 1) % 3 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}