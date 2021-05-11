#include "quick_sort.h"

#include <iostream>

#include <unistd.h>         // Used for usleep()

using namespace std;

Quick_Sort::Quick_Sort():Sort()
{

}

// Pick last element as pivot
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int Quick_Sort::partition (int array[], int low, int high,
                           int size, int origi_array[])
{
    int pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    int count_step = 0;
    int original_array[size];
    copy( origi_array, origi_array+size, original_array );      // copy array, syntax: copy(source_array, source_array + source_array_size, destination_array)

    for (int j = low; j <= high - 1; j++)
    {
        cout <<"-> CHECK Current("<<array[j]<<") - Pivot("<<pivot<<")";
        count_step = Sort::visualize_processing_sort("\tQUICK SORT",array,original_array,size,count_step);

        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {

            i++; // increment index of smaller element
            cout <<"-> SWAP Current("<<array[j]<<") - Last Element("<<array[i]<<") - Pivot("<<pivot<<")";
            this->swap(&array[i], &array[j]);

            count_step = Sort::visualize_processing_sort("\tQUICK SORT",array,original_array,size,count_step);
        }
    }
    cout <<"-> SWAP Pivot("<<array[high]<<") - Last Element("<<array[i+1]<<")";
    this->swap(&array[i + 1], &array[high]);

    // to visualize
    count_step = Sort::visualize_processing_sort("\tQUICK SORT",array,original_array,size,count_step);

    return (i + 1);
}


/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void Quick_Sort::run_sort(int array[],int original_array[], int size, int low, int high) {

    if (low < high){
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(array, low, high, size, original_array);

        // Separately sort elements before
        // partition and after partition
        this->run_sort(array,original_array, size, low, pi - 1);
        this->run_sort(array,original_array, size, pi + 1, high);
    }
}

/*
int Quick_Sort::visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step,
                                          int pivot, int array_j){
    //array[]: array to be sorted
    //original_array[]: copy of array[] to display original version
    //size: size of array
    //count_step: increase number to count each step

    //pivot: array[high]
    //array_j: value of the current element array[j]

    system("clear");
    cout << "\n\t\t\t"<<sort_name<<"\n\n";
    cout << "Original\n";
    this->visualize_sort(original_array,size);
    count_step++;
    cout << "Pass " << count_step;
    cout << " - (Pivot: " << pivot << ", Check: "<< array_j <<") ";
    cout << endl;
    this->visualize_sort(array,size);
    usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

    return count_step;
}
*/
