#include "../Headers/indeed_scraper.h"

#include <iostream>
#include <Python.h>        // to embed python file (.py)
#include <fstream>          // to create file Indeed_Data.csv if not exists
#include <string>
#include <sstream>
#include <vector>           //vector<string> 
#include <algorithm>        // remove /n

using namespace std;

Indeed_Scraper::Indeed_Scraper() {

}

void Indeed_Scraper::update() {
    this->display();

    this->load();  // Turn on flag Ask user to confirm to start playing

    this->play();
}

void Indeed_Scraper::load() {
    this->set_is_started(true);
    this->set_is_running(true);
}

void Indeed_Scraper::play() {
    if (this->get_is_started()) {  // MAIN PART to RUN GAME
        this->run_game_body();

        if (!this->get_is_running()) {  // when game finished, move to
                                        // replay_exit event
            this->get_replay_exit();
        }
    }
}

void Indeed_Scraper::get_replay_exit() {
    int game_replay;
    cout << "\t\tDo you want to refresh or exit ? (Replay-1|Exit-0) ";
    cin >> game_replay;
    if (game_replay == 1 || game_replay == 0) {
        if (game_replay == 0) {       // exit game
            // Close the python instance
            Py_Finalize(); 
            this->set_next_state(8);  // exit to main menu
            this->set_is_finished(true);
        } else {                      // replay
            this->set_next_state(4);  // renew current game state by
            this->set_is_finished(true);  // pointing to the new state but same game (state) id
        }
    } else {
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->get_replay_exit();
    }
}

void Indeed_Scraper::run_game_body() {
    this->run_scraping();

    

    //---------------------------------------GAME FINISHED
    this->set_is_running(false);  // When game is finished, turn on flag to move
                                  // to replay_exit event
}

void Indeed_Scraper::display() {
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                    INDEED SCRAPER                     │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       8. Menu         9. About           0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}

void Indeed_Scraper::run_scraping() {   // Embedding Python file to scrap Indeed web
    ofstream file;  
    file.open("./Data/indeed_data_original.csv"); // open file, if not exist create a new file
    file.open("./Data/indeed_data_modified.csv");

    // Initialize the python instance
    Py_Initialize();

    // Run a simple file
    FILE* PScriptFile = fopen("./Python/indeed_scraper.py", "r");
    if (PScriptFile) {
        PyRun_SimpleFile(PScriptFile, "./Python/indeed_scraper.py");
        fclose(PScriptFile);
    }

    // Close the python instance
    //Py_Finalize();            // If close it here, get error when refresh, close in get_replay_exit()


    this->get_data(this->indeed_data);
    this->display_data(this->indeed_data, 15);
}

void Indeed_Scraper::get_data(Indeed_Data indeed_data[]){
    string line;
    ifstream read_file("./Data/indeed_data_modified.csv");

    getline(read_file, line); // read the first line , skip the first line when starting loo

    vector<string> store_data;
    while (!read_file.eof() ) {	// Use a while loop together with the getline() function to read the file line by line
        getline(read_file, line);       // start reading from the second line
        
        stringstream line_convert(line);
        string element;
        while (getline(line_convert, element, '|')) {
            element.erase(remove(element.begin(), element.end(), '\n'), element.end());     // remove new line character
            element.erase(remove(element.begin(), element.end(), '\r'), element.end());    // remove \r
            store_data.push_back(element);
        }
    }
    
    int store_data_size = (int)store_data.size();
    int position=0;     // count number from 0->7 and reset 0->7 to group up each line of data
    int index=0;        // assign value to a specific index place 
    for (int i = 0; i < store_data_size; i++){
        if(position==0){
            indeed_data[index].set_title(store_data.at(i));
        }else if(position==1){
            indeed_data[index].set_company(store_data.at(i));
        }else if(position==2){
            indeed_data[index].set_location(store_data.at(i));
        }else if(position==3){
            indeed_data[index].set_salary(store_data.at(i));
        }else if(position==4){
            indeed_data[index].set_date(store_data.at(i));
        }else if(position==5){
            indeed_data[index].set_rating(store_data.at(i));
        }else if(position==6){
            indeed_data[index].set_difficulty(store_data.at(i));
        }else if(position==7){
            indeed_data[index].set_remote(store_data.at(i));
        }

        position++;         // increase pos until enough 8 elements
        if(position==8){
            position=0;     // reset pos to start the new group
            index++;        // move to next row of data
        }
    }
}

void Indeed_Scraper::display_data(Indeed_Data indeed_data[], int data_size){
    cout << "--------------------------------------\n";
    for(int i=0;i<data_size;i++){
        cout<<"Date: "<<indeed_data[i].get_date()<<endl;     // get() return value, need to assign to a variable to display
    }
}
