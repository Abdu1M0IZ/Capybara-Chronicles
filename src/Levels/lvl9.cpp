#include "Levels/lvl8.hpp"
#include "Minigames/rock_paper_scissors.hpp"
#include "save_system.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

void lvl9(GameState &state)
{
    int choice, result;
    bool flag = false;

    gameScreen(9);

    displayStatus(state);

    if (state.otherResources >= 50)
    {
        state.otherResources -= 50;
        cout << "\nWin the Rock Paper Scissor Duel to build the Raft.";
        cout.flush();

        delay(3);
        result = rockPaperScissors();
        if (result == 1)
        {
            cout << endl
                 << "Raft Successfully Built!!\n";

            delay(2);

            cout << "\n\nYou have completed Level 9!";

            state.levelNumber = 10;

            delay(2);
        }
        else
        {
            state.health -= 7;
            cout << endl
                 << "Construction Failed! Resources wasted!";

            delay(2);

            cout << "\n\nYou have completed Level 9!";

            state.levelNumber = 10;

            delay(2);
        }
    }
    else if (state.otherResources >= 10)
    {
        state.otherResources -= 10;
        cout << "\nWin the Rock Paper Scissor Duel to Signal for Rescue.";
        cout.flush();

        delay(3);

        clearScreen();

        result = rockPaperScissors();
        if (result == 1)
        {
            state.health -= 7;
            cout << endl
                 << "Signal Transmitted!\n";

            delay(2);

            cout << "\n\nYou have completed Level 9!";

            state.levelNumber = 10;

            delay(2);
        }
        else
        {
            state.health -= 15;
            cout << "Signal Failed! Resources wasted!";

            delay(2);

            cout << "\n\nYou have completed Level 9!";

            state.levelNumber = 10;

            delay(2);
        }
    }
    else
    {
        state.health -= 25;
        cout << "\nWin the Rock Paper Scissor Duel to survice the Storm.";
        cout.flush();

        delay(3);

        clearScreen();

        result = rockPaperScissors();
        if (result == 1)
        {
            cout << "\nYou Survived the Storm!\n";

            delay(2);

            cout << "\n\nYou have completed Level 9!";

            state.levelNumber = 10;

            delay(2);
        }
        else
        {
            state.health -= 100;
            cout << "You did not Survive the Storm!";

            delay(2);
        }
    }
}