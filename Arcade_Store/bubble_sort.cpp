#include "bubble_sort.h"

#include <iostream>

#include <unistd.h>         // Used for usleep()

using namespace std;

Bubble_Sort::Bubble_Sort():Sort()
{

}

// A function to implement bubble sort
void Bubble_Sort::run_sort(int array[], int size) {
    int count_step = 0;
    int original_array[size];

    copy( array, array+size, original_array );      // copy array, syntax: copy(source_array, source_array + source_array_size, destination_array)

    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++)
        {
            cout << "-> CHECK Current(" << array[j] << ") - Next("<< array[j+1] <<") ";
            //count_step = this->visualize_processing_sort("\tBUBBLE SORT",array,original_array,size,count_step, array[j], array[j+1]);
            count_step = Sort::visualize_processing_sort("\tBUBBLE SORT",array,original_array,size,count_step);

            if(array[j]>array[j+1])                             //checking if previous value is grater than next one or not
            {             
                /*int temp=array[j];            // Swap if the next number is smaller than the current number
                array[j]=array[j+1];
                array[j+1]=temp;*/

                cout << "-> SWAP Current("<<array[j]<<") - Next("<<array[j+1]<<")";
                this->swap(&array[j],&array[j+1]);

                //count_step = this->visualize_processing_sort("\tBUBBLE SORT",array,original_array,size,count_step, array[j], array[j+1]);
                count_step = Sort::visualize_processing_sort("\tBUBBLE SORT",array,original_array,size,count_step);
            }
        }
    }
}

/*
int Bubble_Sort::visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step,
                                           int array_j, int array_j_plus_1){
    //array[]: array to be sorted
    //original_array[]: copy of array[] to display original version
    //size: size of array
    //count_step: increase number to count each step

    //array_j: value of the current element array[j]
    //array_j_plus_1: value of the next element array[j+1]

    system("clear");
    cout << "\n\t\t\t"<<sort_name<<"\n\n";
    cout << "Original\n";
    this->visualize_sort(original_array,size);
    count_step++;
    cout << "Pass " << count_step;
    cout << " - (" << array_j << ", "<< array_j_plus_1 <<") ";
    cout << endl;
    this->visualize_sort(array,size);
    usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

    return count_step;
}
*/
