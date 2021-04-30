#include "rock_paper_scissor.h"

#include <iostream>
using namespace std;

Rock_Paper_Scissor::Rock_Paper_Scissor():State()
{

}

void Rock_Paper_Scissor::update(){

    this->display();

    this->load();           // Ask user to confirm to start playing, meanwhile assign a flag to comeback to user_selection when game is over

    this->play();
}

void Rock_Paper_Scissor::load(){
    if(!this->get_is_started() && !this->get_is_running() && !this->get_is_finished()){
        int user_choice;
        cout << "\n\t\t\tAre you ready ? (Yes-1|No-0) ";
        cin >> user_choice;

        if(user_choice==0){         // Answer No, stop loading game
            this->get_user_selection();
        }else{                      // Yes, start game
            this->set_is_started(true);
            this->set_is_running(true);     // to check replay exit later on

        }
    }
}

void Rock_Paper_Scissor::play(){
    if(this->get_is_started() && !this->get_is_over()){         // MAIN PART to RUN GAME
        if(this->get_is_running()){         // Start Game

            this->run_game_body();

            this->set_is_running(false);

        }else{                              // Game finished
            this->get_replay_exit();
        }
    }else if(this->get_is_over()){              // When game is over
        this->get_user_selection();             // get user selection to navigate to other functions
    }
}

void Rock_Paper_Scissor::get_user_selection(){
    int i;
    cout << "\n\t\t\tWhich number do you choose? ";
    cin >> i;

    if(i==6 || i==7 || i==8 || i==9){			// if selection is match with any options in list
        //this->set_user_selection(i);
        this->set_next_state(i);
        this->set_is_finished(true);
    }else if(i==0){
        exit(0);
    }else{						// not match any option
        cout << "Wrong input, please try again !";
    }
}

void Rock_Paper_Scissor::get_replay_exit(){
    if(!this->get_is_finished() && !this->get_is_over()){
        int game_replay;
        cout << "\n\t\tDo you want to replay or exit ? (Replay-1|Exit-0) ";
        cin >> game_replay;
        if(game_replay==1 || game_replay==0){
            if(game_replay==0){             // exit game
                //this->set_is_over(true);        // turn on flag "game over" to come back to user selection
                this->set_next_state(8);        // exit to main menu
                this->set_is_finished(true);
            }else{                          // replay
                this->set_next_state(1);        // renew current game state by
                this->set_is_finished(true);    // pointing to the new state but same game (state) id
            }
        }else{
            cout << "Wrong Input, please try again";
        }
    }
}

void Rock_Paper_Scissor::run_game_body(){
    int user_choice;
    cout << "\t\t1. ROCK\n";
    cout << "\t\t2. PAPER\n";
    cout << "\t\t3. SCISSOR\n";
    cout << "\t\tEnter your choice: ";
    cin >> user_choice;

    this->determine_winner(user_choice, this->get_computer_choice());

}

int Rock_Paper_Scissor::get_computer_choice(){
    srand(time(NULL));
    int comp_choice = rand() % 3 + 1;
    return comp_choice;
}

void Rock_Paper_Scissor::determine_winner(int user_choice, int computer_choice){
    if(user_choice == 1 && computer_choice == 2){
        cout << "\tComputer WIN ! Paper wraps Rock";
    }else if(user_choice == 2 && computer_choice == 3){
        cout << "\tComputer WIN ! Scissor cuts Paper";
    }else if(user_choice == 3 && computer_choice == 1){
        cout << "\tComputer WIN ! Rock smashes Scissor";
    }else if(user_choice == 1 && computer_choice == 3){
        cout << "\tYOU WIN ! Rock smashes Scissor";
    }else if(user_choice == 2 && computer_choice == 1){
        cout << "\tYOU WIN ! Paper wraps Rock";
    }else if(user_choice == 3 && computer_choice == 2){
        cout << "\tYOU WIN ! Scissor cuts Paper";
    }else{
        cout << "\tTIE";
    }
}

void Rock_Paper_Scissor::display(){
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                   ROCK-PAPER-SCISSOR                  │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       8. Menu         9. About           0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}
