#include "../Headers/recursion_pathfinder.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()
using namespace std;

Recursion_Pathfinder::Recursion_Pathfinder(){}

void Recursion_Pathfinder::set_start_check_node(Node *check_node,const Node start_node){
    // start from left (if possible)
    // otherwise -> above -> right -> below
    int col=check_node->get_y_column();
    int row=check_node->get_x_row();

    if(!this->match_left_node(*check_node,start_node)){
        check_node->set_y_column(col-1);
    }
    else if(!this->match_above_node(*check_node,start_node)){
        check_node->set_x_row(row-1);
    }
    else if(!this->match_right_node(*check_node,start_node)){
        check_node->set_y_column(col+1);
    }
    else{
        check_node->set_x_row(row+1);
    }
}


void Recursion_Pathfinder::spiral_recursion(char map[][COLUMN_SIZE], int max_row_size, int max_col_size, Node start_node, Node end_node, Node check_node, bool found_node, int spiral_gap){
    int left = check_node.get_y_column()-1;
    int right = check_node.get_y_column()+1;
    int up= check_node.get_x_row()-1;
    int down= check_node.get_x_row()+1;
    int current_row=check_node.get_x_row();
    int current_col=check_node.get_y_column();

    int start_node_row=start_node.get_x_row();
    int start_node_col=start_node.get_y_column();

    this->print_map(map,max_row_size,max_col_size,start_node,end_node,check_node);

    found_node = this->found_node(check_node,end_node);

    if(!found_node){
        check_node.set_row_column(current_row,left);     // go left

        if(current_col==start_node_col-spiral_gap){                       // hit left wall
            if(current_row==start_node_row-spiral_gap)                    // hit top left corner
                check_node.set_row_column(current_row,right);                       // go right
            else
                check_node.set_row_column(up,current_col);                          // go up

        }else if(current_row==start_node_row-spiral_gap){                 // hit top wall
            if(current_col==start_node_col+spiral_gap)                    // hit top right corner
                check_node.set_row_column(down,current_col);                        // go down
            else
                check_node.set_row_column(current_row,right);                       // go right

        }else if(current_col==start_node_col+spiral_gap){                 // hit right wall
            if(current_row==start_node_row+spiral_gap)                    // hit bottom right corner 
                check_node.set_row_column(current_row,left);                        // go left
            else
                check_node.set_row_column(down,current_col);                        // go down 

        }else if(current_row==start_node_row+spiral_gap){                 // hit bottom wall
            spiral_gap++;
            if(current_col==start_node_col - spiral_gap)                  // hit bottom left corner
                check_node.set_row_column(up,current_col);                          // go up
            else
                check_node.set_row_column(current_row,left);                        // go left
        }

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

        this->print_map(map,max_row_size,max_col_size,start_node,end_node,check_node);
        usleep(100000);               // 1s = 1,000,000 ; delaying system 0.5s (0.5x1000000) to display animation
        this->spiral_recursion(map,max_row_size,max_col_size,start_node,end_node,check_node,found_node, spiral_gap);
    }
}

void Recursion_Pathfinder::find_path(char map[][COLUMN_SIZE], int max_row_size, int max_col_size, Node start_node, Node end_node){
    this->show_title();

    Node check_node;
    this->copy_node(&start_node,&check_node);
    //check_node.set_row_column(start_node.get_x_row(),start_node.get_y_column());        // clone start node to check node

    //this->set_start_check_node(&check_node, start_node);          // move check node to the left of start node (not important)

    this->spiral_recursion(map,max_row_size,max_col_size,start_node,end_node,check_node, false, 1);
}

void Recursion_Pathfinder::show_title(){
    system("clear");   
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                  RECURSION PATHFINDER                 │\n";
    cout << "\t•-------------------------------------------------------•\n";
}

