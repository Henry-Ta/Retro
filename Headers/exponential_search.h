#ifndef EXPONENTIAL_SEARCH_H
#define EXPONENTIAL_SEARCH_H

#include "search.h"

class Exponential_Search : public Search
{
public:
    Exponential_Search();

    void run_binary_search(int array[],int original_array[], int size, int search_node, int left_node, int right_node, int count_step, bool found_node);
    
    void run_search(int array[],int origin_array[], int size, int search_node);
};

#endif // EXPONENTIAL_SEARCH_H