#ifndef HEARTHSTONE_CL_DECK_H
#define HEARTHSTONE_CL_DECK_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Card.h"
#include "Utilities.h"

class Deck {
 private:
  bool debugMode{false};
  bool strictDecks{true};
  std::string heroClass;
  //  const short CARD_MAX{30};
  std::vector<Card>
      cards;  // allows deck to grow/shrinl, supports random_shuffle

 public:
  Deck();
  Deck(const Deck &d){};  // dummy copy constructor
  Deck &operator=(const Deck &d) {
    return *this;
  };  // dummy assignment operator
  virtual ~Deck();
  void enableDebugMode();
  void disableStrictMode();
  void loadDeckFromFile(const std::string path, const std::string deckFileName);
  void setHeroClass(const std::string hc);
  void addCard(const Card &card);
  void shuffle();
  //  Card *getRandomCards(const int count);
  //  bool canDrawCard() const;
  //  Card drawCard();
  //  void shuffleIntoDeck(const Card &card);
};

#endif  // HEARTHSTONE_CL_DECK_H
