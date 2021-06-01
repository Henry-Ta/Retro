#include "../Headers/user_page.h"


User_Page::User_Page():State()
{

}

void User_Page::set_id(string s){
    this->id = s;
}
string User_Page::get_id(){
    return this->id;
}

void User_Page::set_password(string s){
    this->password = s;
}
string User_Page::get_password(){
    return this->password;
}

void User_Page::update(){
    this->display(this->get_id(),this->get_password());

    int i;
    cout << "\n\t\t\tWhich number do you choose ? ";
    cin >> i;

    if(i==11 || i==12 || i==13 || i==14){			//if user's choice match any option on the list
        //this->set_user_selection(i);
        this->set_next_state(i);
        this->set_is_finished(true);
    }else if(i==0){
        exit(0);
    }else{						// not match
        cout << "Wrong input, please try again !";
    }
}

void User_Page::display(string id, string password){        // get id, pass from User_Profile class to display
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                          USER                         │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t                ♥ ID          : "+ id + "\n";
    cout << "\t                ♥ Password    : "+ password + "\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       13. Menu        14. About          0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}
