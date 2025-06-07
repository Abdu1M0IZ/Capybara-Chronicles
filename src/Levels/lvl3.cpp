#include "Levels/lvl3.hpp"
#include "Minigames/rock_paper_scissors.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;


void lvl3(GameState &state)
{
    int choice;
    bool flag = false;

    gameScreen(3);

    displayStatus(state);

    cout << endl
         << "Capy has to either:\n"
         << "1. Take a detour to avoid danger.\n"
         << "2. Confront the wildlife.\n"
         << "Your Choice: ";
    do
    {
        cin >> choice;
        if (choice == 1)
        {
            state.health -= 10;
            cout << "\nCapy rushes causing hunger and fatigue!\n";
            flag = true;
        }
        else if (choice == 2)
        {
            state.health -= 7;
            state.eatingResources += 10;
            cout << "\nCapy falls and gets injured!\n";
            flag = true;
        }
        else
            cout << "Invalid Entry! Enter Again:";
    } while (flag == false);

    displayStatus(state);

    delay(3);

    clearScreen();

    int result = rockPaperScissors(); 
    if (result == 1)
    {
        state.otherResources += 5;
        cout << "\nCapy won some shiny objects!\n";
    }
    else if (result == 0)
    {
        cout << "\nTie! No big changes.\n";
    }
    else
    {
        state.eatingResources -= 5;
        if (state.eatingResources < 0)
            state.eatingResources = 0;
        cout << "\nCapy lost some resources...\n";
    }

    delay(2);

    cout << "\n\nYou have completed Level 3!";

    delay(2);

    state.levelNumber = 4;
}