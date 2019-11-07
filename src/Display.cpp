#include <iomanip>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>

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

    std::vector<std::shared_ptr<Node>> nodes = this->search->getResult();
    std::cout << "Moves required: " << nodes.size() - 1<< "\n\n";

    for (int i = nodes.size() - 1; i >= 0; i--) {
        int* state = nodes.at(i)->getState();
        if (i != 0) {
            std::cout << "Move: " << i << "\n";
            int move = nodes.at(i - 1)->getState()[nodes.at(i)->getSpace()];
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
        } else {
            std::cout << "Completed\n";
            for (int i = 0; i < 9; i++) {
                std::cout << " " << state[i] << " ";
                if ((i + 1) % 3 == 0) {
                    std::cout << "\n";
                }
            }
        }
        std::cout << "\n";
    }
}