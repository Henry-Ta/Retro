#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include "sort.h"

class Binary_Insertion_Sort : public Sort
{
public:
    Binary_Insertion_Sort();

    void run_sort(int array[], int size);

    int binarySearch(int array[], int item, int low, int high);
};

#endif // BINARY_INSERTION_SORT_H
