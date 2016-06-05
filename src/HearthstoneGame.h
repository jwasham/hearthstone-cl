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
  HearthstoneGame(const HearthstoneGame &) = delete;
  HearthstoneGame &operator=(const HearthstoneGame &) = delete;
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
  bool strict_deck_mode_{true};
  HearthstonePlayer::Player player1_;
  HearthstonePlayer::Player player2_;
  void SetupPlayer(const std::string deckFilePath,
                   HearthstonePlayer::Player *player);
};

}  // namespace HearthstoneCL

#endif  // HEARTHSTONE_CL_HEARTHSTONEGAME_H
