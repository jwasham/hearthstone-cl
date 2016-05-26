#include "HearthstoneGame.h"
#include <iostream>

void showUsage();

int main(int argc, char *argv[]) {
  using std::string;

  bool debugMode = false;
  bool strictDeckMode = false;
  string deck1 = argv[1];
  string deck2 = argv[2];
  int optionalArgCount{0};
  const int minArgCount{3};

  if (argc < minArgCount) {
    showUsage();
  }

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-D") == 0) {
      optionalArgCount++;
      debugMode = true;
    } else if (strcmp(argv[i], "--strict-deck=false") == 0) {
      optionalArgCount++;
      strictDeckMode = false;
    } else if (strcmp(argv[i], "--strict-deck=true") == 0) {
      optionalArgCount++;
      strictDeckMode = true;
    }
  }

  if (optionalArgCount + minArgCount < argc) {
    showUsage();
    exit(EXIT_FAILURE);
  }

  // always the last 2 arguments
  deck1 = argv[optionalArgCount + 1];
  deck2 = argv[optionalArgCount + 2];

  HearthstoneGame game;
  if (debugMode) {
    game.enableDebugMode();
  }
  if (not strictDeckMode) {
    game.disableStrictDecks();
  }
  game.start(deck1, deck2);

  return EXIT_SUCCESS;
}

void showUsage() {
  using std::cout;
  using std::endl;

  cout << "Usage: hearthstone_cl [-D] [--strict-deck=false] deck1.txt deck2.txt"
       << endl;
  cout << "       (deck files go in \"decks\" directory)" << endl;
  cout << "       -D = debug mode" << endl;
  cout << "       --strict-deck=false = allow any deck of 30 cards, no "
          "restrictions"
       << endl;
  cout << "       --strict-deck=true = (default) legal deck of 30 cards"
       << endl;
}