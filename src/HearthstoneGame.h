#ifndef HEARTHSTONE_CL_HEARTHSTONEGAME_H
#define HEARTHSTONE_CL_HEARTHSTONEGAME_H

#include <string>
#include "Player.h"

namespace HearthstoneCL {

  class HearthstoneGame {
   private:
    bool debugMode{false};
    bool strictDecks{true};
    Player player1;
    Player player2;
    const std::string deckDirectory{"decks"};
    void setupPlayer(const std::string deckFileName, Player &player);
    // void deckCheck();

   public:
    static void showUsage();

    HearthstoneGame();
    HearthstoneGame(const HearthstoneGame &h){};  // dummy copy constructor
    HearthstoneGame &operator=(const HearthstoneGame &h) {
      return *this;
    };  // dummy assignment operator
    virtual ~HearthstoneGame();
    void start(const std::string &deck1, const std::string &deck2);
    void enableDebugMode();
    void disableStrictDecks();
  };

}

#endif  // HEARTHSTONE_CL_HEARTHSTONEGAME_H
