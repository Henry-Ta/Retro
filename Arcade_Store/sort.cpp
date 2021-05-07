#include "sort.h"

#include <iostream>
using namespace std;

Sort::Sort():State()
{

}

void Sort::update(){

    this->display();

    this->load();           // Ask user to confirm to start playing, meanwhile assign a flag to comeback to user_selection when game is over

    this->play();
}

void Sort::load(){

    this->set_is_started(true);
    this->set_is_running(true);
}

void Sort::play(){
    if(this->get_is_started()){         // MAIN PART to RUN GAME
        this->run_game_body();

        if(!this->get_is_running()){            // when game finished, move to replay_exit event
            this->get_replay_exit();
        }
    }
}

void Sort::get_user_selection(){
    int i;
    cout << "\n\t\t\tWhich number do you choose? ";
    cin >> i;

    if(i==6 || i==7 || i==8 || i==9){			// if selection is match with any options in list
        this->set_next_state(i);
        this->set_is_finished(true);
    }else if(i==0){
        exit(0);
    }else{						// not match any option
        cout << "Wrong input, please try again !";
        this->get_user_selection();
    }
}

void Sort::get_replay_exit(){
    int game_replay;
    cout << "\n\t\tDo you want to replay or exit ? (Replay-1|Exit-0) ";
    cin >> game_replay;
    if(game_replay==1 || game_replay==0){
        if(game_replay==0){             // exit game
            this->set_next_state(8);        // exit to main menu
            this->set_is_finished(true);
        }else{                          // replay
            this->set_next_state(2);        // renew current game state by
            this->set_is_finished(true);    // pointing to the new state but same game (state) id
        }
    }else{
        cout << "Wrong Input, please try again";
        this->get_replay_exit();
    }
}

void Sort::run_game_body(){
    int user_choice;
    cout << "\n\t\t\t\t1. Bubble Sort";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> user_choice;

    if(user_choice==1){
        this->run_sort(user_choice);

        //---------------------------------------GAME FINISHED
        this->set_is_running(false);        // When game is finished, turn on flag to move to replay_exit event
    }else{
        cout << "Wrong input, please try again";
        this->run_game_body();
    }

}

void Sort::run_sort(int i){
    switch(i){
        case 1:
        cout << "This is bubble sort";
        break;
    }
}

int Sort::get_computer_choice(){
    srand(time(NULL));
    int comp_choice = rand() % 3 + 1;
    return comp_choice;
}

void Sort::display(){
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                          SORT                         │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       8. Menu         9. About           0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}
