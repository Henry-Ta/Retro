#include "search.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()
using namespace std;

Search::Search()
{

}

void Search::swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void Search::print_array(int array[], int size)       // Function to print an array
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void Search::visualize_original_array(int array[], int size){
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

void Search::visualize_search(int array[], int size, int search_node, int check_node){
    string visualization;
    for (int i = 0; i < size; i++){

        switch(array[i]){
            case 1:
                if(check_node == array[i]){
                    if(search_node == check_node){
                        visualization+="\tFOUND ->  1 ─\n";
                    }else
                        visualization+="\t\t 1 ─\n";
                }else
                    visualization+="\t\t\t 1 ─\n";

                break;

            case 2:
                if(check_node == array[i]){
                    if(search_node == check_node)
                        visualization+="\tFOUND ->  2 ──\n";
                    else
                        visualization+="\t\t 2 ──\n";
                }else
                    visualization+="\t\t\t 2 ──\n";

                break;

            case 3:
                if(check_node == array[i]){
                    if(search_node == check_node )
                        visualization+="\tFOUND ->  3 ───\n";
                    else
                        visualization+="\t\t 3 ───\n";
                }else
                    visualization+="\t\t\t 3 ───\n";

                break;

            case 4:
                if(check_node == array[i]){
                    if(search_node == check_node)
                        visualization+="\tFOUND ->  4 ────\n";
                    else
                        visualization+="\t\t 4 ────\n";
                }else
                    visualization+="\t\t\t 4 ────\n";

                break;

            case 5:
               if(check_node == array[i]){
                   if(search_node == check_node)
                       visualization+="\tFOUND ->  5 ─────\n";
                   else
                        visualization+="\t\t 5 ─────\n";
                }else
                    visualization+="\t\t\t 5 ─────\n";

                break;

            case 6:
                if(check_node == array[i]){
                    if(search_node == check_node)
                        visualization+="\tFOUND ->  6 ──────\n";
                    else
                        visualization+="\t\t 6 ──────\n";
                }else
                    visualization+="\t\t\t 6 ──────\n";

                break;

            case 7:
                if(check_node == array[i]){
                    if(search_node == check_node)
                        visualization+="\tFOUND ->  7 ───────\n";
                    else
                        visualization+="\t\t 7 ───────\n";
                }else
                    visualization+="\t\t\t 7 ───────\n";

                break;

            case 8:
                if(check_node == array[i]){
                    if(search_node == check_node)
                        visualization+="\tFOUND ->  8 ────────\n";
                    else
                        visualization+="\t\t 8 ────────\n";
                }else
                    visualization+="\t\t\t 8 ────────\n";

                break;

            case 9:
                if(check_node == array[i]){
                    if(search_node == check_node)
                        visualization+="\tFOUND ->  9 ─────────\n";
                    else
                        visualization+="\t\t 9 ─────────\n";
                }else
                    visualization+="\t\t\t 9 ─────────\n";

                break;

            case 10:
                if(check_node == array[i]){
                    if(search_node==check_node)
                        visualization+="\tFOUND -> 10 ──────────\n";
                    else
                        visualization+="\t\t10 ──────────\n";
                }else
                    visualization+="\t\t\t10 ──────────\n";

                break;

            case 11:
                if(check_node == array[i]){
                   if(search_node==check_node )
                       visualization+="\tFOUND -> 11 ───────────\n";
                   else
                    visualization+="\t\t11 ───────────\n";
                }else
                    visualization+="\t\t\t11 ───────────\n";

                break;

            case 12:
                if(check_node == array[i]){
                    if(search_node==check_node)
                        visualization+="\tFOUND -> 12 ────────────\n";
                    else
                        visualization+="\t\t12 ────────────\n";
                }else
                    visualization+="\t\t\t12 ────────────\n";

                break;

            case 13:
                if(check_node == array[i]){
                   if(search_node==check_node)
                       visualization+="\tFOUND -> 13 ─────────────\n";
                   else
                    visualization+="\t\t13 ─────────────\n";
                }else
                    visualization+="\t\t\t13 ─────────────\n";

                break;

            case 14:
                if(check_node == array[i]){
                    if(search_node==check_node)
                        visualization+="\tFOUND -> 14 ──────────────\n";
                    else
                        visualization+="\t\t14 ──────────────\n";
                }else
                    visualization+="\t\t\t14 ──────────────\n";

                break;
        }
    }

    cout << visualization << "\n\n";
}

int Search::visualize_processing_search(string search_name, int array[], int original_array[],int size, int count_step,
                                        int search_node, int check_node){
    //array[]: array to be searched
    //original_array[]: copy of array[] to display original version
    //size: size of array
    //count_step: increase number to count each step

    //search_node: value of node to search
    //check_node: check current value of node

    system("clear");
    cout << "-> SEARCH ("<<search_node<<")";
    cout << "\n\t\t\t"<<search_name<<"\n\n";
    cout << "Original\n";
    this->visualize_original_array(original_array,size);
    count_step++;
    cout << "Pass " << count_step;
    cout << endl;
    this->visualize_search(array,size,search_node,check_node);
    usleep(300000);               // 1s = 1,000,000 ; delaying system 0.5s (0.5x1000000) to display animation

    return count_step;
}
