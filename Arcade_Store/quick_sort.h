#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sort.h"

class Quick_Sort : public Sort
{
public:
    Quick_Sort();

    void run_sort(int array[],int original_array[], int size, int low, int high);

    int partition (int array[], int low, int high, int size, int original_array[]);
};

#endif // QUICK_SORT_H
