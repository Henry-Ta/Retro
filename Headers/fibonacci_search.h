#ifndef FIBONACCI_SEARCH_H
#define FIBONACCI_SEARCH_H

#include "search.h"

class Fibonacci_Search : public Search
{
public:
    Fibonacci_Search();

    int min(int x, int y);
    void run_search(int array[],int origin_array[], int size, int search_node);
};

#endif // FIBONACCI_SEARCH_H