#include "Levels/lvl10.hpp"
#include "Minigames/quick_reflexes.hpp"
#include "Minigames/balancing_act.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void lvl10(GameState &state)
{
    gameScreen(10);

    displayStatus(state);

    cout << "The Capybara's destiny is now in your hands! Win the games and maintain over 50 health to survive.";
    cout.flush();

    delay(7);

    clearScreen();

    int reflex = quickReflexes();

    delay(5);

    clearScreen();

    bool balance = balancingAct();

    delay(5);

    if (reflex == 2 && balance == true && state.health >= 50)
    {
        delay(3);
        DisplayEndings(1);
    }
    else if ((reflex == 2 || balance == true) && (state.health >= 50))
    {
        delay(3);
        DisplayEndings(2);
    }
    else
    {
        delay(3);
        DisplayEndings(3);
    }

    delay(10);
    state.levelNumber = 11;
}
