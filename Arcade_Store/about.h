#ifndef ABOUT_H
#define ABOUT_H

#include "state.h"

#include <iostream>

using namespace std;

class About : public State
{
public:
    About();

    void update();
    void display();
};

#endif // ABOUT_H
