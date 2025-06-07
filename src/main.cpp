#include <iostream>
#include <string>
#include <filesystem>
#include "game_state.hpp"
#include "save_system.hpp"
#include "run_game.hpp"
#include "ascii_art.hpp"
#include <limits>
#include <string>
using namespace std;
namespace fs = std::filesystem;

int main()
{
    int fileCount = 0, index;
    bool flag = false, ok;
    string choice, user_input;

    printCoverPage();

    fs::path saveDir{"saves"};

    if (!fs::exists(saveDir))
    {
        fs::create_directory(saveDir);
    }

    string saveFiles[10];
    for (auto &entry : fs::directory_iterator(saveDir))
    {
        if (entry.is_regular_file())
        {
            saveFiles[fileCount] = entry.path().string();
            fileCount++;
        }
    }

    // Let user pick
    cout << "\n\nAvailable Save Files:\n";
    if (fileCount == 0)
    {
        cout << "\n[No saves found — will start new]\n";
    }
    else
    {
        for (int i = 0; i < fileCount; i++)
        {
            cout << (i + 1) << ". " << saveFiles[i] << "\n";
        }
        cout << "N. New Game\n";
    }

    cout << "\nEnter your Choice (N/1/2...): ";
    cin >> choice;
    GameState state;

    do
    {
        if (fileCount == 0 || choice == "N" || choice == "n")
        {
            cout << "\nEnter session name (no spaces): \n";
            cin >> state.sessionName;
            cout << "\nStarting a NEW game...\n";
            flag = true;
        }
        else
        {
            index = stoi(choice) - 1;
            if ((index >= 0) && (index <= fileCount))
            {
                cout << "Loading from: " << saveFiles[index] << endl;
                ok = loadGame(state, saveFiles[index]);
                if (!ok)
                {
                    cout << "Load failed. Starting New.\n";
                }
                flag = true;
            }
            else
            {
                cout << "Invalid choice. Enter Again: ";
            }
        }
    } while (flag == false);

    delay(1);

    clearScreen();

    printGameStart();

    cout << endl
         << "PRESS ENTER TO CONTINUE: ";
    cout.flush();

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, user_input);

    clearScreen();

    runGame(state);

    return 0;
}
