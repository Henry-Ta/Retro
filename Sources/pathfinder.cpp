#include "../Headers/pathfinder.h"

#include <iostream>
using namespace std;

Pathfinder::Pathfinder(){}

void Pathfinder::print_map(char map[][COLUMN_SIZE], int max_row_size,int max_col_size, Node start_node, Node end_node){
    cout << "\t    Start Node("<<start_node.get_x_row()<<", "<<start_node.get_y_column()<<") S\t";
    cout << "\t  End Node("<<end_node.get_x_row()<<", "<<end_node.get_y_column()<<") E\n";

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

bool Pathfinder::compare_node(Node a, Node b){
    if(a.get_x_row() != b.get_x_row() && a.get_y_column()!=b.get_y_column())
        return true;
    return false;
}
