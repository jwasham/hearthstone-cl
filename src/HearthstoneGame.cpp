#include "HearthstoneGame.h"
#include <fstream>
#include <iostream>

HearthstoneGame::HearthstoneGame() {}
HearthstoneGame::~HearthstoneGame() {}

void HearthstoneGame::start(const std::string &deck1,
                            const std::string &deck2) {

  std::cout << "Here we go." << std::endl;

  Player player1;
  Player player2;

  setupPlayer(deck1, player1);
  setupPlayer(deck2, player2);
}

void HearthstoneGame::enableDebugMode() { debugMode = true; }

void HearthstoneGame::disableStrictDecks() { strictDecks = false; }

void HearthstoneGame::setupPlayer(const std::string deckFileName,
                                  Player &player) {

  // @todo replace with OS-appropriate directory separator
  std::string deckLocation = deckDirectory + "/" + deckFileName;

  std::cout << "deck location: " << deckLocation << std::endl;

  Deck deck;
  if (strictDecks) {
    deck.disableStrictMode();
  }

  loadDeck(deckLocation, deckFileName, deck);

  // player.deck
}

void HearthstoneGame::loadDeck(const std::string path,
                               const std::string deckFileName,
                               Deck &deck) const {

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

  //  const int MAX_LINE_LENGTH =80;
  //  bool firstLine {true};
  //  char line[MAX_LINE_LENGTH];
  std::string className;

  std::getline(inFile, className);

  std::cout << "Hero class: " << className << std::endl;

  std::string line;
  std::string cardName;
  int cardCount = 0;
  while (std::getline(inFile, line)) {
    std::cout << "Line: " << line << std::endl;
    auto starPos = line.find('*');
    if (starPos != std::string::npos) {
      cardName = line.substr(0, starPos - 1);
      trimString(cardName);
      cardCount = std::stoi(line.substr(starPos + 1, line.length() - 1));
      std::cout << "Cardname: " << cardName << std::endl;
      std::cout << "Count: " << cardCount << std::endl;
    } else {
      cardName = line;
      trimString(cardName);
      cardCount = 1;
      std::cout << "Cardname: " << cardName << std::endl;
      std::cout << "Count: " << cardCount << std::endl;
    }
  }

  std::cout << "--------------------" << std::endl;

  // make cards from name

  //  Card card;
  //
  //  deck.addCard(card);
}

void HearthstoneGame::trimString(std::string & str) const {

  auto strLength = str.length();
  int alphaStart = -1;
  int alphaEnd = -1;

  for (int i = 0; i < strLength; i++) {
    bool isSpace = std::isspace(str[i]);

    if (alphaStart < 0) {
      if (not isSpace) {
        alphaStart = i;
        break;
      }
    }
  }

  for (auto i = strLength; i > 0; --i) {
    bool isSpace = std::isspace(str[i]);

    if (alphaEnd < 0) {
      if (not isSpace) {
        alphaEnd = static_cast<int>(i);
        break;
      }
    }
  }

  str = str.substr((unsigned long)alphaStart, (unsigned long)alphaEnd);
}

// bool HearthstoneGame::loadDecks() {
//
//  using std::ifstream;
//
//  // load from files
//
//  if (debugMode) {
//    std::cout << "Loading decks: " << deck1Location << " and " <<
//    deck2Location
//              << std::endl;
//  }
//
//  // move to method, save character class and deck to pointers passed as args
//
//  ifstream inFile;
//  inFile.open(deck1Location);
//
//  if (inFile.is_open()) {
//    if (debugMode) {
//      std::cout << "Reading decklist " << deck1Location << std::endl;
//    }
//  } else {
//    std::cerr << "Failed to open file " << deck1Location << std::endl;
//    exit(EXIT_FAILURE);
//  }
//
//  return true;
//}

// void HearthstoneGame::getDeck(deckLocation, char * charClass, ) {
//
//
//
//}

// void HearthstoneGame::deckCheck() {
//
//    const int maxDeckSize {30};
//    int maxPerLegendary {1};
//    int maxPerNonLegendary {2};
//
//    if (not strictDecks) {
//        maxPerLegendary = maxDeckSize;
//        maxPerNonLegendary = maxDeckSize;
//    }
//
//    return true;
//}