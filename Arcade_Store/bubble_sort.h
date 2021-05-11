#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort.h"

class Bubble_Sort:public Sort
{
public:
    Bubble_Sort();

    void run_sort(int array[], int size);               // The main function to implement bubble sort

    //int visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step, int array_j, int array_j_plus_1);

};

#endif // BUBBLE_SORT_H
