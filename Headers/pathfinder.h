#ifndef PATHFINDER_H 
#define PATHFINDER_H

#include "node.h"

const int ROW_SIZE=16;
const int COLUMN_SIZE=16;

class Pathfinder:public Node{
public:
    Pathfinder();

    void print_map(char map[][COLUMN_SIZE], int max_row_size,int max_col_size, Node start_node, Node end_node);
    void print_map(char map[][COLUMN_SIZE], int max_row_size,int max_col_size, Node start_node, Node end_node, Node check_node);

    bool found_node(Node check_node, Node search_node);
    bool match_node(Node a, Node b);
    bool match_left_node(Node check_node, Node left_node);
    bool match_right_node(Node check_node, Node right_node);
    bool match_above_node(Node check_node, Node above_node);
    bool match_below_node(Node check_node, Node below_node);

    void copy_node(Node copied, Node copy);
    void display_node(Node n);

};
#endif // PATHFINDER_H
