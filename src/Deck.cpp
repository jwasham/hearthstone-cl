#include "Deck.h"

namespace HearthstoneDeck {

Deck::Deck() {}
Deck::~Deck() {}

void Deck::EnableDebugMode() { debug_mode_ = true; }

void Deck::DisableStrictMode() { strict_decks_ = false; }

void Deck::AddCard(const HearthstoneCard::Card &card) {
  cards_.push_back(card);
  Shuffle();
}

void Deck::Shuffle() {
    std::vector<HearthstoneCard::Card> small;
    std::vector<HearthstoneCard::Card> med;
    std::vector<HearthstoneCard::Card> large;

    for(auto i = cards_.begin(); i != cards_.end(); i++) {
        int cardCost = i->getCost();
        if(cardCost <= 4) small.push_back(*i);
        else if(cardCost <=6) med.push_back(*i);
        else large.push_back(*i);
    }

    cards_.clear();

    std::random_shuffle(small.begin(),small.end());
    std::random_shuffle(med.begin(),med.end());
    std::random_shuffle(large.begin(),large.end());

    cards_.reserve(small.size() + med.size() + large.size());
    cards_.insert(cards_.end(), small.begin(), small.end());
    cards_.insert(cards_.end(), med.begin(), med.end());
    cards_.insert(cards_.end(), large.begin(), large.end());
}

void Deck::SetHeroClass(const std::string hc) { hero_class_ = hc; }

void Deck::LoadDeckFromFile(const std::string deckFilePath) {
  using std::ifstream;

  // load from files

  OutputDebugMessage("Loading deck: " + deckFilePath);

  // move to method, save character class and deck to pointers passed as args_

  ifstream inFile;
  inFile.open(deckFilePath);

  if (inFile.is_open()) {
    OutputDebugMessage("Reading decklist: " + deckFilePath);
  } else {
    std::cerr << "Failed to open file: " << deckFilePath << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string className;

  std::getline(inFile, className);

  General::Utilities::TrimString(className);
  General::Utilities::LowerCase(className);

  // @todo check for valid hero class

  //  if (not HeroClass::isValidClass(className)) {
  //    std::cerr << "Invalid hero class: " << className << std::endl;
  //    exit(EXIT_FAILURE);
  //  }

  SetHeroClass(className);

  OutputDebugMessage("Hero class: " + className);

  std::string line;
  std::string cardName;
  int lineNumber = 1;  // first line with class was already read
  int cardCount = 0;
  while (std::getline(inFile, line)) {
    lineNumber++;
    OutputDebugMessage("Line " + std::to_string(lineNumber) + ": " + line);

    auto starPos = line.find('*');
    if (starPos != std::string::npos) {
      cardName = line.substr(0, starPos - 1);
      General::Utilities::TrimString(cardName);
      cardCount = std::stoi(line.substr(starPos + 1, line.length() - 1));
      OutputDebugMessage("  - Card name: " + cardName);
      OutputDebugMessage("  - Count: " + std::to_string(cardCount));
    } else {
      cardName = line;
      General::Utilities::TrimString(cardName);
      cardCount = 1;
      OutputDebugMessage("  - Card name: " + cardName);
      OutputDebugMessage("  - Count: " + std::to_string(cardCount));
    }
  }

  OutputDebugMessage("-------------------------------");

  // make cards from name

  //  Card card;
  //
  //  addCard(card);

  inFile.close();
}

void Deck::OutputDebugMessage(const std::string message) {
  if (debug_mode_) {
    std::cout << message << std::endl;
  }
}

// void Deck::deckCheck() {
//
//    const int maxDeckSize {30};
//    int maxPerLegendary {1};
//    int maxPerNonLegendary {2};
//
//    if (not strict_decks) {
//        maxPerLegendary = maxDeckSize;
//        maxPerNonLegendary = maxDeckSize;
//    }
//
//    return true;
//}

}  // namespace HearthstoneDeck
