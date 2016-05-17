#ifndef HEARTHSTONE_CL_HEARTHSTONEGAME_H
#define HEARTHSTONE_CL_HEARTHSTONEGAME_H

#include <iostream>
#include <string>
#include <fstream>

class HearthstoneGame
{
private:
    bool debugMode;
    bool strictDecks;
    const std::string deckDirectory = "decks";
    std::string deck1Location;
    std::string deck2Location;
    bool loadDecks();
    bool deckCheck();

public:
    HearthstoneGame();
    void init(const std::string & deck1, const std::string & deck2);
    void enableDebugMode();
    void disableStrictDecks();
};


#endif //HEARTHSTONE_CL_HEARTHSTONEGAME_H
