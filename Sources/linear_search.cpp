#include "../Headers/linear_search.h"

#include <iostream>

using namespace std;

Linear_Search::Linear_Search()
{

}

void Linear_Search::run_search(int array[], int size, int search_node) {
    int count_step = 0;
    int original_array[size];
    copy( array, array+size, original_array );
    bool found_node = false;

    int i;
    for (i = 0; i < size; i++){

        if (array[i] == search_node){
            count_step = Search::visualize_processing_search("\tLINEAR SEARCH",array,original_array,size,count_step,search_node,array[i]);
            found_node = true;
            return;
        }
        count_step = Search::visualize_processing_search("\tLINEAR SEARCH",array,original_array,size,count_step,search_node,array[i]);
    }

    if(!found_node)
        cout<<"-> NOT FOUND\n";
}
