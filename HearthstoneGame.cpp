//
// Created by John on 5/16/16.
//

#include "HearthstoneGame.h"

HearthstoneGame::HearthstoneGame() {
    this->debugMode = false;
}

void HearthstoneGame::init(const std::string & deck1, const std::string & deck2)
{
    std::cout << "Here we go." << std::endl;

    deck1Location = deck1;
    deck2Location = deck2;

    if (loadDecks()) {
//        bool deckCheck = this->deckCheck();
    }
}

void HearthstoneGame::enableDebugMode() {
    debugMode = true;
}

bool HearthstoneGame::loadDecks() {

    // load from files

    if (debugMode) {
        std::cout << "Loading decks: " << deck1Location << " and " << deck2Location << std::endl;
    }

    return true;
}

//bool HearthstoneGame::deckCheck() {
//
//    // check for validity
//
//    return true;
//}