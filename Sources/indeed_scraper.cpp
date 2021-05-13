#include "../Headers/indeed_scraper.h"

#include <iostream>
#include <Python.h>        // to embed python file (.py)

using namespace std;

Indeed_Scraper::Indeed_Scraper()
{

}

void Indeed_Scraper::update(){

    this->display();

    this->load();           // Turn on flag Ask user to confirm to start playing

    this->play();
}

void Indeed_Scraper::load(){

    this->set_is_started(true);
    this->set_is_running(true);
}

void Indeed_Scraper::play(){
    if(this->get_is_started()){         // MAIN PART to RUN GAME
        this->run_game_body();

        if(!this->get_is_running()){            // when game finished, move to replay_exit event
            this->get_replay_exit();
        }
    }
}

void Indeed_Scraper::get_replay_exit(){
    int game_replay;
    cout << "\t\tDo you want to replay or exit ? (Replay-1|Exit-0) ";
    cin >> game_replay;
    if(game_replay==1 || game_replay==0){
        if(game_replay==0){             // exit game
            this->set_next_state(8);        // exit to main menu
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

void Indeed_Scraper::run_game_body(){
    this->run_scraping();

    //---------------------------------------GAME FINISHED
    this->set_is_running(false);        // When game is finished, turn on flag to move to replay_exit event
}

void Indeed_Scraper::display(){
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                    INDEED SCRAPER                     │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       8. Menu         9. About           0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}

void Indeed_Scraper::run_scraping(){
    //cout << "Hello Henry";
    

    //Initialize the python instance
	Py_Initialize();

    //Run a simple file
	FILE* PScriptFile = fopen("./Python/indeed_scraper.py", "r");
	if(PScriptFile){
		PyRun_SimpleFile(PScriptFile, "./Python/indeed_scraper.py");
		fclose(PScriptFile);
	}

    //Close the python instance
	Py_Finalize();
}
