#ifndef SEARCH_H
#define SEARCH_H

#include <string>
using namespace std;

class Search
{
public:
    Search();

    void swap(int *num1, int *num2);
    void print_array(int array[], int size);
    void visualize_original_array(int array[], int size);
    void visualize_search(int array[], int size, int search_node,int check_node);
    int visualize_processing_search(string search_name, int array[], int original_array[],int size, int count_step,
                                    int search_node, int check_node);
};

#endif // SEARCH_H
