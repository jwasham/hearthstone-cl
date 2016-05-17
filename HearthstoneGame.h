//
// Created by John on 5/16/16.
//

#ifndef HEARTHSTONE_CL_HEARTHSTONEGAME_H
#define HEARTHSTONE_CL_HEARTHSTONEGAME_H

#include <iostream>
#include <string>

class HearthstoneGame
{
private:
    bool debugMode;
    std::string deck1Location;
    std::string deck2Location;
    bool loadDecks();
//    bool deckCheck();

public:
    HearthstoneGame();
    void init(const std::string & deck1, const std::string & deck2);
    void enableDebugMode();
//    bool getPlayerNames();
};


#endif //HEARTHSTONE_CL_HEARTHSTONEGAME_H
