#include <iostream>
#include "HearthstoneGame.h"

using namespace std;

void showUsage();

int main(int argc, char * argv[])
{
    bool debugMode = false;
    string deck1 = argv[1];
    string deck2 = argv[2];

    if (argc < 3) {
        showUsage();
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-D") == 0) {
            debugMode = true;
            if (argc < 4) {
                showUsage();
            } else {
                deck1 = argv[2];
                deck2 = argv[3];
            }
        } else {
            deck1 = argv[1];
            deck2 = argv[2];
        }
    }

    HearthstoneGame game;
    if (debugMode) {
        game.enableDebugMode();
    }
    game.init(deck1, deck2);

    return EXIT_SUCCESS;
}

void showUsage() {
    cout << "Usage: hearthstone_cl [-d] deck1.txt deck2.txt" << endl;
    cout << "       -D = debug mode" << endl;
}