#ifndef DISPLAY_H
#define DISPLAY_H

#include <memory>

#include "Node.h"
#include "Search.h"

class Display {
private:
    Search* search;
public:
    Display(Search* search);
    void print();
};

#endif