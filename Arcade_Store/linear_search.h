#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include "search.h"

class Linear_Search : public Search
{
public:
    Linear_Search();

    void run_search(int array[], int size, int search_node);
};

#endif // LINEAR_SEARCH_H
