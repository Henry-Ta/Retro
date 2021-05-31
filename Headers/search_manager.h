#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

#include "state.h"
#include "linear_search.h"
#include "binary_search.h"
#include "binary_insertion_sort.h"          // to sort array before search binary, can use any kind of sorts
#include "jump_search.h"
#include "fibonacci_search.h"
#include "exponential_search.h"

class Search_Manager : public State, public Linear_Search, public Binary_Search, 
public Binary_Insertion_Sort, public Jump_Search, public Fibonacci_Search, public Exponential_Search
{
private:
    Linear_Search linear_search;
    Binary_Search binary_search;
    Binary_Insertion_Sort binary_insertion_sort;
    Jump_Search jump_search;
    Fibonacci_Search fibonacci_search;
    Exponential_Search exponential_search;
    
public:
    Search_Manager();

    void update();
    void display();

    void load();
    void play();

    void get_replay_exit();

    void run_game_body();

    void run_search(int i);
};

#endif // SEARCH_MANAGER_H
