#include "sort.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()
using namespace std;

Sort::Sort()
{

}

void Sort::swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void Sort::swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void Sort::print_array(int array[], int size)       // Function to print an array
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void Sort::visualize_sort(int array[], int size){
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

int Sort::visualize_processing_sort(string sort_name, int array[], int original_array[],int size, int count_step){
    //array[]: array to be sorted
    //original_array[]: copy of array[] to display original version
    //size: size of array
    //count_step: increase number to count each step

    system("clear");
    cout << "\n\t\t\t"<<sort_name<<"\n\n";
    cout << "Original\n";
    this->visualize_sort(original_array,size);
    count_step++;
    cout << "Pass " << count_step;
    cout << endl;
    this->visualize_sort(array,size);
    usleep(100000);               // 1s = 1,000,000 ; delaying system 0.5s (0.5x1000000) to display animation

    return count_step;
}
