#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "game.h"
#include <ctime>

using std::vector;
using std::string;

using namespace std;

int main()
{
    char player_choice;


    cout << "Press 's' to start the game or 'q' to quit: ";
    cin >> player_choice;
    cout << " " << endl;
    cout << " " << endl;

    if (player_choice=='s'){
        game game_object;
        game_object.play();

    }else if(player_choice=='q'){
        exit;

    }else{
        cout << "Invalid input" << endl;

    }


    return 0;
}
