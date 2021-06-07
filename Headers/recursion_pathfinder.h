#ifndef RECURSION_PATHFINDER_H
#define RECURSION_PATHFINDER_H

#include "pathfinder.h"

class Recursion_Pathfinder:public Pathfinder{
public:
    Recursion_Pathfinder();

    void find_path(int map[][COLUMN_SIZE],int max_row_size, int max_col_size, Node star_node, Node end_node);
};

#endif // NODE_H
