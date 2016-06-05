#ifndef HEARTHSTONE_CL_DECK_H
#define HEARTHSTONE_CL_DECK_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Card.h"
#include "Utilities.h"

namespace HearthstoneDeck {

class Deck {
 public:
  Deck();
  Deck(const Deck &d) = delete;
  Deck &operator=(const Deck &d) = delete;
  virtual ~Deck();
  void EnableDebugMode();
  void DisableStrictMode();
  void LoadDeckFromFile(const std::string deckFilePath);
  void SetHeroClass(const std::string hc);
  void AddCard(const HearthstoneCard::Card &card);
  void Shuffle();
  //  Card *GetRandomCards(const int count);
  //  bool CanDrawCard() const;
  //  Card DrawCard();
  //  void ShuffleIntoDeck(const Card &card);

 private:
  //  const short CARD_MAX{30};
  // allows deck to grow/shrink, supports random_shuffle
  void OutputDebugMessage(const std::string message);

  bool debug_mode_{false};
  bool strict_decks_{true};
  std::string hero_class_;
  std::vector<HearthstoneCard::Card> cards_;
};

}  // namespace HearthstoneDeck

#endif  // HEARTHSTONE_CL_DECK_H
