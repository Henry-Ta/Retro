#ifndef INDEED_SCRAPER_H
#define INDEED_SCRAPER_H

#include "state.h"

class Indeed_Scraper : public State
{
public:
    Indeed_Scraper();

    void update();
    void display();

    void load();
    void play();

    void get_replay_exit();

    void run_game_body();

    void run_scraping();
};

#endif // INDEED_SCRAPER_H
