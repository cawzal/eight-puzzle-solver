#include <memory>
#include <queue>

#include "SearchBFS.h"

std::shared_ptr<Node> SearchBFS::solve(std::shared_ptr<Node> root) {
    std::queue<std::shared_ptr<Node>> queue;
    queue.push(root);
    root->setVisited(true);
    while (!queue.empty()) {
        std::shared_ptr<Node> front = queue.front(); queue.pop();
        if (front->completed()) {
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