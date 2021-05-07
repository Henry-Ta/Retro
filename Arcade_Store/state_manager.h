#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "user_profile.h"
#include "menu.h"
#include "about.h"
#include "user_page.h"
#include "rock_paper_scissor.h"
#include "sort.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()
#include <stdlib.h>         // Used for system("clear")
#include <algorithm>        // Used for converting string to upper/lower case

using namespace std;

class State_Manager : public User_Profile
{
private:
    bool is_running;                // check whether a specific state is running (Menu, Log Out, Game,..)
    int state;                      // get id of state

    Menu menu;
    About about;
    User_Page user_page;

    Rock_Paper_Scissor rock_paper_scissor;
    Sort sort;

public:
    State_Manager();

    void set_is_running(bool s);
    bool get_is_running();

    void set_state(int i);
    int get_state();

    void run();
    void update();
    void load(int state_id);
    void exit();

    //void show_logo();
};

#endif // STATE_MANAGER_H
