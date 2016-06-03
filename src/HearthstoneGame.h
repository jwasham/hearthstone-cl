#ifndef HEARTHSTONE_CL_HEARTHSTONEGAME_H
#define HEARTHSTONE_CL_HEARTHSTONEGAME_H

#include <string>
#include "Player.h"

namespace HearthstoneCL {

struct CommandLineArguments {
  bool debugMode{false};
  bool strictDecks{true};
  std::string deck1Name;
  std::string deck2Name;
};

class HearthstoneGame {
 private:
  bool debugMode{false};
  bool strictDeckMode{true};
  Player player1;
  Player player2;
  void setupPlayer(const std::string deckFilePath, Player &player);
  // void deckCheck();

 public:
  static void showUsage();
  CommandLineArguments args;
  HearthstoneGame();
  HearthstoneGame(const HearthstoneGame &h){};  // dummy copy constructor
  HearthstoneGame &operator=(const HearthstoneGame &h) {
    return *this;
  };  // dummy assignment operator
  virtual ~HearthstoneGame();
  void setupFromCommandLineOptions(const int argc, char *argv[]);
  void enableDebugMode();
  void disableStrictDecks();
  void setDeck1(const std::string &deck);
  void setDeck2(const std::string &deck);
  void start();
};
}

#endif  // HEARTHSTONE_CL_HEARTHSTONEGAME_H
