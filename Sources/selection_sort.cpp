#include "../Headers/selection_sort.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()

using namespace std;

Selection_Sort::Selection_Sort():Sort()
{

}

// A function to implement Selection sort
void Selection_Sort::run_sort(int array[], int size) {
    int count_step = 0;
    int original_array[size];

    copy( array, array+size, original_array );      // copy array, syntax copy(source_array, source_array + source_array_size, destination_array)

    for (int i = 0; i < size-1; i++)                // One by one move boundary of unsorted subarray
    {
        int min_number = i;         // Find the minimum element in unsorted array

        for (int j = i+1; j < size; j++){

            cout << "-> CHECK Min(" << array[min_number] <<") - Current("<<array[j]<<")";
            //count_step = this->visualize_processing_sort("\tSELECTION SORT",array,original_array,size,count_step, array[min_number], array[j]);
            count_step = Sort::visualize_processing_sort("\tSELECTION SORT",array,original_array,size,count_step);

            if (array[j] < array[min_number]){          // Swap current min with the new min if found out
                cout << "-> UPDATE Min("<<array[j]<<")";
                min_number = j;

                //count_step = this->visualize_processing_sort("\tSELECTION SORT",array,original_array,size,count_step, array[min_number], array[j]);
                count_step = Sort::visualize_processing_sort("\tSELECTION SORT",array,original_array,size,count_step);
            }
        }
        cout << "-> SWAP Min(" << array[min_number] <<") - Sorted Array's Last Element("<< array[i]<<")";
        this->swap(&array[min_number], &array[i]);          // Swap the found minimum element with the first element in sorted subarray

        count_step = Sort::visualize_processing_sort("\tSELECTION SORT", array,original_array,size,count_step);
    }
}

/*
int Selection_Sort::visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step,
                                              int array_min, int array_j){
    //array[]: array to be sorted
    //original_array[]: copy of array[] to display original version
    //size: size of array
    //count_step: increase number to count each step

    //array_min: show value of array[min_number]
    //array_j: value of current element to check ( array[j] )

    system("clear");
    cout << "\n\t\t\t"<<sort_name<<"\n\n";
    cout << "Original\n";
    this->visualize_sort(original_array,size);
    count_step++;
    cout << "Pass " << count_step;
    cout << " - (Min: " << array_min << ", Check: "<< array_j <<") ";
    cout << endl;
    this->visualize_sort(array,size);
    usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

    return count_step;
}
*/

