#include "selection_sort.h"

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
    bool j_done = false;

    copy( array, array+size, original_array );      // copy array, syntax copy(source_array, source_array + source_array_size, destination_array)

    for (int i = 0; i < size-1; i++)                // One by one move boundary of unsorted subarray
    {

        int min_number = i;         // Find the minimum element in unsorted array

        for (int j = i+1; j < size; j++){

            system("clear");
            cout << "\n\t\t\t\tSELECTION SORT\n\n";
            cout << "Original\n";

            //this->visualize_sort(original_array,size);
            Sort::visualize_sort(original_array,size);

            count_step++;
            cout << "Pass " << count_step;
            cout << " - (Min: " << array[min_number] << ", Check: "<< array[j] <<") ";

            if (array[j] < array[min_number]){          // Swap current min with the new min if found out
                min_number = j;
                cout << " - UPDATE (New Min: "<<array[min_number]<<")";
            }

            cout << endl;
            //this->visualize_sort(array,size);
            Sort::visualize_sort(array,size);
            usleep(500000);               // delaying system 0.5s (0.5x1000000) to display animation

            if(j==size-1)                   // turn on flag to display the final finished array
                j_done = true;

        }
        cout << "-> SWAP (" << array[min_number] <<", "<< array[i]<<")";        // NEED TO UPDATE

        Sort::swap(&array[min_number], &array[i]);          // Swap the found minimum element with the first element

        if(i==size-2 && j_done){        // to display the final finished array, when everything is done
            system("clear");
            cout << "\n\t\t\t\tSELECTION SORT\n\n";
            cout << "Original\n";

            //this->visualize_sort(original_array,size);
            Sort::visualize_sort(original_array,size);

            count_step++;
            cout << "Pass " << count_step << " - Finish ";

            cout << endl;
            //this->visualize_sort(array,size);
            Sort::visualize_sort(array,size);
            usleep(500000);               // delaying system 0.5s (0.5x1000000) to display animation
        }
    }
}


/*
void Selection_Sort::swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//Function to print an array
void Selection_Sort::print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void Selection_Sort::visualize_sort(int array[], int size){
    string visualization;
    for (int i = 0; i < size; i++){
        switch(array[i]){

            case 1:
            visualization+="\t\t\t 1 ─\n";
            break;
            case 2:
            visualization+="\t\t\t 2 ──\n";
            break;
            case 3:
            visualization+="\t\t\t 3 ───\n";
            break;
            case 4:
            visualization+="\t\t\t 4 ────\n";
            break;
            case 5:
            visualization+="\t\t\t 5 ─────\n";
            break;
            case 6:
            visualization+="\t\t\t 6 ──────\n";
            break;
            case 7:
            visualization+="\t\t\t 7 ───────\n";
            break;
            case 8:
            visualization+="\t\t\t 8 ────────\n";
            break;
            case 9:
            visualization+="\t\t\t 9 ─────────\n";
            break;
            case 10:
            visualization+="\t\t\t10 ──────────\n";
            break;
            case 11:
            visualization+="\t\t\t11 ───────────\n";
            break;
            case 12:
            visualization+="\t\t\t12 ────────────\n";
            break;
            case 13:
            visualization+="\t\t\t13 ─────────────\n";
            break;
            case 14:
            visualization+="\t\t\t14 ──────────────\n";
            break;
        }
    }

    cout << visualization << "\n\n";
}
*/
