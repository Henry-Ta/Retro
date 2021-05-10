#ifndef SORT_MANAGER_H
#define SORT_MANAGER_H

#include "state.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "binary_insertion_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"

class Sort_Manager : public State, public Bubble_Sort, public Selection_Sort,
        public Insertion_Sort, public Binary_Insertion_Sort, public Quick_Sort,
        public Shell_Sort
{
private:
    Bubble_Sort bubble_sort;
    Selection_Sort selection_sort;
    Insertion_Sort insertion_sort;
    Binary_Insertion_Sort binary_insertion_sort;
    Quick_Sort quick_sort;
    Shell_Sort shell_sort;

public:
    Sort_Manager();

    void update();
    void display();

    void load();
    void play();

    void get_replay_exit();

    void run_game_body();

    void run_sort(int i);

    //void get_user_selection();

};

#endif // SORT_MANAGER_H
