#include "Levels/lvl2.hpp"
#include "Minigames/memory_match.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void lvl2(GameState &state)
{
    int choice;
    bool flag = false, result;

    gameScreen(2);

    displayStatus(state);

    cout << endl
         << "Capy has to either:\n"
         << "1. Test plants cautiously using clues.\n"
         << "2. Eat a plant immediately to satisfy hunger.\n"
         << "3. Ignore plants and drink water.\n"
         << "Your Choice: ";
    do
    {
        cin >> choice;
        if (choice == 1)
        {
            state.health -= 5;
            state.eatingResources += 20;
            cout << "\nCapy discovers Food and Water Resources, but has loses some Health.\n";
            flag = true;
        }
        else if (choice == 2)
        {
            state.health -= 25;
            cout << "\nYikes! The plant was poisonous.\n";
            flag = true;
        }
        else if (choice == 3)
        {
            state.health -= 10;
            cout << "\nYikes! The water was dirty.\n";
            flag = true;
        }
        else
            cout << "Invalid Entry! Enter Again:";
    } while (flag == false);

    displayStatus(state);

    delay(3);

    result = memoryMatch();

    if (result)
    {
        state.eatingResources += 10;
        cout << "You matched successfully! Capy found Food and Water Resources.\n";
    }
    else
    {
        state.health -= 5;
        cout << "Mistakes costs Capy Health!\n";
    }

    delay(2);

    cout << "\n\nYou have completed Level 2!";

    delay(2);

    state.levelNumber = 3;
}
