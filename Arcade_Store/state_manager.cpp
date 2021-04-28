#include "state_manager.h"
#include "user_profile.h"
#include "menu.h"
#include "about.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()
#include <stdlib.h>         // Used for system("clear")
#include <algorithm>        // Used for converting string to upper/lower case

using namespace std;

State_Manager::State_Manager():User_Profile()           // Constructor: inherits from User_Profile for user info
{
    if(User_Profile::get_is_accessed()){                // passed user validation
        this->set_is_running(true);
        this->set_state(8);                 // start with state of Menu (8)
    }else{                                              // failed user validation
        cout << "Access Denied";
        State_Manager();
    }
}

void State_Manager::set_is_running(bool s){
    this->is_running = s;
}
bool State_Manager::get_is_running(){
    return this->is_running;
}

// using set/get state to pick a specific state to run from update()
void State_Manager::set_state(int i){
    this->state = i;
}
int State_Manager::get_state(){
    return this->state;
}

void State_Manager::update(){
    this->show_logo();
    string id_upper = User_Profile::get_user_id();
    transform(id_upper.begin(), id_upper.end(), id_upper.begin(), ::toupper);       // convert user id to upper case for displaying
    cout << "\n\t"+id_upper+"(6)\t\t\t\t\tLog Out(7)\n";

    switch(this->get_state()){
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 8:
            if(!menu.get_is_finished()){            // if (Menu) state didn't finish
                menu.update();                      // keep updating
            }else {                                                 // if (Menu) state finished
                this->set_state(menu.get_next_state());             // update to the next chosen state
                menu.set_is_finished(false);                        // reset flag to check state finished
            }
            break;

        case 9:
            if(about.get_is_finished()==false){
                about.update();
            }else{
                this->set_state(about.get_next_state());
                about.set_is_finished(false);
            }
            break;

        case 0:                                     // NEED TO UPDATE, NOT WORK AS EXPECTED
            this->set_is_running(false);
            break;
    }
}

void State_Manager::run(){
    do{
        system("clear");
        this->update();
        usleep(1000);               // delaying system to display animation
    }while(this->get_is_running());
}

void State_Manager::show_logo(){
    cout<<"\t  _______  _______  _______  _______  ______   _______     \n";
    cout<<"\t (  ___  )(  ____ )(  ____ \\(  ___  )(  __  \\ (  ____ \\    \n";
    cout<<"\t | (   ) || (    )|| (    \\/| (   ) || (  \\  )| (    \\/    \n";
    cout<<"\t | (___) || (____)|| |      | (___) || |   ) || (__        \n";
    cout<<"\t |  ___  ||     __)| |      |  ___  || |   | ||  __)       \n";
    cout<<"\t | (   ) || (\\ (   | |      | (   ) || |   ) || (          \n";
    cout<<"\t | )   ( || ) \\ \\__| (____/\\| )   ( || (__/  )| (____/\\    \n";
    cout<<"\t |/     \\||/   \\__/(_______/|/     \\|(______/ (_______/    \n";
}
