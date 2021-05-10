#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sort.h"

class Insertion_Sort : public Sort
{
public:
    Insertion_Sort();

    void run_sort(int array[], int size);

    int visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step, int key, int array_j);
};

#endif // INSERTION_SORT_H
