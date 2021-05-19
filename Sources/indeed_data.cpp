#include "../Headers/indeed_data.h"

#include <iostream>
using namespace std;

Indeed_Data::Indeed_Data()
{
    
}

void Indeed_Data::set_title(string s){
    this->title = s;
}
string Indeed_Data::get_title(){
    return this->title;
}

void Indeed_Data::set_company(string s){
    this->company = s;
}
string Indeed_Data::get_company(){
    return this->company;
}

void Indeed_Data::set_location(string s){
    this->location = s;
}
string Indeed_Data::get_location(){
    return this->location;
}

void Indeed_Data::set_salary(string s){
    this->salary = s;
}
string Indeed_Data::get_salary(){
    return this->salary;
}

void Indeed_Data::set_date(string s){
    this->date = s;
}
string Indeed_Data::get_date(){
    return this->date;
}

void Indeed_Data::set_rating(string s){
    this->rating = s;
}
string Indeed_Data::get_rating(){
    return this->rating;
}

void Indeed_Data::set_difficulty(string s){
    this->difficulty = s;
}
string Indeed_Data::get_difficulty(){
    return this->difficulty;
}

void Indeed_Data::set_remote(string s){
    this->remote = s;
}
string Indeed_Data::get_remote(){
    return this->remote;
}

