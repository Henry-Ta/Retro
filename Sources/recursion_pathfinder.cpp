#include "../Headers/recursion_pathfinder.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()
using namespace std;

Recursion_Pathfinder::Recursion_Pathfinder(){}

void Recursion_Pathfinder::set_start_check_node(Node check_node, Node start_node){
    // start from left (if possible)
    // otherwise -> above -> right -> below
    int col=check_node.get_y_column();
    int row=check_node.get_x_row();

    if(!this->match_left_node(check_node,start_node)){
        check_node.set_y_column(col-1);
    }
    else if(!this->match_above_node(check_node,start_node)){
        check_node.set_x_row(row-1);
    }
    else if(!this->match_right_node(check_node,start_node)){
        check_node.set_y_column(col+1);
    }
    else{
        check_node.set_x_row(row+1);
    }
}

void Recursion_Pathfinder::recursion(char map[][COLUMN_SIZE], int max_row_size, int max_col_size, Node start_node, Node end_node, Node check_node, bool found_node){
    int left = check_node.get_y_column()-1;
    int right = check_node.get_y_column()+1;
    int up= check_node.get_x_row()-1;
    int down= check_node.get_x_row()+1;
    int current_row=check_node.get_x_row();
    int current_col=check_node.get_y_column();

    this->print_map(map,max_row_size,max_col_size,start_node,end_node,check_node);

    found_node = this->found_node(check_node,end_node);

    if(!found_node){
        //check_node.set_row_column(current_row,left);     // go left

        //if(current_col-1<0){        // hit left wall
            //if(current_row-1<0)     // hit top left corner
                //check_node.set_row_column(current_row,right);
            //else
                //check_node.set_row_column(up,current_col);  // go up
        //}else if(current_row-1<0){  // hit top wall
            //if(current_col+1>COLUMN_SIZE-1)     // hit top right corner
                //check_node.set_row_column(down,current_col);
            //else
                //check_node.set_row_column(current_row,right);   // go right
        //}else if(current_col+1>COLUMN_SIZE-1){
            //if(current_row+1>ROW_SIZE-1)        // hit bottom right 
                //check_node.set_row_column(current_row,left);
            //else
                //check_node.set_row_column(down,current_col);
        //}else if(current_row+1>ROW_SIZE-1){
            //if(current_col-1<0)
                //check_node.set_row_column(up,current_col);
            //else
                //check_node.set_row_column(current_row,left);
        //}

        switch(this->spiral_path(check_node,ROW_SIZE,COLUMN_SIZE)){
            case 0:
                check_node.set_row_column(current_row,right);   // hit top left -> go right 
            break;
            case 1:
                check_node.set_row_column(up,current_col);      // hit left -> go up
            break;
            case 2:
                check_node.set_row_column(down,current_col);    // hit top right -> go down
            break;
            case 3:
                check_node.set_row_column(current_row,right);   // hit top -> go right
            break;
            case 4:
                check_node.set_row_column(current_row,left);    // hit bottom right -> go left
            break;
            case 5:
                check_node.set_row_column(down,current_col);    // hit right -> go down
            break;
            case 6:
                check_node.set_row_column(up,current_col);      // hit bottom left -> go up
            break;
            case 7:
                check_node.set_row_column(current_row,left);    // hit bottom -> go left 
            break;
            case -1:
            check_node.set_row_column(current_row,left);     // go left
            break;
        }

        this->print_map(map,max_row_size,max_col_size,start_node,end_node,check_node);
        usleep(100000);               // 1s = 1,000,000 ; delaying system 0.5s (0.5x1000000) to display animation
        this->recursion(map,max_row_size,max_col_size,start_node,end_node,check_node,found_node);
    }
}

void Recursion_Pathfinder::find_path(char map[][COLUMN_SIZE], int max_row_size, int max_col_size, Node start_node, Node end_node){
    this->show_title();

    Node check_node;
    //this->copy_node(start_node,check_node);
    check_node.set_row_column(start_node.get_x_row(),start_node.get_y_column());
    cout << "Copy Node";  this->display_node(check_node);

    this->set_start_check_node(check_node, start_node);

    cout << "Start Check Node";  this->display_node(check_node);
    this->recursion(map,max_row_size,max_col_size,start_node,end_node,check_node, false);
}

void Recursion_Pathfinder::show_title(){
    system("clear");   
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                  RECURSION PATHFINDER                 │\n";
    cout << "\t•-------------------------------------------------------•\n";
}

