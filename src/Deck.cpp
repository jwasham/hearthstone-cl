#include "Deck.h"

Deck::Deck() {}
Deck::~Deck() {}

void Deck::disableStrictMode() { strictDecks = false; }

void Deck::addCard(const Card &card) {

  cards.push_back(card);
  shuffle();

}

void Deck::shuffle() {
  std::random_shuffle ( cards.begin(), cards.end() );
}

void Deck::setHeroClass(const std::string hc) {
  heroClass = hc;
}


