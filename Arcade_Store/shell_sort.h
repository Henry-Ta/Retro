#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "sort.h"

class Shell_Sort : public Sort
{
public:
    Shell_Sort();

    void run_sort(int array[], int size);

    int visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step, int gap, int array_j);
};

#endif // SHELL_SORT_H
