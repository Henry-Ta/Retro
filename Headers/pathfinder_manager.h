#ifndef PATHFINDER_MANAGER_H
#define PATHFINDER_MANAGER_H

#include "state.h"

class Pathfinder_Manager : public State
{
public:
    Pathfinder_Manager();

    void update();
    void display();

    void load();
    void play();

    void get_replay_exit();

    void run_game_body();

    void run_pathfinding(int i);

};

#endif // PATHFINDER_MANAGER_H