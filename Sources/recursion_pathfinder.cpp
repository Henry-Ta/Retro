#include "../Headers/recursion_pathfinder.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()
using namespace std;

Recursion_Pathfinder::Recursion_Pathfinder(){}

void Recursion_Pathfinder::set_start_check_node(Node check_node){
    //if(check_node.get_x_row()-1>=0 && check_node.get_x_row()!=)
}

void Recursion_Pathfinder::recursion(char map[][COLUMN_SIZE], int max_row_size, int max_col_size, Node start_node, Node end_node, Node check_node, bool found_node){
    if(!this->match_node(check_node,end_node)){
        int temp = check_node.get_y_column()-1;
        check_node.set_y_column(temp);

        this->print_map(map,max_row_size,max_col_size,start_node,end_node,check_node);
        usleep(100000);               // 1s = 1,000,000 ; delaying system 0.5s (0.5x1000000) to display animation
        this->recursion(map,max_row_size,max_col_size,start_node,end_node,check_node,found_node);
    }
        
}

void Recursion_Pathfinder::find_path(char map[][COLUMN_SIZE], int max_row_size, int max_col_size, Node start_node, Node end_node){
    this->show_title();
    Node check_node;
    this->copy_node(start_node,check_node);
    this->set_start_check_node(check_node);
    this->recursion(map,max_row_size,max_col_size,start_node,end_node,check_node, false);
}

void Recursion_Pathfinder::show_title(){
    system("clear");   
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                  RECURSION PATHFINDER                 │\n";
    cout << "\t•-------------------------------------------------------•\n";
}

