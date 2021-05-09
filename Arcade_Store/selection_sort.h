#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "sort.h"

class Selection_Sort: public Sort
{
public:
    Selection_Sort();


    void run_sort(int array[], int size);           // The main function to implement selection sort

    /*
    void swap(int *num1, int *num2);

    void print_array(int array[], int size);        // Function to print an array

    void visualize_sort(int array[],int size);      // Visualize sort by displaying dots
    */
};

#endif // SELECTION_SORT_H
