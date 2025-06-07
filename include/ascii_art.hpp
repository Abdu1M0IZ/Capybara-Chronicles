#ifndef ASCII_ART_HPP
#define ASCII_ART_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include "game_state.hpp"

extern std::string levels[10];
extern std::string levelTexts[10];
extern std::string spinningWheel[3];
extern std::string cards[4];
extern std::string rps[3];
extern std::string balance[5];
extern std::string quickReflexesButton;
extern std::string loadingFrames[3];
extern std::string ground;
extern std::string capyFrames[5];

void displayStatus(GameState &state);

void printLevelArt(int levelNumber);

void printMinigameName(int minigameNumber);

int walkingCapybaraAnimation(int durationInMs);

void printCoverPage(void);

void printLoadingScreen(void);

void printGameStart(void);

void clearScreen(void);

void delay(int seconds);

void printLevelTexts(int levelNumber);

void printSpinningWheel(void);

void printCards(int number);

void printRPS(int number);

void gameScreen(int level);

void printBalance(int number);

void GameOverScreen(void);

void DisplayEndings(int number);

#endif
