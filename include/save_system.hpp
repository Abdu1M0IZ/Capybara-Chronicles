#ifndef SAVE_SYSTEM_HPP
#define SAVE_SYSTEM_HPP

#include "game_state.hpp"
using namespace std;

// Save the current GameState to a file
bool saveGame(const GameState &state, const string &filename);

// Load from a file
bool loadGame(GameState &state, const string &filename);

#endif
