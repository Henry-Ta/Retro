#include "binary_insertion_sort.h"

#include <iostream>

#include <unistd.h>         // Used for usleep()

using namespace std;

Binary_Insertion_Sort::Binary_Insertion_Sort():Sort()
{

}

// A binary search based function to find the position where item should be inserted in a[low..high]
int Binary_Insertion_Sort::binarySearch(int array[], int item, int low, int high)
{
    if (high <= low)
        return (item > array[low]) ? (low + 1) : low;           // return (low+1) if (item>array[low], else return (low)

    int mid = (low + high) / 2;

    if (item == array[mid])
        return mid + 1;

    if (item > array[mid])
        return binarySearch(array, item, mid + 1, high);
    return binarySearch(array, item, low, mid - 1);
}

void Binary_Insertion_Sort::run_sort(int array[], int size){
    int count_step = 0;
    int original_array[size];
    copy( array, array+size, original_array );      // copy array, syntax: copy(source_array, source_array + source_array_size, destination_array)

    int i,j,selected,location;

    for (i = 1; i < size; ++i){
        j = i - 1;
        selected = array[i];

        location = this->binarySearch(array, selected, 0, j);       // uses binary search to find location where selected sould be inseretd

        cout << "-> CHECK Selected("<<selected<<") - Location(" << location <<") ";
        count_step = Sort::visualize_processing_sort("BINARY INSERTION SORT",array,original_array,size,count_step);
        while (j >= location)           // Move all elements after location to create space
        {
            cout << "-> SORT Selected("<<selected<<") - Current(" << array[j] <<")";
            array[j + 1] = array[j];
            count_step = Sort::visualize_processing_sort("BINARY INSERTION SORT",array,original_array,size,count_step);

            j--;
        }
        cout << "-> UPDATE Selected(" << selected <<") - Location(" << location <<") ";
        array[j + 1] = selected;

        count_step = Sort::visualize_processing_sort("BINARY INSERTION SORT",array,original_array,size,count_step);
    }
}

/*
int Binary_Insertion_Sort::visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step,
                                                     int selected, int location){
    //array[]: array to be sorted
    //original_array[]: copy of array[] to display original version
    //size: size of array
    //count_step: increase number to count each step

    //selected: array[i];
    //location: binarySearch(array, selected, 0, j);

    system("clear");
    cout << "\n\t\t\t"<<sort_name<<"\n\n";
    cout << "Original\n";
    this->visualize_sort(original_array,size);
    count_step++;
    cout << "Pass " << count_step;
    cout << " - (Selected: " << selected << ", Location: "<< location <<") ";
    cout << endl;
    this->visualize_sort(array,size);
    usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

    return count_step;
}*/
