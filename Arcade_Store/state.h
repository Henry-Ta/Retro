#ifndef STATE_H
#define STATE_H

#include <string>
using namespace std;

class State
{
protected:
    bool    is_finished     ;
    int     next_state      ;
    int     user_selection  ;

    //string current_state  ;
    //bool    is_selected   ;

public:
    State();

    void set_is_finished(bool s);
    int get_is_finished();

    void set_next_state(int i);
    int get_next_state();

    void set_user_selection(int i);
    int get_user_selection();

    /*
    void set_current_state(string s);
    string get_current_state();

    void set_is_selected(bool s);
    bool get_is_selected();
    */

    void initiate(){}

    void update(){}

    void display(){}
};

#endif // STATE_H
