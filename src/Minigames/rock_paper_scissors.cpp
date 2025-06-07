#include "Minigames/rock_paper_scissors.hpp"
#include "ascii_art.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rockPaperScissors()
{
    char move;
    bool flag = false;
    int ai, aiMove;

    printMinigameName(3);

    cout << "\nRock Paper Scissor: Enter your move (r/p/s): ";

    do
    {
        cin >> move;
        if ((move == 'r') || (move == 'p') || (move == 's'))
            flag = true;
        else
            cout << "Invalid Input! Enter Again: ";
    } while (flag == false);


    srand(time(nullptr));
    ai = rand() % 3; // 0=r,1=p,2=s
    aiMove = (ai == 0 ? 'r' : (ai == 1 ? 'p' : 's'));
    printRPS(ai);

    // Compare
    if (move == aiMove)
    {
        cout << "\nIt's a tie!\n";
        return 0;
    }
    if ((move == 'r' && aiMove == 's') ||
        (move == 'p' && aiMove == 'r') ||
        (move == 's' && aiMove == 'p'))
    {
        cout << "\nYou win!\n";
        return 1;
    }
    else
    {
        cout << "\nYou lose!\n";
        return -1;
    }
}
