#ifndef INDEED_SCRAPER_H
#define INDEED_SCRAPER_H

#include "state.h"
#include "indeed_data.h"
class Indeed_Scraper : public State, public Indeed_Data
{
private:
    Indeed_Data indeed_data[15];

public:
    
    Indeed_Scraper();

    void update();
    void display();

    void load();
    void play();

    void get_replay_exit();

    void run_game_body();

    void run_scraping();

    void get_data(Indeed_Data indeed_data[]);

    void display_data(Indeed_Data indeed_data[], int data_size);
};

#endif // INDEED_SCRAPER_H
