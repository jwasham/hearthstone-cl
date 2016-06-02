#ifndef HEARTHSTONE_CL_PLAYER_H
#define HEARTHSTONE_CL_PLAYER_H

#include <string>
#include "Deck.h"

class Player {
 private:
  std::string name;
  // hero (Hero class)
  Deck deck;
  // Hand hand;
  //  board half
  //  mana
  //  graveyard (hidden)
 public:
  Player();
  Player(const Player &p){};  // dummy copy constructor
  Player &operator=(const Player &p) {
    return *this;
  };  // dummy assignment operator
  virtual ~Player();
  //  void setDeck(Deck & deck);
};

#endif  // HEARTHSTONE_CL_PLAYER_H
