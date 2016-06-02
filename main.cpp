#include <iostream>
#include "HearthstoneGame.h"

int main(int argc, char *argv[]) {
  using std::string;

  bool debugMode = false;
  bool strictDeckMode = false;
  string deck1 = argv[1];
  string deck2 = argv[2];
  int optionalArgCount{0};
  const int minArgCount{3};

  if (argc < minArgCount) {
    HearthstoneCL::HearthstoneGame::showUsage();
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
    HearthstoneCL::HearthstoneGame::showUsage();
    exit(EXIT_FAILURE);
  }

  // always the last 2 arguments
  deck1 = argv[optionalArgCount + 1];
  deck2 = argv[optionalArgCount + 2];

  HearthstoneCL::HearthstoneGame game;
  if (debugMode) {
    game.enableDebugMode();
  }
  if (not strictDeckMode) {
    game.disableStrictDecks();
  }
  game.start(deck1, deck2);

  return EXIT_SUCCESS;
}
