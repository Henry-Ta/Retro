#include "../Headers/pathfinder_manager.h"

#include <iostream>
using namespace std;

Pathfinder_Manager::Pathfinder_Manager():State()
{

}

void Pathfinder_Manager::update(){
    this->display();

    this->load();           // Turn on flag Ask user to confirm to start playing

    this->play();
}

void Pathfinder_Manager::load(){
    this->set_is_started(true);
    this->set_is_running(true);
}

void Pathfinder_Manager::play(){
    if(this->get_is_started()){         // MAIN PART to RUN GAME
        this->run_game_body();

        if(!this->get_is_running()){            // when game finished, move to replay_exit event
            this->get_replay_exit();
        }
    }
}

void Pathfinder_Manager::get_replay_exit(){
    int game_replay;
    cout << "\t    Do you want to replay or exit ? (Replay-1|Exit-0) ";
    cin >> game_replay;
    if(game_replay==1 || game_replay==0){
        if(game_replay==0){             // exit game
            this->set_next_state(13);        // exit to main menu
            this->set_is_finished(true);
        }else{                          // replay
            this->set_next_state(5);        // renew current game state by
            this->set_is_finished(true);    // pointing to the new state but same game (state) id
        }
    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->get_replay_exit();
    }
}

void Pathfinder_Manager::run_game_body(){
    int user_choice;
    cout << "\n\t\t\t     1. Recursion";
    cout << "\n\n\t\t\t     0. Exit to main menu";
    cout << "\n\n\t\t\t     Enter your choice: ";
    cin >> user_choice;

    if(user_choice == 0){
        this->set_next_state(13);        // exit to main menu
        this->set_is_finished(true);
    }else if(user_choice == 1){
        this->run_pathfinding(user_choice);

        //---------------------------------------GAME FINISHED
        this->set_is_running(false);        // When game is finished, turn on flag to move to replay_exit event
    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->run_game_body();
    }

}

void Pathfinder_Manager::run_pathfinding(int i){
    char map[ROW_SIZE][COLUMN_SIZE];
    for(int i=0;i<ROW_SIZE;i++){
        for(int j=0;j<COLUMN_SIZE;j++){
            map[i][j]=' ';
        }
    }

    srand((unsigned)time(NULL));
    int row=rand() % (ROW_SIZE-1);
    int col=rand() % (COLUMN_SIZE-1);
    Node start_node(row,col);
    //cout << "Start: ("<<(start_node.get_x_row())<<", "<<start_node.get_y_column()<<")";

    row=rand() % (ROW_SIZE-1);
    col=rand() % (COLUMN_SIZE-1);
    Node end_node(row,col);
    //cout << "End: ("<<(end_node.get_x_row())<<", "<<end_node.get_y_column()<<")";

    while(match_node(start_node,end_node)){
        //cout <<"Duplicate";
        int row=rand() % (ROW_SIZE-1);
        int col=rand() % (COLUMN_SIZE-1);
        start_node.set_row_column(row,col);

        row=rand() % (ROW_SIZE-1);
        col=rand() % (COLUMN_SIZE-1);
        end_node.set_row_column(row,col);
    }

    switch(i){
        case 1:
        recursion_pathfinder.find_path(map,ROW_SIZE,COLUMN_SIZE,start_node,end_node);
        break;
    }
}

void Pathfinder_Manager::display(){
    system("clear");
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                PATH FINDING VISUALIZER                │\n";
    cout << "\t•-------------------------------------------------------•\n";
}
