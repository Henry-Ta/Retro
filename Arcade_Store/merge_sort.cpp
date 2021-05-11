#include "merge_sort.h"

#include <iostream>

using namespace std;

Merge_Sort::Merge_Sort()
{

}

// Merges two subarrays of array[].
// First subarray is arr[left..middle]
// Second subarray is arr[middle+1..right]
void Merge_Sort::merge(int array[], int left_index, int middle_point, int right_index,
                       int count_step,int size, int original_array[])
{
    int left_array_size = middle_point - left_index + 1;
    int right_array_size = right_index - middle_point;

    // Create temp arrays
    int left_array[left_array_size], right_array[right_array_size];

    count_step = Sort::visualize_processing_sort("\tMERGE SORT",array,original_array,size,count_step);

    // Copy data to temp array L[]
    for (int i = 0; i < left_array_size; i++){
        cout << "-> LEFT[] append {"<<array[left_index + i]<<"}";
        left_array[i] = array[left_index + i];

        count_step = Sort::visualize_processing_sort("\tMERGE SORT",array,original_array,size,count_step);
    }

    // Copy data to temp array R[]
    for (int j = 0; j < right_array_size; j++){
        cout << "-> RIGHT[] append {"<<array[middle_point + 1 + j]<<"}";
        right_array[j] = array[middle_point + 1 + j];

        count_step = Sort::visualize_processing_sort("\tMERGE SORT",array,original_array,size,count_step);
    }


    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = left_index;

    while (i < left_array_size && j < right_array_size) {
        if (left_array[i] <= right_array[j]) {
            cout << "-> MERGE LEFT{"<<left_array[i]<<"}";
            array[k] = left_array[i];
            count_step = Sort::visualize_processing_sort("\tMERGE SORT",array,original_array,size,count_step);

            i++;
        }else {
            cout << "-> MERGE RIGHT{"<<right_array[j]<<"}";
            array[k] = right_array[j];
            count_step = Sort::visualize_processing_sort("\tMERGE SORT",array,original_array,size,count_step);

            j++;
        }

        count_step = Sort::visualize_processing_sort("\tMERGE SORT",array,original_array,size,count_step);

        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < left_array_size) {
        cout << "-> MERGE remaining LEFT{"<<left_array[i]<<"}";
        array[k] = left_array[i];
        count_step = Sort::visualize_processing_sort("\tMERGE SORT",array,original_array,size,count_step);

        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < right_array_size) {
        cout << "-> MERGE remaining RIGHT{"<<right_array[j]<<"}";
        array[k] = right_array[j];
        count_step = Sort::visualize_processing_sort("\tMERGE SORT",array,original_array,size,count_step);

        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void Merge_Sort::run_sort(int array[],int left_index,int right_index,
                          int size, int origin_array[]){
    int count_step = 0;
    int original_array[size];
    copy( origin_array, origin_array+size, original_array );      // copy array, syntax: copy(source_array, source_array + source_array_size, destination_array)

    if(left_index>=right_index){
        return;//returns recursively
    }

    int middle_point =left_index+ (right_index-left_index)/2;

    this->run_sort(array,left_index,middle_point,
                   size, original_array);

    this->run_sort(array,middle_point+1,right_index,
                   size, original_array);

    this->merge(array,left_index,middle_point,right_index,count_step,
                size,original_array);
}

