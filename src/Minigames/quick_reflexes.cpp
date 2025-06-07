#include "Minigames/quick_reflexes.hpp"
#include "ascii_art.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <limits>
using namespace std;

int quickReflexes()
{
    string user_reflex;
    double secs;

    clearScreen();
    printMinigameName(4);
    cout << quickReflexesButton << endl;

    cout << "\nPress ENTER quickly when prompted!\n";
    cout << "Get ready...\n";
    this_thread::sleep_for(std::chrono::seconds(3));

    cout << "NOW! Press ENTER!\n";
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto start = chrono::high_resolution_clock::now();

    getline(cin, user_reflex);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    secs = elapsed.count();
    cout << "\nYour reflex: " << secs << " s\n";

    if (secs < 0.3)
    {
        return 2;
    }
    else if (secs < 0.7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
