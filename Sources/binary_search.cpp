#include "../Headers/binary_search.h"

#include <iostream>

using namespace std;

Binary_Search::Binary_Search()
{

}

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
void Binary_Search::run_search(int array[],int origin_array[], int size, int search_node, int left_node, int right_node) {
    int count_step = 0;
    int original_array[size];
    copy( origin_array, origin_array+size, original_array );        // to display original array in visualization
    bool found_node = false;

    int mid = left_node + (right_node - left_node) / 2;
    count_step = Search::visualize_processing_search("\n\t\t\tBINARY SEARCH",array,original_array,size,count_step,search_node,array[mid]);

    if (right_node >= left_node) {

        // If the element is present at the middle
        // itself
        if (array[mid] == search_node){
            //return mid;
            found_node = true;
            return;
        }

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (array[mid] > search_node){
            //return binarySearch(array, left_node, mid - 1, search_node);

            count_step = Search::visualize_processing_search("\n\t\t\tBINARY SEARCH",array,original_array,size,count_step,search_node,array[mid]);
            this->run_search(array,original_array, size,  search_node, left_node, mid - 1);
            return;
        }

        // Else the element can only be present
        // in right subarray
        //return binarySearch(array, mid + 1, right_node, search_node);
        count_step = Search::visualize_processing_search("\n\t\t\tBINARY SEARCH",array,original_array,size,count_step,search_node,array[mid]);

        this->run_search(array,original_array, size, search_node, mid + 1, right_node);
        return;
    }

    count_step = Search::visualize_processing_search("\n\t\t\tBINARY SEARCH",array,original_array,size,count_step,search_node,array[mid]);

    if(!found_node)
        cout<<"-> NOT FOUND\n";
}
