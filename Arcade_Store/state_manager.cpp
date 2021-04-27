#include "state_manager.h"
#include "user_profile.h"

#include <iostream>
#include <string>
using namespace std;

State_Manager::State_Manager():User_Profile()
{

}

void State_Manager::run(){
    cout << "ID: " << User_Profile::get_user_id() + "\n";
    cout << "Password: " << User_Profile::get_user_password() + "\n";
}
