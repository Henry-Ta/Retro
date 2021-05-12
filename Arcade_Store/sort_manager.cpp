#include "sort_manager.h"

#include <iostream>
#include <algorithm>        // random_shuffle(array, array + array_size)
using namespace std;

Sort_Manager::Sort_Manager():State()
{

}

void Sort_Manager::update(){

    this->display();

    this->load();           // Turn on flag Ask user to confirm to start playing

    this->play();
}

void Sort_Manager::load(){

    this->set_is_started(true);
    this->set_is_running(true);
}

void Sort_Manager::play(){
    if(this->get_is_started()){         // MAIN PART to RUN GAME
        this->run_game_body();

        if(!this->get_is_running()){            // when game finished, move to replay_exit event
            this->get_replay_exit();
        }
    }
}

void Sort_Manager::get_replay_exit(){
    int game_replay;
    cout << "\t\tDo you want to replay or exit ? (Replay-1|Exit-0) ";
    cin >> game_replay;
    if(game_replay==1 || game_replay==0){
        if(game_replay==0){             // exit game
            this->set_next_state(8);        // exit to main menu
            this->set_is_finished(true);
        }else{                          // replay
            this->set_next_state(2);        // renew current game state by
            this->set_is_finished(true);    // pointing to the new state but same game (state) id
        }
    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->get_replay_exit();
    }
}

void Sort_Manager::run_game_body(){
    int user_choice;
    cout << "\n\t\t\t     1. Bubble Sort";
    cout << "\n\t\t\t     2. Selection Sort";
    cout << "\n\t\t\t     3. Insertion Sort";
    cout << "\n\t\t\t     4. Binary Insertion Sort";
    cout << "\n\t\t\t     5. Quick Sort";
    cout << "\n\t\t\t     6. Shell Sort";
    cout << "\n\t\t\t     7. Merge Sort";
    cout << "\n\t\t\t     8. Heap Sort";
    cout << "\n\n\t\t\t     Enter your choice: ";
    cin >> user_choice;

    if(user_choice == 1 || user_choice == 2 || user_choice == 3 || user_choice == 4 ||
            user_choice == 5 || user_choice == 6 || user_choice == 7 || user_choice == 8){
        this->run_sort(user_choice);

        //---------------------------------------GAME FINISHED
        this->set_is_running(false);        // When game is finished, turn on flag to move to replay_exit event
    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->run_game_body();
    }

}

void Sort_Manager::run_sort(int i){
    int numbers_of_elements;
    cout << "\n\t\tHow many elements in array to sort (2-14)? ";
    cin >> numbers_of_elements;
    if(numbers_of_elements>=2 && numbers_of_elements<=14){

        int array[numbers_of_elements];
        for (int i=0; i < numbers_of_elements;i++)
        {
            array[i] = i+1;                         // array starts from 0, but can't display 0 in visualization so +1 for value
        }

        random_shuffle(array, array + numbers_of_elements);     // organize elements randomly

        int original_array[numbers_of_elements];                    // make a copy of original array
        copy( array, array+numbers_of_elements, original_array );   // to display in case 5 (quick sort)

        switch(i){
            case 1:
                bubble_sort.run_sort(array, numbers_of_elements);
                break;
            case 2:
                selection_sort.run_sort(array, numbers_of_elements);
                break;
            case 3:
                insertion_sort.run_sort(array, numbers_of_elements);
                break;
            case 4:
                binary_insertion_sort.run_sort(array, numbers_of_elements);
                break;
            case 5:
                quick_sort.run_sort(array, original_array, numbers_of_elements, 0, numbers_of_elements-1);
                break;
            case 6:
                shell_sort.run_sort(array, numbers_of_elements);
                break;
            case 7:
                merge_sort.run_sort(array, 0, numbers_of_elements-1, numbers_of_elements, original_array);
                break;
            case 8:
                heap_sort.run_sort(array, numbers_of_elements, original_array, numbers_of_elements);
                break;
        }

    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        switch(i){
        case 1:
            this->run_sort(1);
            break;
        case 2:
            this->run_sort(2);
            break;
        case 3:
            this->run_sort(3);
            break;
        case 4:
            this->run_sort(4);
            break;
        case 5:
            this->run_sort(5);
            break;
        case 6:
            this->run_sort(6);
            break;
        case 7:
            this->run_sort(7);
            break;
        case 8:
            this->run_sort(8);
            break;
        }
    }
}

void Sort_Manager::display(){
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                   SORTING VISUALISER                  │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       8. Menu         9. About           0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}

/*
 void Sort_Manager::get_user_selection(){
    int i;
    cout << "\n\t\t\tWhich number do you choose? ";
    cin >> i;

    if(i==6 || i==7 || i==8 || i==9){			// if selection is match with any options in list
        this->set_next_state(i);
        this->set_is_finished(true);
    }else if(i==0){
        exit(0);
    }else{						// not match any option
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->get_user_selection();
    }
}
*/
