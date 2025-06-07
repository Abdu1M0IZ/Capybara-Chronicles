#include "Minigames/spin_the_wheel.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int spinTheWheel()
{
    srand(time(0));
    int r = rand() % 3;
    if (r == 2)
        cout << "[Spin] High roll!\n";
    else if (r == 1)
        cout << "[Spin] Medium roll.\n";
    else
        cout << "[Spin] Low roll...\n";
    return r;
}
