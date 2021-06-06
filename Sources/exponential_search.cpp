#include "../Headers/exponential_search.h"

#include <iostream>

using namespace std;

Exponential_Search::Exponential_Search()
{

}

void Exponential_Search::run_binary_search(int array[],int original_array[], int size, int search_node,  int left_node, int right_node, int count_step, bool found_node){
    int mid = left_node + (right_node - left_node) / 2;
    
    if (right_node >= left_node) {

        // If the element is present at the middle itself
        if (array[mid] == search_node){
            //return mid;

            count_step = Search::visualize_processing_search("\tEXPONENTIAL SEARCH",array,original_array,size,count_step,search_node,array[mid]);
            found_node = true;
            return;
        }

        // If element is smaller than mid, then it can only be present in left subarray
        if (array[mid] > search_node){
            //return binarySearch(array, left_node, mid - 1, search_node);

            count_step = Search::visualize_processing_search("\tEXPONENTIAL SEARCH",array,original_array,size,count_step,search_node,array[mid]);
            this->run_binary_search(array,original_array, size,  search_node, left_node, mid - 1, count_step, found_node);
            return;
        }

        // Else the element can only be present in right subarray
        // return binarySearch(array, mid + 1, right_node, search_node);
        
        this->run_binary_search(array,original_array, size, search_node, mid + 1, right_node, count_step, found_node);
        return;
    }

    if(!found_node)
        cout<<"-> NOT FOUND\n";
}

void Exponential_Search::run_search(int array[],int origin_array[], int size, int search_node) {
    int count_step = 0;
    int original_array[size];
    copy( origin_array, origin_array+size, original_array );        // to display original array in visualization
    bool found_node = false;

    // If search_node is present at firt location itself
    if (array[0] == search_node){
        //return 0;
        count_step = Search::visualize_processing_search("\tEXPONENTIAL SEARCH",array,original_array,size,count_step,search_node,array[0]);
        found_node = true;
        return;
    }
        
 
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < size && array[i] <= search_node){
        count_step = Search::visualize_processing_search("\tEXPONENTIAL SEARCH",array,original_array,size,count_step,search_node,array[i]);
        i = i*2;
    }
        
    //  Call binary search for the found range.
    this->run_binary_search(array, original_array, size, search_node, i/2,min(i, size-1), count_step,found_node);

}