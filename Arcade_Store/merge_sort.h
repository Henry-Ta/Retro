#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "sort.h"

class Merge_Sort : public Sort
{
public:
    Merge_Sort();

    void merge(int arr[], int l, int m, int r,
               int count_step, int size, int original_array[]);

    void run_sort(int arr[],int l,int r,
                  int size, int origin_array[]);
};

#endif // MERGE_SORT_H
