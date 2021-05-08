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
    /*if(!this->get_is_started() && !this->get_is_running()){
        int user_choice;
        cout << "\n\t\t\tAre you ready ? (Yes-1|No-0) ";
        cin >> user_choice;

        if(user_choice==1 || user_choice==0){
            switch(user_choice){
            case 0:         // Answer No, stop loading game
                this->get_user_selection();
                break;
            case 1:         // Yes, start game
                this->set_is_started(true);
                this->set_is_running(true);     // to check replay exit later on
                break;
            }
        }else{
            cout <<"Wrong input, please try again !";
            this->load();
        }
    }*/

    this->set_is_started(true);
    this->set_is_running(true);
}

void Rock_Paper_Scissor::play(){
    /*
    if(this->get_is_started() && !this->get_is_over()){         // MAIN PART to RUN GAME
        this->run_game_body();

        if(!this->get_is_running()){            // when game finished, move to replay_exit event
            this->get_replay_exit();
        }
    }else if(this->get_is_over()){              // When game is over
        this->get_user_selection();             // get user selection to navigate to other functions
    }*/


    if(this->get_is_started()){         // MAIN PART to RUN GAME
        this->run_game_body();

        if(!this->get_is_running()){            // when game finished, move to replay_exit event
            this->get_replay_exit();
        }
    }
}

void Rock_Paper_Scissor::get_user_selection(){
    int i;
    cout << "\n\t\t\tWhich number do you choose? ";
    cin >> i;

    if(i==6 || i==7 || i==8 || i==9){			// if selection is match with any options in list
        this->set_next_state(i);
        this->set_is_finished(true);
    }else if(i==0){
        exit(0);
    }else{						// not match any option
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->get_user_selection();
    }
}

void Rock_Paper_Scissor::get_replay_exit(){
    //if(!this->get_is_finished() && !this->get_is_over()){

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
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->get_replay_exit();
    }

    //}
}

void Rock_Paper_Scissor::run_game_body(){
    int user_choice;
    cout << "\n\t\t\t\t1. ROCK";
    cout << "\n\t\t\t\t2. PAPER";
    cout << "\n\t\t\t\t3. SCISSOR";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> user_choice;

    if(user_choice==1||user_choice==2||user_choice==3){
        this->determine_winner(user_choice, this->get_computer_choice());

        //---------------------------------------GAME FINISHED
        this->set_is_running(false);        // When game is finished, turn on flag to move to replay_exit event
    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->run_game_body();
    }

}

int Rock_Paper_Scissor::get_computer_choice(){
    srand(time(NULL));
    int comp_choice = rand() % 3 + 1;
    return comp_choice;
}

void Rock_Paper_Scissor::determine_winner(int user_choice, int computer_choice){
    if(user_choice == 1 && computer_choice == 2){
        cout << "\n\t\t-> Computer WIN ! PAPER wraps ROCK\n";
    }else if(user_choice == 2 && computer_choice == 3){
        cout << "\n\t\t-> Computer WIN ! SCISSOR cuts PAPER\n";
    }else if(user_choice == 3 && computer_choice == 1){
        cout << "\n\t\t-> Computer WIN ! ROCK smashes SCISSOR\n";
    }else if(user_choice == 1 && computer_choice == 3){
        cout << "\n\t\t-> YOU WIN ! ROCK smashes SCISSOR\n";
    }else if(user_choice == 2 && computer_choice == 1){
        cout << "\n\t\t-> YOU WIN ! PAPER wraps ROCK\n";
    }else if(user_choice == 3 && computer_choice == 2){
        cout << "\n\t\t-> YOU WIN ! SCISSOR cuts PAPER\n";
    }else{
        cout << "\n\t\t-> TIE\n";
    }
}

void Rock_Paper_Scissor::display(){
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                   ROCK-PAPER-SCISSOR                  │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       8. Menu         9. About           0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}
