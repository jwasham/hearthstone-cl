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
  HearthstoneGame(const HearthstoneGame & h) {}; // dummy copy constructor
  HearthstoneGame & operator=(const HearthstoneGame & h) { return *this; }; // dummy assignment operator
  virtual ~HearthstoneGame();
  void setDecks(const std::string &deck1, const std::string &deck2);
  void enableDebugMode();
  void disableStrictDecks();
};

#endif // HEARTHSTONE_CL_HEARTHSTONEGAME_H
