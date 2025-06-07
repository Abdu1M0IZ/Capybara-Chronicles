#include "Levels/lvl6.hpp"
#include "Minigames/balancing_act.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void lvl6(GameState &state)
{
    int choice;
    bool flag = false, success;

    gameScreen(6);

    displayStatus(state);

    cout << endl
         << "Capy has to either:\n"
         << "1. Gather reflective materials for signaling.\n"
         << "2. Rest at the summit to regain health.\n"
         << "3. Descend immediately to avoid further danger.\n"
         << "Your Choice: ";
    do
    {
        cin >> choice;
        if (choice == 1)
        {
            state.otherResources += 10;
            state.health -= 5;
            cout << "\nCapy gathers materials at the expense of some Health.\n";
            flag = true;
        }
        else if (choice == 2)
        {
            state.health -= 5;
            state.eatingResources = state.eatingResources < 5 ? 0 : state.eatingResources - 5;
            cout << "\nCapy suffers from tremors and uses Food and Water Resources.\n";
            flag = true;
        }
        else if (choice == 3)
        {
            state.health -= 10;
            cout << "\nCapy falls!\n";
            flag = true;
        }
        else
            cout << "Invalid Entry! Enter Again:";
    } while (flag == false);

    displayStatus(state);

    delay(3);

    success = balancingAct();
    if (!success)
    {
        state.health -= 5;
        cout << "Capy loses Health from falls!\n";
    }
    else
    {
        state.health += 10;
        cout << "Capy gains Health as he summit!\n";
    }

    delay(2);

    cout << "\n\nYou have completed Level 6!";

    delay(2);

    state.levelNumber = 7;
}
