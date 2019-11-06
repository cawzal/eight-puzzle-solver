#include <chrono>
#include <queue>
#include <memory>
#include <vector>

#include "Graph.h"
#include "Node.h"
#include "Search.h"
#include "SearchAStar.h"

SearchAStar::SearchAStar(Graph* graph) : Search(graph, "A*") {}

std::shared_ptr<Node> SearchAStar::solve() {
    auto s = std::chrono::high_resolution_clock::now();

    std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, AStarComparator> queue;
    std::shared_ptr<Node> root = this->graph->getRoot();
    root->setVisited(true);
    root->setCost(0);
    root->setEstimate(this->heuristic(root->getState()));
    queue.push(root);

    int counter = 0;
    while (!queue.empty()) {
        std::shared_ptr<Node> front = queue.top(); queue.pop();
        counter++;

        if (front->getEstimate() == 0) {
            auto f = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> t = f - s;

            this->count = counter;
            this->result = front;
            this->time = t.count();

            return front;
        }

        for (const std::shared_ptr<Node>& neighbour : front->getNeighbours()) {
            int cost = front->getCost() + 1;
            if (!neighbour->getVisited()) {
                neighbour->setVisited(true);
                neighbour->setParent(front);
                neighbour->setCost(cost);
                neighbour->setEstimate(this->heuristic(neighbour->getState()));
                queue.push(neighbour);
            }
        }
    }
    return nullptr;
}