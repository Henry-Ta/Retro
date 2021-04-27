#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "user_profile.h"

class State_Manager : public User_Profile
{
private:

public:
    State_Manager();

    void run();
};

#endif // STATE_MANAGER_H
