#include "Levels/lvl7.hpp"
#include "Minigames/memory_match.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void lvl7(GameState &state)
{
    int choice;
    bool flag = false, result;

    gameScreen(7);

    displayStatus(state);

    cout << endl
         << "Capy has to either:\n"
         << "1. Build a fire beacon near the beach.\n"
         << "2. Use reflective materials on the volcano summit.\n"
         << "Your Choice: ";
    do
    {
        cin >> choice;
        if (choice == 1)
        {
            if (state.otherResources < 15)
            {
                state.health -= 10;
                cout << "\nInsufficient materials! Capy suffers from fire hazards.\n";
            }
            else
            {
                state.otherResources -= 15;
                state.health -= 5;
                cout << "\nCapy successfully builds the fire beacon! While loosing health due to traveling.\n";
            }
            flag = true;
        }
        else if (choice == 2)
        {
            if (state.otherResources < 20)
            {
                state.health -= 15;
                cout << "\nInsufficient materials! Capy suffers from tremors.\n";
            }
            else
            {
                state.otherResources -= 20;
                cout << "\nCapy successfully builds the fire beacon! While loosing health due to traveling.\n";
            }
            flag = true;
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
        cout << "You matched successfully! A strong signal was created.\n";
    }
    else
    {
        state.otherResources = (state.otherResources < 5) ? 0 : (state.otherResources - 5);
        cout << "Unsuccessful! Signal fails, wasting resources.\n";
    }

    delay(2);

    cout << "\n\nYou have completed Level 7!";

    delay(2);

    state.levelNumber = 8;
}
