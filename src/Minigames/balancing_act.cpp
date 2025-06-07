#include "Minigames/balancing_act.hpp"
#include "ascii_art.hpp"
#include <iostream>
using namespace std;

bool balancingAct()
{
    char c;

    clearScreen();
    printMinigameName(5);
    cout << balance[0] << endl;

    cout << "\nEnter 'b' to maintain balance: ";

    cin >> c;
    if (c == 'b')
    {
        printBalance(0);
        cout << endl
             << "\nYou balanced!\n";
        return true;
    }
    else
    {
        printBalance(4);
        cout << endl
             << "\nYou fell!\n";
        return false;
    }
}
