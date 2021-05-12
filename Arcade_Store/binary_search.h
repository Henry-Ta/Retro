#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "search.h"


class Binary_Search : public Search
{
public:
    Binary_Search();

    void run_search(int array[],int original_array[], int size, int search_node,  int left_node, int right_node);
};

#endif // BINARY_SEARCH_H
