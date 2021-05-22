#ifndef INDEED_SCRAPER_H
#define INDEED_SCRAPER_H

#include "state.h"
#include "indeed_data.h"

#include <vector>  //vector<string>
class Indeed_Scraper : public State, public Indeed_Data
{
private:
    vector<Indeed_Data> indeed_data; 

public:
    
    Indeed_Scraper();

    void update();
    void display();

    void load();
    void play();

    void get_replay_exit();

    void run_game_body();

    void run_scraping();

    void get_data();

    void display_data();

    string shorten_length(int max_length, string s);
};

#endif // INDEED_SCRAPER_H
