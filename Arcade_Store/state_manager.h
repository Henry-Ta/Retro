#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "user_profile.h"
#include "./menu.h"
#include "./about.h"

class State_Manager : public User_Profile
{
private:
    bool is_running;
    char state;

    Menu menu;
    About about;

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
