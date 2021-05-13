#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sort.h"

class Quick_Sort : public Sort
{
public:
    Quick_Sort();

    void run_sort(int array[],int original_array[], int size, int low, int high);

    int partition (int array[], int low, int high,
                   int size, int original_array[]);

    //int visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step, int pivot, int array_j);
};

#endif // QUICK_SORT_H
