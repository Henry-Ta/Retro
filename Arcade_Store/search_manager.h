#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

#include "state.h"
#include "linear_search.h"

class Search_Manager : public State, public Linear_Search
{
private:
    Linear_Search linear_search;

public:
    Search_Manager();

    void update();
    void display();

    void load();
    void play();

    void get_replay_exit();

    void run_game_body();

    void run_search(int i);
};

#endif // SEARCH_MANAGER_H
