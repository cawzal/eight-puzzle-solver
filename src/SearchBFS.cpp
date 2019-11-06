#include <chrono>
#include <queue>
#include <memory>

#include "Graph.h"
#include "Node.h"
#include "Search.h"
#include "SearchBFS.h"

SearchBFS::SearchBFS(Graph* graph) : Search(graph, "BFS") {};

std::shared_ptr<Node> SearchBFS::solve() {
    auto s = std::chrono::high_resolution_clock::now();

    std::queue<std::shared_ptr<Node>> queue;
    std::shared_ptr<Node> root = this->graph->getRoot();
    root->setVisited(true);
    queue.push(root);

    int counter = 0;
    while (!queue.empty()) {
        std::shared_ptr<Node> front = queue.front(); queue.pop();
        counter++;

        if (front->completed()) {
            auto f = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> t = f - s;

            this->count = counter;
            this->result = front;
            this->time = t.count();

            return front;
        }

        for (const std::shared_ptr<Node>& neighbour : front->getNeighbours()) {
            if (!neighbour->getVisited()) {
                neighbour->setVisited(true);
                neighbour->setParent(front);
                queue.push(neighbour);
            }
        }
    }
    return nullptr;
}