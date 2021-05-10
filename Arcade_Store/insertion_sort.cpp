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
            system("clear");
            cout << "\n\t\t\t\tINSERTION SORT\n\n";
            cout << "Original\n";

            this->visualize_sort(original_array,size);

            count_step++;
            cout << "Pass " << count_step;
            cout << " - (Key: " << key << ", Check: "<< array[j] <<") ";

            array[j + 1] = array[j];                // update the current element
            --j;                                    // by moving backward to the previous elements until the loop failed (current element < key)

            cout << endl;
            this->visualize_sort(array,size);
            usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

        }

        cout << "-> UPDATE (Key: " << array[j+1] <<") ";
        array[j + 1] = key;             // keep moving key until the end of the array


        system("clear");
        cout << "\n\t\t\t\tINSERTION SORT\n\n";
        cout << "Original\n";

        this->visualize_sort(original_array,size);

        count_step++;
        cout << "Pass " << count_step;

        cout << endl;
        this->visualize_sort(array,size);
        usleep(300000);               // delaying system 0.5s (0.5x1000000) to display animation

    }
}
