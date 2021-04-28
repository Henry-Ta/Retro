#include "state.h"


State::State()              // base class for all other event states ( Menu, About, ... )
{
    this->set_is_finished(false);           // initiate a flag to check whether a current state is still running
    this->set_next_state(-1);

    /*
     this->set_user_selection(-1);
    this->set_current_state(-1);
    this->set_is_selected(false);
    */
}

void State::set_is_finished(bool s){
    this->is_finished = s;
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

void State::update(){}

void State::display(){}
/*
void State::set_user_selection(int i){
    this->user_selection = i;
}
int State::get_user_selection(){
    return this->user_selection;
}

void State::set_current_state(string s){
    this->current_state = s;
}
string State::get_current_state(){
    return this->current_state;
}

void State::set_is_selected(bool s){
    this->is_selected = s;
}
bool State::get_is_selected(){
    return this->is_selected;
}*/
