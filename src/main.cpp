#include <algorithm>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <map>
#include <memory>
#include <string>

#include "Display.h"
#include "Graph.h"
#include "Search.h"
#include "SearchAStar.h"
#include "SearchIDAStar.h"
#include "SearchIDDFS.h"
#include "SearchBFS.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Error: Inputs not specified\n";
        return 0;
    }

    std::string input = argv[1];
    if (input.length() != 9) {
        std::cout << "Error: Input not valid\n";
        return 0;
    }
    
    int tiles[9];
    int nums[9];
    for (int i = 0; i < 9; i++) {
        nums[i] = std::stoi(input.substr(i, 1));
        tiles[i] = nums[i];
    }
    
    std::sort(nums, nums + 9);
    bool valid = true;
    for (int i = 0; i < 8; i++) {
        if (i != nums[i]) {
            valid = false;
            break;
        }
    }
    
    if (!valid) {
        std::cout << "Error: Input not valid\n";
        return 0;
    }

    std::map<std::string, int> algorithms = {
        {"astar", 1}, {"bfs", 2}, {"idastar", 3}, {"iddfs", 4}
    };
    std::string algorithm = argv[2];
    std::transform(algorithm.begin(), algorithm.end(), algorithm.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    
    auto selection = algorithms.find(algorithm);
    if (selection == algorithms.end()) {
        std::cout << "Error: Invalid algorithm specified\n";
        return 0;
    }

    Graph graph(tiles);
    Search* search;
    switch (selection->second) {
        case 1:
            search = new SearchAStar(&graph);
            break;
        case 2:
            search = new SearchBFS(&graph);
            break;
        case 3:
            search = new SearchIDAStar(&graph);
            break;
        case 4:
            search = new SearchIDDFS(&graph);
            break;
    }
    search->solve();
    
    if (search->getResult().size() == 0) {
        std::cout << "Error: Unable to solve provided configuration\n";
        return 0;
    }

    Display display(search);
    display.print();

    return 0;
};