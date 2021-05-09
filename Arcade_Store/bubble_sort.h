#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort.h"

class Bubble_Sort:public Sort
{
public:
    Bubble_Sort();

    void run_sort(int array[], int size);               // The main function to implement bubble sort

    /*
    void swap(int *num1, int *num2);

    void print_array(int array[], int size);            // Function to print an array

    void visualize_sort(int array[],int size);          // Visualize sort by displaying dots
    */

};

#endif // BUBBLE_SORT_H
