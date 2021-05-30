#include "../Headers/jump_search.h"

#include <iostream>
#include <math.h>       // sqrt()
using namespace std;

Jump_Search::Jump_Search()
{

}

void Jump_Search::run_search(int array[], int size, int search_node) {
    int count_step = 0;
    int original_array[size];
    copy( array, array+size, original_array );
    bool found_node = false;


     // Finding block size to be jumped
    int step = sqrt(size);
 
    // Finding the block where element is
    // present (if it is present)
    int prev = 0;

    count_step = Search::visualize_processing_search("\tJUMP SEARCH",array,original_array,size,count_step,search_node,array[prev]);

    while (array[min(step, size)-1] < search_node)
    {
        count_step = Search::visualize_processing_search("\tJUMP SEARCH",array,original_array,size,count_step,search_node,array[prev]);
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return;
    }
 
    // Doing a linear search for search_node in block
    // beginning with prev.
    while (array[prev] < search_node)
    {
        count_step = Search::visualize_processing_search("\tJUMP SEARCH",array,original_array,size,count_step,search_node,array[prev]);
        prev++;
        // If we reached next block or end of
        // array, element is not present.
        if (prev == min(step, size))
            return;
    }
    // If element is found
    if (array[prev] == search_node){
        count_step = Search::visualize_processing_search("\tJUMP SEARCH",array,original_array,size,count_step,search_node,array[prev]);
        found_node = true;
        return;
    }
 
    if(!found_node)
        cout<<"-> NOT FOUND\n";
}