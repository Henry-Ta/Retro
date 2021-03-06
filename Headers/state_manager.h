#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "user.h"
#include "menu.h"
#include "about.h"
#include "user_page.h"
#include "rock_paper_scissor.h"
#include "sort_manager.h"
#include "search_manager.h"
#include "web_scraper_manager.h"
#include "pathfinder_manager.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()
#include <stdlib.h>         // Used for system("clear")
#include <algorithm>        // Used for converting string to upper/lower case

using namespace std;

class State_Manager : public User
{
private:
    bool is_running;                // check whether a specific state is running (Menu, Log Out, Game,..)
    int state;                      // get id of state

    Menu menu;
    About about;
    User_Page user_page;

    Rock_Paper_Scissor rock_paper_scissor;
    Sort_Manager sort_manager;
    Search_Manager search_manager;

    Web_Scraper_Manager web_scraper_manager;

    Pathfinder_Manager pathfinder_manager;

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
