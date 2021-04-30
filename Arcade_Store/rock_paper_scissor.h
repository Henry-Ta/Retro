#ifndef ROCK_PAPER_SCISSOR_H
#define ROCK_PAPER_SCISSOR_H

#include "state.h"

class Rock_Paper_Scissor : public State
{
public:
    Rock_Paper_Scissor();

    void update();
    void display();

    void load();
    void play();

    void get_user_selection();

    void get_replay_exit();

    void run_game_body();

    int get_computer_choice();

    void determine_winner(int user_choice, int computer_choice);

};

#endif // ROCK_PAPER_SCISSOR_H
