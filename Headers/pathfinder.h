#ifndef PATHFINDER_H 
#define PATHFINDER_H

#include "node.h"

const int ROW_SIZE=10;
const int COLUMN_SIZE=10;

class Pathfinder:public Node{
public:
    Pathfinder();

    void print_map(int map[][COLUMN_SIZE], int max_row_size,int max_col_size, Node start_node, Node end_node);
};

#endif // PATHFINDER_H
