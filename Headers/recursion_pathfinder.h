#ifndef RECURSION_PATHFINDER_H
#define RECURSION_PATHFINDER_H

#include "pathfinder.h"

class Recursion_Pathfinder:public Pathfinder{
public:
    Recursion_Pathfinder();

    void find_path(char map[][COLUMN_SIZE],int max_row_size, int max_col_size, Node star_node, Node end_node);
    void show_title();
    
    void set_start_check_node(Node check_node, Node end_node);
    void spiral_recursion(char map[][COLUMN_SIZE],int max_row_size, int max_col_size, Node star_node, Node end_node, Node check_node, bool found_node, int sprial_round);
};

#endif // RECURSION_PATHFINDER_H
