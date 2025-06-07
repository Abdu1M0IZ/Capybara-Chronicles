#include "Levels/lvl1.hpp"
#include "Minigames/spin_the_wheel.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void lvl1(GameState &state)
{
    int choice, outcome;
    bool flag = false;

    gameScreen(1);

    displayStatus(state);

    cout << endl
         << "Capy has to either:\n"
         << "1. Build a Simple Shelter (costs 10 Other Resources).\n"
         << "2. Save Materials for later.\n"
         << "Your Choice: ";
    do
    {
        cin >> choice;
        if (choice == 1)
        {
            cout << "\nShelter Built Successfully!\n";
            state.otherResources -= 10;
            flag = true;
        }
        else if (choice == 2)
        {
            cout << "\nResources Saved, but Capy is stranded!\n";
            state.eatingResources -= 15;
            flag = true;
        }
        else
            cout << "Invalid Entry! Enter Again:";
    } while (flag == false);

    displayStatus(state);

    delay(3);

    printSpinningWheel();
    clearScreen();
    printMinigameName(1);
    cout << spinningWheel[2] << endl;

    outcome = spinTheWheel();
    if (outcome == 2)
    {
        state.eatingResources += 10;
        cout << "\n\nCapy gains extra Food and Water Resources!" << endl;
    }
    else if (outcome == 1)
    {
        state.otherResources += 5;
        cout << "\n\nCapy finds Other Resources!" << endl;
    }
    else
    {
        state.health -= 5;
        cout << "\n\nCapy loses Health!" << endl;
    }

    delay(2);

    cout << "\n\nYou have completed Level 1!";

    delay(2);

    state.levelNumber = 2;
}
