#ifndef USER_PROFILE_H
#define USER_PROFILE_H

#include <string>			//	Need both libs
using namespace std;		//	to declare string type

class User_Profile
{
private:
    bool user_validation(string id, string passwd, string file_name);

protected:
    int     user_selection;
    string 	user_id;
    string 	user_password;
    int 	user_score;
    bool    is_accessed;

public:
    User_Profile();

    void set_user_selection(int i);
    int get_user_selection();

    void set_user_id(string s);
    string get_user_id();

    void set_user_password(string s);
    string get_user_password();

    void set_user_score(int i);
    int get_user_score();

    void show_login_signup();

    void set_is_accessed(bool b);
    bool get_is_accessed();

    void set_id_password();

    bool user_login();
    bool user_signup();

    void save_to_file(string id, string passwd, string file_name);
};

#endif // USER_PROFILE_H
