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

void Deck::loadDeckFromFile(const std::string deckFilePath) {
  using std::ifstream;

  // load from files

  outputDebugMessage("Loading deck: " + deckFilePath);

  // move to method, save character class and deck to pointers passed as args

  ifstream inFile;
  inFile.open(deckFilePath);

  if (inFile.is_open()) {
    outputDebugMessage("Reading decklist: " + deckFilePath);
  } else {
    std::cerr << "Failed to open file: " << deckFilePath << std::endl;
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

  outputDebugMessage("Hero class: " + className);

  std::string line;
  std::string cardName;
  int lineNumber = 1;  // first line with class was already read
  int cardCount = 0;
  while (std::getline(inFile, line)) {
    lineNumber++;
    outputDebugMessage("Line " + std::to_string(lineNumber) + ": " + line);

    auto starPos = line.find('*');
    if (starPos != std::string::npos) {
      cardName = line.substr(0, starPos - 1);
      Utilities::trimString(cardName);
      cardCount = std::stoi(line.substr(starPos + 1, line.length() - 1));
      outputDebugMessage("  - Card name: " + cardName);
      outputDebugMessage("  - Count: " + std::to_string(cardCount));
    } else {
      cardName = line;
      Utilities::trimString(cardName);
      cardCount = 1;
      outputDebugMessage("  - Card name: " + cardName);
      outputDebugMessage("  - Count: " + std::to_string(cardCount));
    }
  }

  outputDebugMessage("-------------------------------");

  // make cards from name

  //  Card card;
  //
  //  addCard(card);

  inFile.close();
}

void Deck::outputDebugMessage(const std::string message) {
  if (debugMode) {
    std::cout << message << std::endl;
  }
}