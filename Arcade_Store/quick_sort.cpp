#include "quick_sort.h"

#include <iostream>

#include <unistd.h>         // Used for usleep()

using namespace std;

Quick_Sort::Quick_Sort():Sort()
{

}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int Quick_Sort::partition (int array[], int low, int high, int size, int origi_array[])
{
    int pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    int count_step = 0;
    int original_array[size];
    copy( origi_array, origi_array+size, original_array );      // copy array, syntax: copy(source_array, source_array + source_array_size, destination_array)

    for (int j = low; j <= high - 1; j++)
    {
        system("clear");
        cout << "\n\t\t\t\tQUICK SORT\n\n";
        cout << "Original\n";
        this->visualize_sort(original_array,size);
        count_step++;
        cout << "Pass " << count_step;
        cout << " - (Pivot: " << pivot << ", Check: "<< array[j] <<") ";

        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            cout <<" <- SWAP";
            i++; // increment index of smaller element
            this->swap(&array[i], &array[j]);
            cout <<" -> ("<<array[i]<<", "<<array[j]<<")";
        }

        cout << endl;
        this->visualize_sort(array,size);
        usleep(300000);               // delaying system 0.3s (0.5x1000000) to display animation

    }
    cout <<"-> SWAP ("<<array[i+1]<<", "<<array[high]<<")";
    this->swap(&array[i + 1], &array[high]);

    // to display
    system("clear");
    cout << "\n\t\t\t\tQUICK SORT\n\n";
    cout << "Original\n";
    this->visualize_sort(original_array,size);
    count_step++;
    cout << "Pass " << count_step;
    cout << " - (Pivot: " << pivot << ") ";
    cout << endl;
    this->visualize_sort(array,size);
    usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

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
