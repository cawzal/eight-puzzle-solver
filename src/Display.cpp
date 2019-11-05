#include <iostream>
#include <memory>
#include <stack>

#include "Display.h"

void Display::print(std::shared_ptr<Node> node) {
    std::stack<std::shared_ptr<Node>> nodes;
    std::stack<int> moves;
    std::shared_ptr<Node> current = node;
    
    while (current != nullptr) {
        nodes.push(current);
        if (current->getParent() != nullptr)
            moves.push(current->getState()[current->getParent()->getSpace()]);
        current = current->getParent();
    }
    
    int total = moves.size();
    std::cout << "Moves: " << total << "\n\n";
    
    while (!moves.empty()) {
        node = nodes.top(); nodes.pop();
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
    
    node = nodes.top(); nodes.pop();
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