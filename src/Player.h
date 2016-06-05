#ifndef HEARTHSTONE_CL_PLAYER_H
#define HEARTHSTONE_CL_PLAYER_H

#include <string>
#include "Deck.h"

namespace HearthstonePlayer {

class Player {
 private:
  std::string name_;
  // hero (Hero class)
  HearthstoneDeck::Deck deck_;
  // Hand hand;
  //  board half
  //  mana
  //  graveyard (hidden)
 public:
  Player();
  Player(const Player &p) = delete;
  Player &operator=(const Player &p) = delete;
  virtual ~Player();
  //  void setDeck(Deck & deck);
};

}  // namespace HearthstonePlayer

#endif  // HEARTHSTONE_CL_PLAYER_H
