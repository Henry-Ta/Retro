#ifndef PATHFINDER_MANAGER_H
#define PATHFINDER_MANAGER_H

#include "state.h"
#include "recursion_pathfinder.h"

class Pathfinder_Manager : public State, public Recursion_Pathfinder
{
private:
    Recursion_Pathfinder recursion_pathfinder;

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
