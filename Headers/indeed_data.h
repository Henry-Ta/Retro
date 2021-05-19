#ifndef INDEED_DATA_H
#define INDEED_DATA_H

#include "state.h"
#include <string>
using namespace std;

class Indeed_Data
{
protected:
    string title;
    string company;
    string location;
    string salary;
    string date;
    string rating;
    string difficulty;
    string remote;

public:
    Indeed_Data();

    void set_title(string s);
    string get_title();

    void set_company(string s);
    string get_company();

    void set_location(string s);
    string get_location();

    void set_salary(string s);
    string get_salary();

    void set_date(string s);
    string get_date();

    void set_rating(string s);
    string get_rating();

    void set_difficulty(string s);
    string get_difficulty();

    void set_remote(string s);
    string get_remote();

};

#endif // INDEED_DATA_H
