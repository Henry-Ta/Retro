#ifndef PATHFINDER_H 
#define PATHFINDER_H

#include "node.h"

const int ROW_SIZE=15;
const int COLUMN_SIZE=17;

class Pathfinder:public Node{
public:
    Pathfinder();

    void print_map(char map[][COLUMN_SIZE], int max_row_size,int max_col_size, Node start_node, Node end_node);
    bool compare_node(Node a, Node b);
};

#endif // PATHFINDER_H
