#include "../Headers/pathfinder.h"

#include <iostream>
#include <iomanip>
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
    cout << "           End Node("<<end_node.get_x_row()<<", "<<end_node.get_y_column()<<") E\n\n";

    int i,j;
    map[start_node.get_x_row()][start_node.get_y_column()]='S';
    map[end_node.get_x_row()][end_node.get_y_column()]='E';
    if((check_node.get_x_row()>=0 && check_node.get_x_row()<max_row_size) && (check_node.get_y_column()>=0 && check_node.get_y_column()<max_col_size)) 
        map[check_node.get_x_row()][check_node.get_y_column()]='*';

    cout<<"      0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15\n";
    for(i=0;i<max_row_size;i++){        // row
        cout <<"    •---------------------------------------------------------------•\n"<<setw(3)<<i<<" ";
        for(j=0;j<max_col_size;j++){    // col
            cout << "│ " << map[i][j]<<" ";
        }
        cout<<"│"<<endl;
    }             
    cout <<"    •---------------------------------------------------------------•\n    ";
    //cout<<endl;
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


void Pathfinder::copy_node(Node *from_node, Node *to_node){
    to_node->set_x_row(from_node->get_x_row());
    to_node->set_y_column(from_node->get_y_column());
}

void Pathfinder::display_node(Node n){
    cout <<"("<<n.get_x_row()<<", "<<n.get_y_column()<<" )";
}
