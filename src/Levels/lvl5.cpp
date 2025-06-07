#include "Levels/lvl5.hpp"
#include "Minigames/quick_reflexes.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void lvl5(GameState &state)
{
    int choice, reflexScore;
    bool flag = false;

    gameScreen(5);

    displayStatus(state);

    cout << endl
         << "Capy has to either:\n"
         << "1. Set a trap using available materials.\n"
         << "2. Attempt to scare the boar away.\n"
         << "3. Avoid the area entirely.\n"
         << "Your Choice: ";
    do
    {
        cin >> choice;
        if (choice == 1)
        {
            if (state.otherResources < 5)
            {
                state.health -= 10;
                cout << "\nInsufficient Materials! Capy suffers from Boar attacks!\n";
            }
            else
            {
                state.otherResources -= 5;
                cout << "\nCapy Successfully traps the Boar!\n";
            }
            flag = true;
        }
        else if (choice == 2)
        {
            state.health -= 5;
            cout << "\nCapy scares the Boar away, but has lost some Health!\n";
            flag = true;
        }
        else if (choice == 3)
        {
            state.health -= 10;
            cout << "\nCapy runs away and gets exhausted!.\n";
            flag = true;
        }
        else
            cout << "Invalid Entry! Enter Again:";
    } while (flag == false);

    displayStatus(state);

    delay(3);

    reflexScore = quickReflexes();
    if (reflexScore == 2)
    {
        state.eatingResources += 10;
        cout << "Perfect Dodge! Capy finds Food and Water Resources.\n";
    }
    else if (reflexScore == 1)
    {
        state.health -= 3;
        state.eatingResources += 5;
        cout << "Minor injury, but Capy gains Food and Water Resources.\n";
    }
    else
    {
        state.health -= 10;
        cout << "Poor Score! Capy loses Health and finds no Resources.\n";
    }

    delay(2);

    cout << "\n\nYou have completed Level 5!";

    delay(2);

    state.levelNumber = 6;
}
