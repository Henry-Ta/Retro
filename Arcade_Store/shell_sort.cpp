#include "shell_sort.h"

#include <iostream>

#include <unistd.h>         // Used for usleep()

using namespace std;

Shell_Sort::Shell_Sort()
{

}

void Shell_Sort::run_sort(int array[], int size) {
    int count_step = 0;
    int original_array[size];
    copy( array, array+size, original_array );      // copy array, syntax: copy(source_array, source_array + source_array_size, destination_array)

    // Start with a big gap, then reduce the gap
   for (int gap = size/2; gap > 0; gap /= 2){
       // Do a gapped insertion sort for this gap size.
       // The first gap elements a[0..gap-1] are already in gapped order
       // keep adding one more element until the entire array is
       // gap sorted

       for (int i = gap; i < size; i += 1)
       {
           // add a[i] to the elements that have been gap sorted
           // save a[i] in temp and make a hole at position i
           int temp = array[i];

           // shift earlier gap-sorted elements up until the correct
           // location for a[i] is found
           int j;
           for (j = i; j >= gap && array[j - gap] > temp; j -= gap){

               cout << "-> CHECK Current("<<array[j-gap]<<") - Last("<<array[j]<<") - Gap("<<gap<<")";
               array[j] = array[j - gap];

               count_step = Sort::visualize_processing_sort("\tSHELL SORT",array,original_array,size,count_step);

            }
           cout << "-> UPDATE Current("<<temp<<") - Last("<<array[j]<<") - Gap("<<gap<<")";
           //  put temp (the original a[i]) in its correct location
           array[j] = temp;

           count_step = Sort::visualize_processing_sort("\tSHELL SORT",array,original_array,size,count_step);
       }

   }
}

/*
int Shell_Sort::visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step,
                                          int gap, int array_j){
    //array[]: array to be sorted
    //original_array[]: copy of array[] to display original version
    //size: size of array
    //count_step: increase number to count each step

    //gap: show value of gap in Shell sort
    //array_j: value of current element to check ( array[j] )
    system("clear");
    cout << "\n\t\t\t"<<sort_name<<"\n\n";
    cout << "Original\n";
    this->visualize_sort(original_array,size);
    count_step++;
    cout << "Pass " << count_step;
    cout << " - (Gap: " << gap << ", Check: "<< array_j <<") ";
    cout << endl;
    this->visualize_sort(array,size);
    usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

    return count_step;      // return number of step to keep counting steps later on other calls
}*/
