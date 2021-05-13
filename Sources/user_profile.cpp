#include "../Headers/user_profile.h"


User_Profile::User_Profile()
{
    this->set_is_accessed(false);
    int choice;
    this->show_login_signup();
    cin >> choice;          // only accept number with int, error with characters
    this->set_user_selection(choice);

    switch(choice){
    case 1:
        this->set_is_accessed(this->user_login());          // Log in
        break;
    case 2:
        this->set_is_accessed(this->user_signup());         // Sign up
        break;
    case 0:
        exit(0);

    default:
        system("clear");
        cout << "Input-> Wrong";
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

    cout << "\n\t❅--------------| WELCOME TO RETRO WORLD |--------------❅\n";
    cout << "\t•------------------------------------------------------•\n";
    cout << "\t│                          HOME                        │\n";
    cout << "\t•------------------------------------------------------•\n";
    cout << "\t│                       1. Log In                      │\n";
    cout << "\t│                       2. Sign Up                     │\n";
    cout << "\t│                       0. Exit                        │\n";
    cout << "\t•------------------------------------------------------•\n";
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
    cout << "\n\t❅--------------| WELCOME TO RETRO WORLD |--------------❅\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                        LOG IN                         │\n";
    cout << "\t•-------------------------------------------------------•\n";

    this->set_id_password();
    bool valid_login=false;

    if(this->get_user_id().length()>0 && this->get_user_password().length()>0){     // id, pass not empty
        valid_login = this->user_validation(this->get_user_id(),this->get_user_password(),"./Data/User_Data.csv");     // return true/false after checking id,pass with data in "user_data.txt"
        if(!valid_login){           // failed validation
            //system("clear");
            cout << "Wrong Id / Password";
            this->user_login();         // keep looping until login correct
        }
    }else{ 				// id,pass empty ( Uses cin to get id,pass so get rid of empty character)
        //system("clear");
        cout << "Id / Password empty";
        this->user_login();
    }
    return true;


    //return valid_login;
}

bool User_Profile::user_signup(){
    system("clear");

    this->show_logo();
    cout << "\n\t❅--------------| WELCOME TO RETRO WORLD |--------------❅\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                        SIGN UP                        │\n";
    cout << "\t•-------------------------------------------------------•\n";

    this->set_id_password();

    if(this->get_user_id().length()>0 && this->get_user_password().length()>0){			// if,pass not empty
        this->save_to_file(this->get_user_id(),this->get_user_password(),"./Data/User_Data.csv");		// Save to file "user_data.txt"
        cout << "Signed Up Successfully !";
    }else{ 				// id,pass empty
        //system("clear");
        cout << "Id / Password empty";
        this->user_signup();                // keep looping until sign up correct
    }
    return true;
}

void User_Profile::save_to_file(string id, string passwd, string file_name){
    string id_passwd = id + "," + passwd + "\n";		// uses ',' to seperate data

    ofstream file;			// open file, if not exist create a new file
    file.open(file_name, ofstream::app);		// open file and point to the last line ( to insert new data later on )
    file << id_passwd;
}

bool User_Profile::user_validation(string id, string passwd, string file_name){
    string line;
    string id_passwd = id + "," + passwd;       // insert ',' into string to match with line in file
    ifstream read_file(file_name);

    while (getline (read_file, line)) {	// Use a while loop together with the getline() function to read the file line by line
        if(id_passwd.compare(line)==0){	// if match any line
            return true;
        }
    }
    return false;
}

void User_Profile::show_logo(){
    /*
    cout<<"\n\t  _______  _______  _______  _______  ______   _______     \n";
    cout<<"\t (  ___  )(  ____ )(  ____ \\(  ___  )(  __  \\ (  ____ \\    \n";
    cout<<"\t | (   ) || (    )|| (    \\/| (   ) || (  \\  )| (    \\/    \n";
    cout<<"\t | (___) || (____)|| |      | (___) || |   ) || (__        \n";
    cout<<"\t |  ___  ||     __)| |      |  ___  || |   | ||  __)       \n";
    cout<<"\t | (   ) || (\\ (   | |      | (   ) || |   ) || (          \n";
    cout<<"\t | )   ( || ) \\ \\__| (____/\\| )   ( || (__/  )| (____/\\    \n";
    cout<<"\t |/     \\||/   \\__/(_______/|/     \\|(______/ (_______/    \n";
    */


    cout<<"\n\t       _______  _______ _________ _______  _______\n"; 
    cout<<"\t      (  ____ )(  ____ \\\\__   __/(  ____ )(  ___  )\n"; 
    cout<<"\t      | (    )|| (    \\/   ) (   | (    )|| (   ) |\n"; 
    cout<<"\t      | (____)|| (__       | |   | (____)|| |   | |\n"; 
    cout<<"\t      |     __)|  __)      | |   |     __)| |   | |\n"; 
    cout<<"\t      | (\\ (   | (         | |   | (\\ (   | |   | |\n"; 
    cout<<"\t      | ) \\ \\__| (____/\\   | |   | ) \\ \\__| (___) |\n"; 
    cout<<"\t      |/   \\__/(_______/   )_(   |/   \\__/(_______)\n"; 

}
