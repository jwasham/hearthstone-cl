#ifndef HEARTHSTONE_CL_HEARTHSTONEGAME_H
#define HEARTHSTONE_CL_HEARTHSTONEGAME_H

#include <string>

class HearthstoneGame {
private:
  bool debugMode{false};
  bool strictDecks{true};
  const std::string deckDirectory{"decks"};
  std::string deck1Location;
  std::string deck2Location;
  bool loadDecks();
  // bool deckCheck();

public:
  HearthstoneGame();
  virtual ~HearthstoneGame();
  void setDecks(const std::string &deck1, const std::string &deck2);
  void enableDebugMode();
  void disableStrictDecks();
};

#endif // HEARTHSTONE_CL_HEARTHSTONEGAME_H
