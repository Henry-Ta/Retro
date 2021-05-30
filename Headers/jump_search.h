#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H

#include "search.h"

class Jump_Search : public Search
{
public:
    Jump_Search();

    void run_search(int array[], int size, int search_node);
};

#endif // JUMP_SEARCH_H