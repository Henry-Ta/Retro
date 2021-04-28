#include "user_profile.h"

#include <iostream>
#include <string>
#include <stdlib.h>         // for system("clear")
#include <fstream>          // input/output to file
#include <algorithm>        // convert string to lower/upper case

User_Profile::User_Profile()
{
    int choice;
    this->show_login_signup();
    cin >> choice;
    this->set_user_selection(choice);

    switch(choice){
    case 1:
        this->set_is_accessed(this->user_login());
        break;
    case 2:
        this->set_is_accessed(this->user_signup());
        break;
    case 0:
        exit(0);
    default:
        system("clear");
        cout << "Wrong input, please try again!\n";
        User_Profile();
    }
}

void User_Profile::set_user_selection(int i){
    this->user_selection = i;
}
int User_Profile::get_user_selection(){
    return this->user_selection;
}

void User_Profile::set_user_id(string s){
    this->user_id = s;
}
string User_Profile::get_user_id(){
    return this->user_id;
}

void User_Profile::set_user_password(string s){
    this->user_password = s;
}
string User_Profile::get_user_password(){
    return this->user_password;
}

void User_Profile::set_user_score(int i){
    this->user_score = i;
}
int User_Profile::get_user_score(){
    return this->user_score;
}

void User_Profile::show_login_signup(){    
    this->show_logo();

    cout << "\n\t❅--------------| WELCOME TO ARCADE WORLD |--------------❅\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                          HOME                         │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                       1. Log In                       │\n";
    cout << "\t│                       2. Sign Up                      │\n";
    cout << "\t│                       0. Exit                         │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t\t\t  What's your choice ? ";
}

void User_Profile::set_is_accessed(bool b){
    this->is_accessed = b;
}
bool User_Profile::get_is_accessed(){
    return this->is_accessed;
}

void User_Profile::set_id_password(){
    string id, password;

    cout << "\t\t\t\tID: ";
    //getline(cin,id);
    cin >> id;
    transform(id.begin(), id.end(), id.begin(), ::tolower);         // convert to lower case
    this->set_user_id(id);

    cout << "\t\t\t\tPassword: ";
    //getline(cin,password);
    cin >> password;
    transform(password.begin(), password.end(), password.begin(), ::tolower);
    this->set_user_password(password);
}

bool User_Profile::user_login(){
    system("clear");

    this->show_logo();
    cout << "\n\t❅--------------| WELCOME TO ARCADE WORLD |--------------❅\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                        Log In                         │\n";
    cout << "\t•-------------------------------------------------------•\n";

    this->set_id_password();
    bool valid_login;

    if(this->get_user_id().length()>0 && this->get_user_password().length()>0){
        valid_login = this->user_validation(this->get_user_id(),this->get_user_password(),"user_data.txt");
        if(!valid_login){
            //system("clear");
            //cout << "Wrong Id / Password\n";
            this->user_login();
        }
    }else{
        //system("clear");
        cout << "Id / Password empty\n";
        this->user_login();
    }
    return true;
}

bool User_Profile::user_signup(){
    this->set_id_password();

    if(this->get_user_id().length()>0 && this->get_user_password().length()>0){
        this->save_to_file(this->get_user_id(),this->get_user_password(),"user_data.txt");
        //cout << "Signed Up Successfully !";
        return true;
    }
    return false;
}

void User_Profile::save_to_file(string id, string passwd, string file_name){
    string id_passwd = id + "," + passwd + "\n";

    ofstream file;
    file.open(file_name, ofstream::app);
    file << id_passwd;
}

bool User_Profile::user_validation(string id, string passwd, string file_name){
    string line;
    string id_passwd = id + "," + passwd;       // insert ',' into string to match with line in file
    ifstream read_file(file_name);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (read_file, line)) {
        if(id_passwd.compare(line)==0){
            return true;
        }
    }
    return false;
}

void User_Profile::show_logo(){
    cout<<"\t  _______  _______  _______  _______  ______   _______     \n";
    cout<<"\t (  ___  )(  ____ )(  ____ \\(  ___  )(  __  \\ (  ____ \\    \n";
    cout<<"\t | (   ) || (    )|| (    \\/| (   ) || (  \\  )| (    \\/    \n";
    cout<<"\t | (___) || (____)|| |      | (___) || |   ) || (__        \n";
    cout<<"\t |  ___  ||     __)| |      |  ___  || |   | ||  __)       \n";
    cout<<"\t | (   ) || (\\ (   | |      | (   ) || |   ) || (          \n";
    cout<<"\t | )   ( || ) \\ \\__| (____/\\| )   ( || (__/  )| (____/\\    \n";
    cout<<"\t |/     \\||/   \\__/(_______/|/     \\|(______/ (_______/    \n";
}
