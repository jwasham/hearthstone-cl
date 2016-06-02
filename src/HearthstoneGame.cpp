#include "HearthstoneGame.h"

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
  if (debugMode) {
    deck.enableDebugMode();
  }
  if (strictDecks) {
    deck.disableStrictMode();
  }

  deck.loadDeckFromFile(deckLocation, deckFileName);

  // player.deck
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
