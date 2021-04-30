#include "state.h"

#include <iostream>
using namespace std;

State::State()              // base class for all other event states ( Menu, About, ... )
{
    this->set_is_finished(false);           // initiate a flag to check whether a current state is still running
    this->set_next_state(-1);
    this->set_is_started(false);
    this->set_is_running(false);
    this->set_is_over(false);

}

void State::set_is_finished(bool b){
    this->is_finished = b;
}
int State::get_is_finished(){
    return this->is_finished;
}

void State::set_next_state(int i){
    this->next_state = i;
}
int State::get_next_state(){
    return this->next_state;
}

void State::set_is_started(bool b){
    this->is_started = b;
}
bool State::get_is_started(){
    return this->is_started;
}

void State::set_is_running(bool b){
    this->is_running = b;
}
bool State::get_is_running(){
    return this->is_running;
}

void State::set_is_over(bool b){
    this->is_over = b;
}
bool State::get_is_over(){
    return this->is_over;
}


void State::update(){}

void State::display(){}

