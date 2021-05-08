#include "bubble_sort.h"

#include <iostream>

#include <unistd.h>         // Used for usleep()
#include <algorithm>
#include <iterator>

using namespace std;

Bubble_Sort::Bubble_Sort()
{

}

void Bubble_Sort::swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// A function to implement bubble sort
void Bubble_Sort::run_sort(int array[], int size) {
    int count_step = 0;
    int original_array[size];

    copy( array, array+size, original_array );      // copy array, syntax copy(source_array, source_array + source_array_size, destination_array)

    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++)
        {
            system("clear");
            cout << "Original\n";
            this->visualize_sort(original_array,size);

            count_step++;
            cout << "Pass " << count_step;
            cout << " - (" << array[j] << ", "<< array[j+1] <<") ";
            //checking if previous value is
            //grater than next one or not
            if(array[j]>array[j+1])
            {
                //temp will temporarly store
                //the value of arr[j]
                //then we will swap the values

                /*int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;*/

                this->swap(&array[j],&array[j+1]);
                cout << "<- SWAP -> ("<<array[j]<<", "<<array[j+1]<<")";
            }
            cout << endl;

            this->visualize_sort(array,size);

            usleep(500000);               // delaying system 0.5s (0.5x1000000) to display animation

        }
    }
}

/* Function to print an array */
void Bubble_Sort::print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void Bubble_Sort::visualize_sort(int array[], int size){
    string visualization;
    for (int i = 0; i < size; i++){
        switch(array[i]){

            case 1:
            visualization+="\t\t\t 1 ----\n";
            break;
            case 2:
            visualization+="\t\t\t 2 ------\n";
            break;
            case 3:
            visualization+="\t\t\t 3 --------\n";
            break;
            case 4:
            visualization+="\t\t\t 4 ----------\n";
            break;
            case 5:
            visualization+="\t\t\t 5 ------------\n";
            break;
            case 6:
            visualization+="\t\t\t 6 --------------\n";
            break;
            case 7:
            visualization+="\t\t\t 7 ----------------\n";
            break;
            case 8:
            visualization+="\t\t\t 8 ------------------\n";
            break;
            case 9:
            visualization+="\t\t\t 9 --------------------\n";
            break;
            case 10:
            visualization+="\t\t\t10 ----------------------\n";
            break;
            case 11:
            visualization+="\t\t\t11 ------------------------\n";
            break;
            case 12:
            visualization+="\t\t\t12 --------------------------\n";
            break;
            case 13:
            visualization+="\t\t\t13 ----------------------------\n";
            break;
            case 14:
            visualization+="\t\t\t14 ------------------------------\n";
            break;
            case 15:
            visualization+="\t\t\t15 --------------------------------\n";
            break;
            case 16:
            visualization+="\t\t\t16 ----------------------------------\n";
            break;
            case 17:
            visualization+="\t\t\t17 ------------------------------------\n";
            break;
            case 18:
            visualization+="\t\t\t18 --------------------------------------\n";
            break;
            case 19:
            visualization+="\t\t\t19 ----------------------------------------\n";
            break;
            case 20:
            visualization+="\t\t\t20 ------------------------------------------\n";
            break;
            /*
            case 1:
            visualization+="\t\t\t•\n";
            break;
            case 2:
            visualization+="\t\t\t•••\n";
            break;
            case 3:
            visualization+="\t\t\t•••••\n";
            break;
            case 4:
            visualization+="\t\t\t•••••••\n";
            break;
            case 5:
            visualization+="\t\t\t•••••••••\n";
            break;
            case 6:
            visualization+="\t\t\t•••••••••••\n";
            break;
            case 7:
            visualization+="\t\t\t•••••••••••••\n";
            break;
            */
        }
    }

    cout << visualization << "\n\n";
    //system("clear");
}
