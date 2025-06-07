#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <string>

struct GameState {
    int levelNumber = 1;         
    int health = 100;         
    int eatingResources = 20;  
    int otherResources = 30; 
    std::string sessionName = "default";
};

#endif
