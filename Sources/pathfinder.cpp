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
            //cout << "│" << map[i][j];
            cout << "│ " << map[i][j]<<" ";
        }
        cout<<endl;
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
            //cout << "│" << map[i][j];
            cout << "│ " << map[i][j]<<" ";
        }
        cout<<endl;
    }             
    cout <<"    •---------------------------------------------------------------•\n    ";
    cout<<endl;
}

bool Pathfinder::match_node(Node a, Node b){            // matching node
    if(a.get_x_row() == b.get_x_row() && a.get_y_column()==b.get_y_column())
        return true;
    return false;
}

bool Pathfinder::match_left_node(Node check_node, Node left_node){
    if(check_node.get_x_row()==left_node.get_x_row() && check_node.get_y_column()-1==left_node.get_y_column())
        return true;
    return false;
}

//bool Pathfinder::match_right_node(Node a, Node b){
    //if(a.get_x_row() == b.get_x_row() && a.get_y_column()==b.get_y_column())
        //return true;
    //else
        //return false;
//}
//bool Pathfinder::match_above_node(Node a, Node b){
    //if(a.get_x_row() == b.get_x_row() && a.get_y_column()==b.get_y_column())
        //return true;
    //else
        //return false;
//}
//bool Pathfinder::match_below_node(Node a, Node b){
    //if(a.get_x_row() == b.get_x_row() && a.get_y_column()==b.get_y_column())
        //return true;
    //else
        //return false;
//}

void Pathfinder::copy_node(Node copied, Node copy){
    copy.set_x_row(copied.get_x_row());
    copy.set_y_column(copied.get_y_column());
}
