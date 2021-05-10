#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sort.h"

class Insertion_Sort : public Sort
{
public:
    Insertion_Sort();

    void run_sort(int array[], int size);
};

#endif // INSERTION_SORT_H
