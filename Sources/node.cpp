#include "../Headers/node.h"

#include <iostream>
using namespace std;

Node::Node(){}

Node::Node(int row, int col){
    this->set_x_row(row);
    this->set_y_column(col);
}

void Node::set_x_row(int i){
    this->x_row = i;
}
int Node::get_x_row(){
    return this->x_row;
}

void Node::set_y_column(int i){
    this->y_column = i;
}
int Node::get_y_column(){
    return this->y_column;
}

void Node::set_row_column(int row, int col){
    this->set_x_row(row);
    this->set_y_column(col);
}

