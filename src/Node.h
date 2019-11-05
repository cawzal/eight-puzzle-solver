#ifndef NODE_H
#define NODE_H

#include <memory>
#include <vector>

class Node {
private:
    int state[9];
    int space;
    std::vector<std::shared_ptr<Node>> neighbours;
    bool visited;
    std::shared_ptr<Node> parent;
public:
    Node(int state[9], int space);
    bool completed();
    void set(int index);
    std::vector<std::shared_ptr<Node>>& getNeighbours();
    int* getState();
    int getSpace();
    std::shared_ptr<Node> getParent();
    void setParent(std::shared_ptr<Node> parent);
    int getVisited();
    void setVisited(bool visited);
};

struct NodeHasher {
     size_t operator()(const std::shared_ptr<Node>& node) const {
        int* state = node->getState();
        int result = 1;
        for (int i = 0; i < 9; i++) {
            result = 31 * result + state[i];
        }
        return result;
    }
};

struct NodeComparator {
    size_t operator()(const std::shared_ptr<Node>& l, const std::shared_ptr<Node>& r) const {
        int* statel = l->getState();
        int* stater = r->getState();
        for (int i = 0; i < 9; i++) {
            if (statel[i] != stater[i])
                return false;
        }
        return true;
    }
};

#endif
