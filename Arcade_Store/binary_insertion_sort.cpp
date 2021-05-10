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
        return (item > array[low]) ? (low + 1) : low;

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

        while (j >= location)           // Move all elements after location to create space
        {
            system("clear");
            cout << "\n\t\t\tBINARY INSERTION SORT\n\n";
            cout << "Original\n";
            this->visualize_sort(original_array,size);
            count_step++;
            cout << "Pass " << count_step;
            cout << " - (Selected: " << array[j] << ", Location: "<< location <<") ";

            array[j + 1] = array[j];
            j--;

            cout << endl;
            this->visualize_sort(array,size);
            usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

        }
        cout << "-> UPDATE (Selected: " << array[j+1] <<") ";
        array[j + 1] = selected;


        system("clear");
        cout << "\n\t\t\t\tBINARY INSERTION SORT\n\n";
        cout << "Original\n";
        this->visualize_sort(original_array,size);
        count_step++;
        cout << "Pass " << count_step;
        cout << endl;
        this->visualize_sort(array,size);
        usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

    }
}
