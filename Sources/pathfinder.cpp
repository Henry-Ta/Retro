#include "../Headers/pathfinder.h"

#include <iostream>
using namespace std;

Pathfinder::Pathfinder(){}

void Pathfinder::print_map(int map[][COLUMN_SIZE], int max_row_size,int max_col_size, Node start_node, Node end_node){
    cout << "Start Node ("<<start_node.get_x_row()<<", "<<start_node.get_y_column()<<")\n";
    cout << "End Node ("<<end_node.get_x_row()<<", "<<end_node.get_y_column()<<")\n";
}
