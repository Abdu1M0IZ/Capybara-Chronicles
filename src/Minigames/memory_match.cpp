#include "Minigames/memory_match.hpp"
#include "ascii_art.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool memoryMatch(void)
{
    char answer;
    int card;

    srand(time(0));
    card = (rand() % 2) + 1; 
    
    printCards(card);

    cout << "\nWhat card was it: ";

    cin >> answer;

    if (((card == 1) && (answer == '9')) || ((card == 2) && (answer == 'S')) || ((card == 3) && (answer == 'P')))
    {
        return true;
    }
    else
    {
        return false;
    }
}
