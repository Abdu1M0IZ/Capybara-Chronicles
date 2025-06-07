#include "Levels/lvl8.hpp"
#include "Minigames/spin_the_wheel.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void lvl8(GameState &state)
{
    int choice, outcome;
    bool flag = false;

    gameScreen(8);

    displayStatus(state);

    cout << "\nThe CapyBara's fate will be determined by the spinning wheel..";
    cout.flush();

    delay(5);

    printSpinningWheel();
    clearScreen();
    printMinigameName(1);
    cout << spinningWheel[2] << endl;

    outcome = spinTheWheel();
    if (outcome == 2)
    {
        state.otherResources += 55;
        cout << "\n\nCapy neutralizes crystal safely, big reward!\n";
    }
    else if (outcome == 1)
    {
        state.health -= 7;
        cout << "\n\nMinor damage.\n";
    }
    else
    {
        state.health -= 15;
        cout << "\n\nCave collapse! -20 health.\n";
    }

    delay(2);

    cout << "\n\nYou have completed Level 8!";

    delay(2);

    state.levelNumber = 9;
}