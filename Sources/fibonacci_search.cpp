#include "../Headers/fibonacci_search.h"

#include <iostream>

using namespace std;

Fibonacci_Search::Fibonacci_Search()
{

}

// Utility function to find minimum of two elements
int Fibonacci_Search::min(int x, int y) { return (x <= y) ? x : y; }
 

void Fibonacci_Search::run_search(int array[],int origin_array[], int size, int search_node) {
    int count_step = 0;
    int original_array[size];
    copy( origin_array, origin_array+size, original_array );        // to display original array in visualization
    bool found_node = false;

    /* Initialize fibonacci numbers */
    int fibMMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

    /* fibM is going to store the smallest Fibonacci
       Number greater than or equal to size */
    while (fibM < size) {
        count_step = Search::visualize_processing_search("\tFIBONACCI SEARCH",array,original_array,size,count_step,search_node,array[fibM]);

        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Marks the eliminated range from front
    int offset = -1;
 
    /* while there are elements to be inspected. Note that
       we compare array[fibMm2] with search_node. When fibM becomes 1,
       fibMm2 becomes 0 */
    while (fibM > 1) {
        // Check if fibMm2 is a valid location
        int i = this->min(offset + fibMMm2, size - 1);
        
        /* If search_node is greater than the value at index fibMm2,
           cut the subarray array from offset to i */
        if (array[i] < search_node) {
            count_step = Search::visualize_processing_search("\tFIBONACCI SEARCH",array,original_array,size,count_step,search_node,array[i]);

            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
 
        /* If search_node is greater than the value at index fibMm2,
           cut the subarray after i+1  */
        else if (array[i] > search_node) {
            count_step = Search::visualize_processing_search("\tFIBONACCI SEARCH",array,original_array,size,count_step,search_node,array[i]);

            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 
        /* element found. return index */
        else{
            //return i;

            count_step = Search::visualize_processing_search("\tFIBONACCI SEARCH",array,original_array,size,count_step,search_node,array[i]);
            found_node = true;
            return;
        }
    }
 
    /* comparing the last element with search_node */
    if (fibMMm1 && array[offset + 1] == search_node){
        //return offset + 1;
        count_step = Search::visualize_processing_search("\tFIBONACCI SEARCH",array,original_array,size,count_step,search_node,array[offset + 1]);
        found_node = true;
        return;
    }

    if(!found_node)
        cout<<"-> NOT FOUND\n";
}




