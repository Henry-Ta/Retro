#include "heap_sort.h"

#include <iostream>

using namespace std;

Heap_Sort::Heap_Sort()
{

}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void Heap_Sort::heapify(int array[], int size, int node_i,int origin_array[], int origin_size)
{
    int count_step = 0;
    int original_array[origin_size];
    copy( origin_array, origin_array+origin_size, original_array );

    int largest = node_i; // Initialize largest as root
    int left_child = 2 * node_i + 1; // left_child = 2*i + 1
    int right_child = 2 * node_i + 2; // right_child = 2*i + 2

    cout <<"-> CHECK Left Child("<<array[left_child]<<") - Right Child("<<array[right_child]<<")";
    count_step = Sort::visualize_processing_sort("\tHEAP SORT",array,original_array,origin_size,count_step);

    // If left_child child is larger than root
    if (left_child < size && array[left_child] > array[largest]){
        cout <<"-> UPDATE Left Child("<<array[left_child]<<")";
        largest = left_child;
        count_step = Sort::visualize_processing_sort("\tHEAP SORT",array,original_array,origin_size,count_step);
    }

    // If right_child child is larger than largest so far
    if (right_child < size && array[right_child] > array[largest]){
        cout <<"-> UPDATE Right Child("<<array[right_child]<<")";
        largest = right_child;
        count_step = Sort::visualize_processing_sort("\tHEAP SORT",array,original_array,origin_size,count_step);
    }

    // If largest is not root
    if (largest != node_i) {
        cout << "-> SWAP Root("<<array[largest]<<") - Largest("<<array[node_i]<<")";
        this->swap(array[node_i], array[largest]);
        count_step = Sort::visualize_processing_sort("\tHEAP SORT",array,original_array,origin_size,count_step);

        // Recursively heapify the affected sub-tree
        this->heapify(array, size, largest, original_array, origin_size);
    }
}

// main function to do heap sort
void Heap_Sort::run_sort(int array[], int size, int origin_array[], int origin_size)
{
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        this->heapify(array, size, i,origin_array,origin_size);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        this->swap(array[0], array[i]);

        // call max heapify on the reduced heap
        this->heapify(array, i, 0,origin_array,origin_size);
    }
}
