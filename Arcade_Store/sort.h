#ifndef SORT_H
#define SORT_H

#include <string>
using namespace std;

class Sort
{
public:
    Sort();

    void swap(int *num1, int *num2);
    void print_array(int array[], int size);
    void visualize_sort(int array[], int size);
    int visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step);
};

#endif // SORT_H
