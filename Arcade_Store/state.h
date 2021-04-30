#ifndef STATE_H
#define STATE_H


class State
{
protected:
    bool    is_finished     ;       // check whether a current state is finished
    int     next_state      ;
    int     user_selection  ;

    bool    is_started      ;       // check whether game is started
    bool    is_running      ;       // check whether game is running
    //bool    is_over         ;     // check wheteher game is over

public:
    State();

    void set_is_finished(bool s);
    int get_is_finished();

    void set_next_state(int i);
    int get_next_state();

    void set_user_selection(int i);
    int get_user_selection();

    void set_is_started(bool b);
    bool get_is_started();

    void set_is_running(bool b);
    bool get_is_running();

    /*
    void set_is_over(bool b);
    bool get_is_over();
    */

    //void initiate();
    void update();
    void display();

};

#endif // STATE_H
