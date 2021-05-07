#include "menu.h"


Menu::Menu():State()
{
    //this->set_current_state("MENU");
}

void Menu::update(){
    this->display();

    int i;
    cout << "\n\t\t\tWhich number do you choose? ";
    cin >> i;

    if(i==1 || i==2 || i==6 || i==7 || i==8 || i==9){			// if selection is match with any options in list
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
    cout << "\t│                 2. Sort                               │\n";
    cout << "\t│                 3. Game 3                             │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       8. Menu         9. About           0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}
