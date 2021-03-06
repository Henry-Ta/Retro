#include "../Headers/menu.h"


Menu::Menu():State()
{

}

void Menu::update(){
    this->display();

    this->get_user_selection();
}

void Menu::get_user_selection(){
    int i;
    cout << "\n\t\t\tWhich number do you choose? ";
    cin >> i;

    if(i==1 || i==2 || i==3 || i==4 || i==5 || 
    i==11 || i==12 || i==13 || i==14){			// if selection is match with any options in list
        //this->set_user_selection(i);
        this->set_next_state(i);
        this->set_is_finished(true);
    }else if(i==0){
        exit(0);
    }else{						// not match any option
        cout << "Wrong input, please try again !";
    }
}

void Menu::display(){
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                       MAIN MENU                       │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                 1. Rock-Paper-Scissor                 │\n";
    cout << "\t│                 2. Sorting Visualizer                 │\n";
    cout << "\t│                 3. Searching Visualizer               │\n";
    cout << "\t│                 4. Web Scraper                        │\n";
    cout << "\t│                 5. Pathfinding Visualizer             │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       13. Menu        14. About          0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}
