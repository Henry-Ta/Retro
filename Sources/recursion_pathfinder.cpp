#include "../Headers/recursion_pathfinder.h"

#include <iostream>
using namespace std;

Recursion_Pathfinder::Recursion_Pathfinder(){}

void Recursion_Pathfinder::find_path(int map[][COLUMN_SIZE], int max_row_size, int max_col_size, Node start_node, Node end_node){
    this->print_map(map,max_row_size,max_col_size,start_node,end_node);
}

