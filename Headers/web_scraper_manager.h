#ifndef WEB_SCRAPER_MANAGER_H
#define WEB_SCRAPER_MANAGER_H

#include "state.h"
#include "indeed_scraper.h"

class Web_Scraper_Manager : public State, public Indeed_Scraper
{
private:
    Indeed_Scraper indeed_scraper;

public:
    Web_Scraper_Manager();

    void update();
    void display();

    void load();
    void play();

    void get_replay_exit();

    void run_game_body();

    void run_scraping(int i);

};

#endif // WEB_SCRAPER_MANAGER_H