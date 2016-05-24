#ifndef HEARTHSTONE_CL_DECK_H
#define HEARTHSTONE_CL_DECK_H

#include "Card.h"

class Deck {
private:
  const short CARD_MAX {30};
  std::vector<Card> cards;

public:
  Deck();
  ~Deck();
  void addCard(const Card &card);
  void shuffle();
  Card *getRandomCards(const int count);
  bool canDrawCard() const;
  Card drawCard();
  void shuffleIntoDeck(const Card &card);
};

#endif // HEARTHSTONE_CL_DECK_H
