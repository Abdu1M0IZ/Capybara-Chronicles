#include "run_game.hpp"
#include "Levels/lvl1.hpp"
#include "Levels/lvl2.hpp"
#include "Levels/lvl3.hpp"
#include "Levels/lvl4.hpp"
#include "Levels/lvl5.hpp"
#include "Levels/lvl6.hpp"
#include "Levels/lvl7.hpp"
#include "Levels/lvl8.hpp"
#include "Levels/lvl9.hpp"
#include "Levels/lvl10.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void runGame(GameState &state)
{
    bool running = true;
    while (running)
    {
        switch (state.levelNumber)
        {
        case 1:
            lvl1(state);
            break;
        case 2:
            lvl2(state);
            break;
        case 3:
            lvl3(state);
            break;
        case 4:
            lvl4(state);
            break;
        case 5:
            lvl5(state);
            break;
        case 6:
            lvl6(state);
            break;
        case 7:
            lvl7(state);
            break;
        case 8:
            lvl8(state);
            break;
        case 9:
            lvl9(state);
            break;
        case 10:
            lvl10(state);
            break;
        default:
            running = false;
            break;
        }

        if (state.levelNumber > 10)
        {
            running = false;
            break;
        }

        if (running)
        {
            const int toDeduct = 10;

            if (state.eatingResources >= toDeduct)
            {
                state.eatingResources -= toDeduct;
            }
            else
            {
                int remainder = toDeduct - state.eatingResources;
                state.eatingResources = 0;
                state.health -= remainder;
            }

            if (state.health < 100 && state.eatingResources > 0)
            {
                int healthLeft = 100 - state.health;

                if (state.eatingResources >= healthLeft)
                {
                    state.eatingResources -= healthLeft;
                    state.health = 100;
                }
                else
                {
                    state.health += state.eatingResources;
                    state.eatingResources = 0;
                }

            }

            if (state.health <= 0)
            {
                clearScreen();
                cout << "\nYour health has dropped to 0!\n";
                GameOverScreen();
                running = false;
            }
        }

        if (running)
        {
            cout << "\n\nSaving progress:";
            string filename = "saves/" + state.sessionName + ".txt";
            bool ok = saveGame(state, filename);
            if (ok)
                cout << "\n[Saved to " << filename << "]\n";
            else
                cout << "\n[Save failed]\n";
            delay(2);
        }
    }
}
