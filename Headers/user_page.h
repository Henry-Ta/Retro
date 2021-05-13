#ifndef USER_PAGE_H
#define USER_PAGE_H

#include "state.h"

#include <iostream>

#include <string>

using namespace std;


class User_Page : public State
{
private:
    string id, password;
public:
    User_Page();

    void set_id(string s);
    string get_id();

    void set_password(string s);
    string get_password();

    void update();
    void display(string id, string password);
};

#endif // USER_PAGE_H
