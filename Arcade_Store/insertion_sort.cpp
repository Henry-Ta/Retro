#include "insertion_sort.h"

#include <iostream>

#include <unistd.h>         // Used for usleep()

using namespace std;

Insertion_Sort::Insertion_Sort():Sort()
{

}

// A function to implement insertion sort
void Insertion_Sort::run_sort(int array[], int size) {
    int count_step = 0;
    int original_array[size];

    copy( array, array+size, original_array );      // copy array, syntax: copy(source_array, source_array + source_array_size, destination_array)

    for (int i = 1; i < size; i++){
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)        // if the current element is > key, move the current element to the back, make it a sorted array
        {
            count_step = this->visualize_processing_sort("\tINSERTION SORT",array,original_array,size,count_step,key,array[j]);

            cout << "-> UPDATE (Check: " << array[j] <<") ";
            array[j + 1] = array[j];                // update the current element
            j--;                                    // by moving backward to the previous elements until the loop failed (current element < key)

            count_step = this->visualize_processing_sort("\tINSERTION SORT",array,original_array,size,count_step,key,array[j]);
        }
        cout << "-> UPDATE (Key: " << key <<") ";
        array[j + 1] = key;             // keep moving key until the end of the array

        count_step = this->visualize_processing_sort("\tINSERTION SORT",array,original_array,size,count_step,key,array[j]);
    }
}

int Insertion_Sort::visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step, int key, int array_j){
    //array[]: array to be sorted
    //original_array[]: copy of array[] to display original version
    //size: size of array
    //count_step: increase number to count each step

    //key: array[i] in insertion_sort
    //array_j: value of current element to check ( array[j] )

    system("clear");
    cout << "\n\t\t\t"<<sort_name<<"\n\n";
    cout << "Original\n";
    this->visualize_sort(original_array,size);
    count_step++;
    cout << "Pass " << count_step;
    cout << " - (Key: " << key << ", Check: "<< array_j<<") ";
    cout << endl;
    this->visualize_sort(array,size);
    usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

    return count_step;
}
