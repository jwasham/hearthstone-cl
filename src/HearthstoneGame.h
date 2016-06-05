#ifndef HEARTHSTONE_CL_HEARTHSTONEGAME_H
#define HEARTHSTONE_CL_HEARTHSTONEGAME_H

#include <string>
#include "Player.h"

namespace HearthstoneCL {

struct CommandLineArguments {
  bool debug_mode{false};
  bool strict_decks{true};
  std::string deck1_name;
  std::string deck2_name;
};

class HearthstoneGame {
 public:
  CommandLineArguments args_;
  HearthstoneGame();
  HearthstoneGame(const HearthstoneGame &){};  // dummy copy constructor
  HearthstoneGame &operator=(const HearthstoneGame &) {
    return *this;
  };  // dummy assignment operator
  virtual ~HearthstoneGame();
  void ShowUsage();
  bool SetupFromCommandLineOptions(const int argc, char **argv);
  void SuppressUsage();
  void EnableDebugMode();
  void DisableStrictDecks();
  void SetDeck1(const std::string deckPath);
  void SetDeck2(const std::string deckPath);
  void Start();

 private:
  bool suppress_usage_message_{false};
  bool debug_mode_{false};
  bool strict_dck_mode_{true};
  Player player1_;
  Player player2_;
  void SetupPlayer(const std::string deckFilePath, Player *player);
};

}  // namespace HearthstoneCL

#endif  // HEARTHSTONE_CL_HEARTHSTONEGAME_H
