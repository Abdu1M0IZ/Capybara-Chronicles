#include "save_system.hpp"
#include <fstream>
#include <iostream>
using namespace std;

bool saveGame(const GameState &state, const string &filename)
{
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "\nError: Cannot open file for saving: " << filename << endl;
        return false;
    }
    // Save each field in a simple text format
    outFile << state.levelNumber << "\n"
            << state.health << "\n"
            << state.eatingResources << "\n"
            << state.otherResources << "\n";
    outFile.close();
    return true;
}

bool loadGame(GameState &state, const string &filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "\nError: Cannot open file for loading: " << filename << endl;
        return false;
    }
    inFile >> state.levelNumber
           >> state.health
           >> state.eatingResources
           >> state.otherResources;
    inFile.close();
    return true;
}
