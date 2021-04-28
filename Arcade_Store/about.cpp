#include "about.h"
#include "state.h"

#include <iostream>

using namespace std;

About::About():State()
{
    //this->set_current_state("ABOUT");
}

void About::update(){
    this->display();

    int i;
    cout << "\n\t\t\tWhich number do you choose ? ";
    cin >> i;

    if(i==6 || i==7 || i==8 || i==9){			//if user's choice match any option on the list
        //this->set_user_selection(i);
        this->set_next_state(i);
        this->set_is_finished(true);
    }else if(i==0){
        exit(0);
    }else{						// not match
        cout << "Wrong input, please try again !";
    }
}

void About::display(){
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                         ABOUT                         │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                    Author : Henry Ta                  │\n";
    cout << "\t│                Student ID : 100301469                 │\n";
    cout << "\t│                    Github : Henry-Ta                  │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       8. Menu         9. About           0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}
