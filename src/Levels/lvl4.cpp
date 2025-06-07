#include "Levels/lvl4.hpp"
#include "Minigames/spin_the_wheel.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void lvl4(GameState &state)
{
    int choice, outcome;
    bool flag = false;

    gameScreen(4);

    displayStatus(state);

    cout << endl
         << "Capy has to either:\n"
         << "1. Interact with the crystal.\n"
         << "2. Use the cave for shelter.\n"
         << "3. Leave the cave to explore elsewhere.\n"
         << "Your Choice: ";
    do
    {
        cin >> choice;
        if (choice == 1)
        {
            state.health -= 7;
            state.otherResources += 10;
            cout << "\nCapy discovers Other Resources, but loses some Health!\n";
            flag = true;
        }
        else if (choice == 2)
        {
            if (state.otherResources < 5)
            {
                state.health -= 10;
                cout << "\nCapy Stays at the cave but freezes due to cold.\n";
            }
            else
            {
                state.otherResources -= 5;
                cout << "\nCapy Stays at the cave and builds a fire.\n";
            }
            flag = true;
        }
        else if (choice == 3)
        {
            state.health -= 15;
            cout << "\nCapy gets exhausted and exposed!.\n";
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
        state.otherResources += 10;
        cout << "\n\nCapy finds a useful Artifact!" << endl;
    }
    else if (outcome == 1)
    {
        state.eatingResources += 5;
        cout << "\n\nCapy finds Food and Water Resources." << endl;
    }
    else
    {
        state.health -= 5;
        cout << "\n\nCapy encounters a hazard." << endl;
    }

    delay(2);

    cout << "\n\nYou have completed Level 4!";

    delay(2);

    state.levelNumber = 5;
}
