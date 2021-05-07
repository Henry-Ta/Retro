#ifndef SORT_H
#define SORT_H

#include "state.h"

class Sort : public State
{
public:
    Sort();

    void update();
    void display();

    void load();
    void play();

    void get_user_selection();

    void get_replay_exit();

    void run_game_body();

    int get_computer_choice();

    void run_sort(int i);

};

#endif // SORT_H
