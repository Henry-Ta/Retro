#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "user_profile.h"
#include "menu.h"
#include "about.h"
#include "user_page.h"

#include <iostream>
#include <unistd.h>         // Used for usleep()
#include <stdlib.h>         // Used for system("clear")
#include <algorithm>        // Used for converting string to upper/lower case

using namespace std;

class State_Manager : public User_Profile
{
private:
    bool is_running;
    int state;

    Menu menu;
    About about;
    User_Page user_page;

public:
    State_Manager();

    void set_is_running(bool s);
    bool get_is_running();

    void set_state(int i);
    int get_state();

    void run();
    void update();
    void load();
    void exit();

    void show_logo();
};

#endif // STATE_MANAGER_H
