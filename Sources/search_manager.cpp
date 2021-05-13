#include "../Headers/search_manager.h"

#include <iostream>
#include <algorithm>        // random_shuffle(array, array + array_size)
using namespace std;

Search_Manager::Search_Manager():State()
{

}

void Search_Manager::update(){

    this->display();

    this->load();           // Turn on flag Ask user to confirm to start playing

    this->play();
}

void Search_Manager::load(){

    this->set_is_started(true);
    this->set_is_running(true);
}

void Search_Manager::play(){
    if(this->get_is_started()){         // MAIN PART to RUN GAME
        this->run_game_body();

        if(!this->get_is_running()){            // when game finished, move to replay_exit event
            this->get_replay_exit();
        }
    }
}

void Search_Manager::get_replay_exit(){
    int game_replay;
    cout << "\t\tDo you want to replay or exit ? (Replay-1|Exit-0) ";
    cin >> game_replay;
    if(game_replay==1 || game_replay==0){
        if(game_replay==0){             // exit game
            this->set_next_state(8);        // exit to main menu
            this->set_is_finished(true);
        }else{                          // replay
            this->set_next_state(3);        // renew current game state by
            this->set_is_finished(true);    // pointing to the new state but same game (state) id
        }
    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->get_replay_exit();
    }
}

void Search_Manager::run_game_body(){
    int user_choice;
    cout << "\n\t\t\t     1. Linear Search";
    cout << "\n\t\t\t     2. Binary Search";
    cout << "\n\n\t\t\t     Enter your choice: ";
    cin >> user_choice;

    if(user_choice == 1 || user_choice == 2){
        this->run_search(user_choice);

        //---------------------------------------GAME FINISHED
        this->set_is_running(false);        // When game is finished, turn on flag to move to replay_exit event
    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        this->run_game_body();
    }

}

void Search_Manager::run_search(int i){
    int numbers_of_elements,search_node;

    cout << "\n\t\tHow many elements in array to sort (2-14)? ";
    cin >> numbers_of_elements;

    int array[numbers_of_elements];         // to create a random array
    for (int i=0; i < numbers_of_elements;i++)
        array[i] = i+1;                         // array starts from 0, but can't display 0 in visualization so +1 for value

    random_shuffle(array, array + numbers_of_elements);     // to organize elements randomly

    if(numbers_of_elements>=2 && numbers_of_elements<=14){
        cout<<"\n\t\t\t";
        for (int i=0; i < numbers_of_elements;i++)          // to display random array
            cout<<array[i]<<" ";

        cout << "\n\n\t\tWhich number are you looking for? ";
        cin >> search_node;

        int original_array[numbers_of_elements];                    // make a copy of original array
        copy( array, array+numbers_of_elements, original_array );   // to display in case 5 (quick sort)

        switch(i){
            case 1:
                linear_search.run_search(array, numbers_of_elements,search_node);
                break;
            case 2:
                binary_insertion_sort.run_sort(array, numbers_of_elements);     // need to sort elements in order before searching binary
                binary_search.run_search(array,original_array, numbers_of_elements,search_node, 0 , numbers_of_elements-1);
                break;
        }

    }else{
        cout << "\n☠ Wrong input, please try again ☠\n\n";
        switch(i){
        case 1:
            this->run_search(1);
            break;
        case 2:
            this->run_search(2);
            break;

        }
    }
}

void Search_Manager::display(){
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│                  SEARCHING VISUALIZER                 │\n";
    cout << "\t•-------------------------------------------------------•\n";
    cout << "\t│       8. Menu         9. About           0. Exit      │\n";
    cout << "\t•-------------------------------------------------------•\n";
}
