#include "../Headers/state_manager.h"


State_Manager::State_Manager():User_Profile()           // Constructor: inherits from User_Profile for user info
{
    if(User_Profile::get_is_accessed()){                // passed user validation
        this->set_is_running(true);
        this->set_state(13);                             // start with the state of Menu (13)
        this->run();
    }else{                                              // failed user validation
        cout << "\nAccess-> Denied";
        this->set_is_running(false);
        this->set_state(-1);
        State_Manager();
    }
}

void State_Manager::set_is_running(bool s){
    this->is_running = s;
}
bool State_Manager::get_is_running(){
    return this->is_running;
}

// using set/get state to pick a specific state to run from update()
void State_Manager::set_state(int i){
    this->state = i;
}
int State_Manager::get_state(){
    return this->state;
}

void State_Manager::update(){
    system("clear");
    //this->show_logo();
    User_Profile::show_logo();

    string id_upper = User_Profile::get_user_id();
    transform(id_upper.begin(), id_upper.end(), id_upper.begin(), ::toupper);       // convert user id to upper case for displaying
    cout << "\n\t"+id_upper+"(11)\t\t\t\t\tLog Out(12)\n";

    switch(this->get_state()){
        case 1:
            this->load(1);
            break;

        case 2:
            this->load(2);
            break;

        case 3:
            this->load(3);
            break;

        case 4:
            this->load(4);
            break;

        case 5:
            this->load(5);
            break;

        //----------------------------------------- System options
        case 11:
            user_page.set_id(User_Profile::get_user_id());
            user_page.set_password(User_Profile::get_user_password());

            this->load(11);
            break;

        case 12:
            system("clear");
            User_Profile::set_is_accessed(false);
            State_Manager();
            break;

        case 13:
            this->load(13);
            break;

        case 14:
            this->load(14);
            break;
    }
}

void State_Manager::load(int state_id){         // use id of state to run that state
    switch(state_id){
    case 1:
        if(!rock_paper_scissor.get_is_finished()){      // state is running
            rock_paper_scissor.update();
        }else{                                          // state finished
            this->set_state(rock_paper_scissor.get_next_state());
            rock_paper_scissor.set_is_finished(false);

            rock_paper_scissor.set_is_started(false);       //refresh attributes to default
            rock_paper_scissor.set_is_running(false);
            //rock_paper_scissor.set_is_over(false);
        }
        break;

    case 2:
        if(!sort_manager.get_is_finished()){      // state is running
            sort_manager.update();
        }else{                                          // state finished
            this->set_state(sort_manager.get_next_state());
            sort_manager.set_is_finished(false);

            sort_manager.set_is_started(false);       //refresh attributes to default
            sort_manager.set_is_running(false);
        }
        break;

    case 3:
        if(!search_manager.get_is_finished()){      // state is running
            search_manager.update();
        }else{                                          // state finished
            this->set_state(search_manager.get_next_state());
            search_manager.set_is_finished(false);

            search_manager.set_is_started(false);       //refresh attributes to default
            search_manager.set_is_running(false);
        }
        break;

    case 4:
        if(!web_scraper_manager.get_is_finished()){      // state is running
            web_scraper_manager.update();
        }else{                                          // state finished
            this->set_state(web_scraper_manager.get_next_state());
            web_scraper_manager.set_is_finished(false);

            web_scraper_manager.set_is_started(false);       //refresh attributes to default
            web_scraper_manager.set_is_running(false);
        }
        break;

    case 5:
        if(!pathfinder_manager.get_is_finished()){      // state is running
            pathfinder_manager.update();
        }else{                                          // state finished
            this->set_state(pathfinder_manager.get_next_state());
            pathfinder_manager.set_is_finished(false);

            pathfinder_manager.set_is_started(false);       //refresh attributes to default
            pathfinder_manager.set_is_running(false);
        }
        break;

    //----------------------------------------- System options
    case 11:
        if(!user_page.get_is_finished()){
            user_page.update();
        }else{
            this->set_state(user_page.get_next_state());
            user_page.set_is_finished(false);
        }
        break;

    case 13:
        if(!menu.get_is_finished()){            // if (Menu) state didn't finish
            menu.update();                      // keep updating
        }else {                                                 // if (Menu) state finished
            this->set_state(menu.get_next_state());             // update to the next chosen state
            menu.set_is_finished(false);                        // reset flag to check state finished
        }
        break;

    case 14:
        if(!about.get_is_finished()){
            about.update();
        }else{
            this->set_state(about.get_next_state());
            about.set_is_finished(false);
        }
        break;

    }
}

void State_Manager::run(){
    while(this->get_is_running()){
        system("clear");
        this->update();
        //usleep(1000000);               // delaying system to display animation
    };
}

/*void State_Manager::show_logo(){
    cout<<"\n\t  _______  _______  _______  _______  ______   _______     \n";
    cout<<"\t (  ___  )(  ____ )(  ____ \\(  ___  )(  __  \\ (  ____ \\    \n";
    cout<<"\t | (   ) || (    )|| (    \\/| (   ) || (  \\  )| (    \\/    \n";
    cout<<"\t | (___) || (____)|| |      | (___) || |   ) || (__        \n";
    cout<<"\t |  ___  ||     __)| |      |  ___  || |   | ||  __)       \n";
    cout<<"\t | (   ) || (\\ (   | |      | (   ) || |   ) || (          \n";
    cout<<"\t | )   ( || ) \\ \\__| (____/\\| )   ( || (__/  )| (____/\\    \n";
    cout<<"\t |/     \\||/   \\__/(_______/|/     \\|(______/ (_______/    \n";

    cout<<"\n\t       _______  _______ _________ _______  _______\n"; 
    cout<<"\t      (  ____ )(  ____ \\\\__   __/(  ____ )(  ___  )\n"; 
    cout<<"\t      | (    )|| (    \\/   ) (   | (    )|| (   ) |\n"; 
    cout<<"\t      | (____)|| (__       | |   | (____)|| |   | |\n"; 
    cout<<"\t      |     __)|  __)      | |   |     __)| |   | |\n"; 
    cout<<"\t      | (\\ (   | (         | |   | (\\ (   | |   | |\n"; 
    cout<<"\t      | ) \\ \\__| (____/\\   | |   | ) \\ \\__| (___) |\n"; 
    cout<<"\t      |/   \\__/(_______/   )_(   |/   \\__/(_______)\n"; 
}*/
