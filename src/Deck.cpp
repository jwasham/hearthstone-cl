#include "Deck.h"

Deck::Deck() {}
Deck::~Deck() {}

void Deck::enableDebugMode() { debugMode = true; }

void Deck::disableStrictMode() { strictDecks = false; }

void Deck::addCard(const Card &card) {

  cards.push_back(card);
  shuffle();
}

void Deck::shuffle() { std::random_shuffle(cards.begin(), cards.end()); }

void Deck::setHeroClass(const std::string hc) { heroClass = hc; }

void Deck::loadDeckFromFile(const std::string path, const std::string deckFileName) {

  using std::ifstream;

  // load from files

  if (debugMode) {
    std::cout << "Loading deck: " << deckFileName << std::endl;
  }

  // move to method, save character class and deck to pointers passed as args

  ifstream inFile;
  inFile.open(path);

  if (inFile.is_open()) {
    if (debugMode) {
      std::cout << "Reading decklist " << path << std::endl;
    }
  } else {
    std::cerr << "Failed to open file " << path << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string className;

  std::getline(inFile, className);

  Utilities::trimString(className);
  Utilities::lowerCase(className);

  // @todo check for valid hero class

//  if (not HeroClass::isValidClass(className)) {
//    std::cerr << "Invalid hero class: " << className << std::endl;
//    exit(EXIT_FAILURE);
//  }

  setHeroClass(className);

  std::cout << "Hero class: " << className << std::endl;

  std::string line;
  std::string cardName;
  int lineNumber = 1; // first line with class was already read
  int cardCount = 0;
  while (std::getline(inFile, line)) {
    lineNumber++;
    std::cout << "Line " << lineNumber << ": " << line << std::endl;

    auto starPos = line.find('*');
    if (starPos != std::string::npos) {
      cardName = line.substr(0, starPos - 1);
      Utilities::trimString(cardName);
      cardCount = std::stoi(line.substr(starPos + 1, line.length() - 1));
      std::cout << "  - Card name: " << cardName << std::endl;
      std::cout << "  - Count: " << cardCount << std::endl;
    } else {
      cardName = line;
      Utilities::trimString(cardName);
      cardCount = 1;
      std::cout << "  - Card name: " << cardName << std::endl;
      std::cout << "  - Count: " << cardCount << std::endl;
    }
  }

  std::cout << "--------------------" << std::endl;

  // make cards from name

  //  Card card;
  //
  //  addCard(card);

  inFile.close();
}
