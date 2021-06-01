#include "../Headers/web_scraper_manager.h"

#include <iostream>
using namespace std;

Web_Scraper_Manager::Web_Scraper_Manager():State()
{

}

void Web_Scraper_Manager::update(){

    this->display();

    this->load();           // Turn on flag Ask user to confirm to start playing

    this->play();
}

void Web_Scraper_Manager::load(){

    this->set_is_started(true);
    this->set_is_running(true);
}

void Web_Scraper_Manager::play(){
    if(this->get_is_started()){         // MAIN PART to RUN GAME
        this->run_game_body();

        if(!this->get_is_running()){            // when game finished, move to replay_exit event
            this->get_replay_exit();
        }
    }
}

void Web_Scraper_Manager::get_replay_exit(){
    int game_replay;
    cout << "\t\tDo you want to replay or exit ? (Replay-1|Exit-0) ";
    cin >> game_replay;
    if(game_replay==1 || game_replay==0){
        if(game_replay==0){             // exit game
            this->set_next_state(13);        // exit to main menu
            this->set_is_finished(true);
        }else{                          // replay
            this->set_next_state(4);        // renew current game state by
            this->set_is_finished(true);    // pointing to the new state but same game (state) id
        }
    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->get_replay_exit();
    }
}

void Web_Scraper_Manager::run_game_body(){
    int user_choice;
    cout << "\n\t\t\t     1. indeed.ca Scraper";
    cout << "\n\t\t\t     0. Exit to main menu";
    cout << "\n\n\t\t\t     Enter your choice: ";
    cin >> user_choice;

    if(user_choice == 0){
        this->set_next_state(13);        // exit to main menu
        this->set_is_finished(true);
    }else if(user_choice == 1){
        this->run_scraping(user_choice);

        //---------------------------------------GAME FINISHED
        this->set_is_running(false);        // When game is finished, turn on flag to move to replay_exit event
    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->run_game_body();
    }

}

void Web_Scraper_Manager::run_scraping(int i){
    switch(i){
        case 1:
        indeed_scraper.run_scraping();
        break;
    }
}

void Web_Scraper_Manager::display(){
    system("clear");
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                       WEB SCRAPER                     │\n";
    cout << "\t•-------------------------------------------------------•\n";
    //cout << "\t│       13. Menu        14. About          0. Exit      │\n";
    //cout << "\t•-------------------------------------------------------•\n";
}