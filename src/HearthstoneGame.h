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
 public:
  CommandLineArguments args;
  HearthstoneGame();
  HearthstoneGame(const HearthstoneGame &h){};  // dummy copy constructor
  HearthstoneGame &operator=(const HearthstoneGame &h) {
    return *this;
  };  // dummy assignment operator
  virtual ~HearthstoneGame();
  void showUsage();
  bool setupFromCommandLineOptions(const int argc, char *argv[]);
  void suppressUsage();
  void enableDebugMode();
  void disableStrictDecks();
  void setDeck1(const std::string deckPath);
  void setDeck2(const std::string deckPath);
  void start();

 private:
  bool suppressUsageMessage{false};
  bool debugMode{false};
  bool strictDeckMode{true};
  Player player1;
  Player player2;
  void setupPlayer(const std::string deckFilePath, Player *player);
};
}

#endif  // HEARTHSTONE_CL_HEARTHSTONEGAME_H
