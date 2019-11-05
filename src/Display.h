#ifndef DISPLAY_H
#define DISPLAY_H

#include <memory>

#include "Node.h"

class Display {
public:
    void print(std::shared_ptr<Node> node);
};

#endif