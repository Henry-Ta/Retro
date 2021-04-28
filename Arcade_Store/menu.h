#ifndef MENU_H
#define MENU_H

#include "state.h"

class Menu : public State
{
public:
    Menu();

    void update();
    void display();
};

#endif // MENU_H
