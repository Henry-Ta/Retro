#ifndef MENU_H
#define MENU_H

#include "state.h"

#include <iostream>

using namespace std;

class Menu : public State
{
public:
    Menu();

    void update();
    void display();

    void get_user_selection();
};

#endif // MENU_H
