#include "sort.h"

#include <iostream>

using namespace std;

Sort::Sort()
{

}

void Sort::swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
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
