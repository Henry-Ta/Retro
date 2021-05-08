#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H


class Bubble_Sort
{
public:
    Bubble_Sort();

    void swap(int *num1, int *num2);

    // A function to implement bubble sort
    void run_sort(int array[], int size);

    /* Function to print an array */
    void print_array(int array[], int size);

    // Visualize sort by displaying dots
    void visualize_sort(int array[],int size);

};

#endif // BUBBLE_SORT_H
