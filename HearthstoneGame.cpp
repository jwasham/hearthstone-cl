#include <iostream>
#include <fstream>
#include "HearthstoneGame.h"

HearthstoneGame::HearthstoneGame() {
    this->debugMode = false;
    this->strictDecks = true;
}

void HearthstoneGame::init(const std::string & deck1, const std::string & deck2)
{
    std::cout << "Here we go." << std::endl;

    deck1Location = deckDirectory + "/" + deck1;
    deck2Location = deckDirectory + "/" + deck2;

    if (loadDecks()) {
        //bool deckCheck = this->deckCheck();
    }
}

void HearthstoneGame::enableDebugMode() {
    debugMode = true;
}

void HearthstoneGame::disableStrictDecks() {
    strictDecks = false;
}

bool HearthstoneGame::loadDecks() {

    using namespace std;

    // load from files

    if (debugMode) {
        std::cout << "Loading decks: " << deck1Location << " and " << deck2Location << std::endl;
    }

    // move to method, save character class and deck to pointers passed as args

    ifstream inFile;
    inFile.open(deck1Location);

    if (inFile.is_open()) {
        if (debugMode) {
            std::cout << "Reading decklist " << deck1Location << std::endl;
        }
    } else {
        cerr << "Failed to open file " << deck1Location << endl;
        exit(EXIT_FAILURE);
    }

    return true;
}

//void HearthstoneGame::getDeck(deckLocation, char * charClass, ) {
//
//
//
//}

//bool HearthstoneGame::deckCheck() {
//
//    const int maxDeckSize {30};
//    int maxPerLegendary {1};
//    int maxPerNonLegendary {2};
//
//    if (not strictDecks) {
//        maxPerLegendary = maxDeckSize;
//        maxPerNonLegendary = maxDeckSize;
//    }
//
//    return true;
//}