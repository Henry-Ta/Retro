#include "../Headers/pathfinder.h"

#include <iostream>
using namespace std;

Pathfinder::Pathfinder(){}

void Pathfinder::print_map(char map[][COLUMN_SIZE], int max_row_size,int max_col_size, Node start_node, Node end_node){
    cout << "\t    Start Node("<<start_node.get_x_row()<<", "<<start_node.get_y_column()<<") S\t";
    cout << "           End Node("<<end_node.get_x_row()<<", "<<end_node.get_y_column()<<") E\n";

    int i,j;
    map[start_node.get_x_row()][start_node.get_y_column()]='S';
    map[end_node.get_x_row()][end_node.get_y_column()]='E';
    
    for(i=0;i<max_row_size;i++){        // row
        cout <<"    •---------------------------------------------------------------•\n    ";
        for(j=0;j<max_col_size;j++){    // col
            cout << "│ " << map[i][j]<<" ";
        }
        cout<<"│"<<endl;
    }             
    cout <<"    •---------------------------------------------------------------•\n    ";
    cout<<endl;
}

void Pathfinder::print_map(char map[][COLUMN_SIZE], int max_row_size,int max_col_size, Node start_node, Node end_node, Node check_node){
    cout << "\t    Start Node("<<start_node.get_x_row()<<", "<<start_node.get_y_column()<<") S\t";
    cout << "           End Node("<<end_node.get_x_row()<<", "<<end_node.get_y_column()<<") E\n";

    int i,j;
    map[start_node.get_x_row()][start_node.get_y_column()]='S';
    map[end_node.get_x_row()][end_node.get_y_column()]='E';
    map[check_node.get_x_row()][check_node.get_y_column()]='*';

    for(i=0;i<max_row_size;i++){        // row
        cout <<"    •---------------------------------------------------------------•\n    ";
        for(j=0;j<max_col_size;j++){    // col
            cout << "│ " << map[i][j]<<" ";
        }
        cout<<"│"<<endl;
    }             
    cout <<"    •---------------------------------------------------------------•\n    ";
    cout<<endl;
}

bool Pathfinder::found_node(Node check_node, Node search_node){
    //for(int i=search_node.get_x_row()-1; i<=search_node.get_x_row()+1;i++)
        //for(int j=search_node.get_y_column()-1;j<=search_node.get_y_column()+1;j++)

    if(check_node.get_x_row() == search_node.get_x_row()){      // same row
        if(this->match_right_node(check_node,search_node) || this->match_left_node(check_node,search_node))
            return true;
    }else if(check_node.get_y_column() == search_node.get_y_column()){      // same col
        if(this->match_above_node(check_node,search_node) || this->match_below_node(check_node,search_node))
            return true;
    }   
    return false;
}

bool Pathfinder::match_node(Node a, Node b){            // matching node
    if(a.get_x_row() == b.get_x_row() && a.get_y_column()==b.get_y_column())
        return true;
    return false;
}

bool Pathfinder::match_left_node(Node check_node, Node left_node){
    if(check_node.get_y_column()-1>=0)
        if(check_node.get_x_row()==left_node.get_x_row() && check_node.get_y_column()-1==left_node.get_y_column())
            return true;
    return false;
}

bool Pathfinder::match_right_node(Node check_node, Node right_node){
    if(check_node.get_y_column()+1>=0)
        if(check_node.get_x_row() == right_node.get_x_row() && check_node.get_y_column()+1==right_node.get_y_column())
            return true;
    return false;
}

bool Pathfinder::match_above_node(Node check_node, Node above_node){
    if(check_node.get_x_row()-1>=0)
        if(check_node.get_x_row()-1 == above_node.get_x_row() && check_node.get_y_column()==above_node.get_y_column())
            return true;
    return false;
}

bool Pathfinder::match_below_node(Node check_node, Node below_node){
    if(check_node.get_x_row()+1>=0)
        if(check_node.get_x_row()+1 == below_node.get_x_row() && check_node.get_y_column()==below_node.get_y_column())
            return true;
    return false;
}

int Pathfinder::spiral_path(Node check_node, int row_size, int col_size){
    //int left = check_node.get_y_column()-1;
    //int right = check_node.get_y_column()+1;
    //int up= check_node.get_x_row()-1;
    //int down= check_node.get_x_row()+1;

    int current_row=check_node.get_x_row();
    int current_col=check_node.get_y_column();

    if(current_col-1<0){        // hit left wall
        if(current_row-1<0)     // hit top left corner
            //check_node.set_row_column(current_row,right);
            return 0;
        else
            //check_node.set_row_column(up,current_col);  // go up
            return 1;
    }else if(current_row-1<0){  // hit top wall
        if(current_col+1>COLUMN_SIZE-1)     // hit top right corner
            //check_node.set_row_column(down,current_col);
            return 2;
        else
            //check_node.set_row_column(current_row,right);   // go right
            return 3;
    }else if(current_col+1>COLUMN_SIZE-1){
        if(current_row+1>ROW_SIZE-1)        // hit bottom right 
            //check_node.set_row_column(current_row,left);
            return 4;
        else
            //check_node.set_row_column(down,current_col);
            return 5;
    }else if(current_row+1>ROW_SIZE-1){
        if(current_col-1<0)
            //check_node.set_row_column(up,current_col);
            return 6;
        else
            //check_node.set_row_column(current_row,left);
            return 7;
    }
    return -1;
}

void Pathfinder::copy_node(Node copied, Node copy){
    copy.set_x_row(copied.get_x_row());
    copy.set_y_column(copied.get_y_column());
}

void Pathfinder::display_node(Node n){
    cout << "("<<n.get_x_row()<<", "<<n.get_y_column()<<" )";
}
