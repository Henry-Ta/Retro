#ifndef SORT_MANAGER_H
#define SORT_MANAGER_H

#include "state.h"
#include "bubble_sort.h"
#include "selection_sort.h"

class Sort_Manager : public State, public Bubble_Sort, public Selection_Sort
{
private:
    Bubble_Sort bubble_sort;
    Selection_Sort selection_sort;

public:
    Sort_Manager();

    void update();
    void display();

    void load();
    void play();

    void get_replay_exit();

    void run_game_body();

    void run_sort(int i);

    //void get_user_selection();

};

#endif // SORT_MANAGER_H
