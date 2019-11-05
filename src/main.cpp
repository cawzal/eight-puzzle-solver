#include <iostream>
#include <memory>

#include "Display.h"
#include "Graph.h"
#include "SearchBFS.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: Input not specified\n";
        return 0;
    }

    std::string input = argv[1];
    if (input.length() != 9) {
        std::cout << "Error: Input not valid\n";
        return 0;
    }

    int board[9];
    for (int i = 0; i < 9; i++) {
        board[i] = std::stoi(input.substr(i, 1));
    }

    Display display;
    Graph graph(board);
    SearchBFS search;
    std::shared_ptr<Node> node = search.solve(graph.getRoot());
    display.print(node);
    
    return 0;
};