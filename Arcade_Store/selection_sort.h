#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "sort.h"

class Selection_Sort: public Sort
{
public:
    Selection_Sort();

    void run_sort(int array[], int size);           // The main function to implement selection sort

    //int visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step, int array_min, int array_j);

};

#endif // SELECTION_SORT_H
