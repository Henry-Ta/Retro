#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "sort.h"

class Heap_Sort : public Sort
{
public:
    Heap_Sort();

    void heapify(int array[], int size, int i, int original_array[], int original_size);
    void run_sort(int array[], int size, int original_array[], int original_size);
};

#endif // HEAP_SORT_H
