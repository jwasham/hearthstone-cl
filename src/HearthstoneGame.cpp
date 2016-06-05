#include "HearthstoneGame.h"

namespace HearthstoneCL {

HearthstoneGame::HearthstoneGame() {}
HearthstoneGame::~HearthstoneGame() {}

void HearthstoneGame::ShowUsage() {
  if (suppress_usage_message_) {
    return;
  }

  using std::cerr;
  using std::endl;

  cerr << "Usage: hearthstone_cl [-D] [--strict-decks=false] "
          "/path/to/deck1.txt /path/to/deck2.txt"
       << endl;
  cerr << "       (deck files go in \"decks\" directory)" << endl;
  cerr << "       -D = debug mode" << endl;
  cerr << "       --strict-decks=false = allow any deck of 30 cards, no "
          "restrictions"
       << endl;
  cerr << "       --strict-decks=true = (default) legal deck of 30 cards"
       << endl;
}

bool HearthstoneGame::SetupFromCommandLineOptions(const int argc, char **argv) {
  using std::string;

  bool cmdDebugMode = false;
  bool cmdStrictDecks = true;
  string deck1;
  string deck2;
  int optionalArgCount{0};
  const int minArgCount{3};

  if (argc < minArgCount) {
    ShowUsage();
    return false;
  }

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-D") == 0) {
      optionalArgCount++;
      cmdDebugMode = true;
    } else if (strcmp(argv[i], "--strict-decks=false") == 0) {
      optionalArgCount++;
      cmdStrictDecks = false;
    } else if (strcmp(argv[i], "--strict-decks=true") == 0) {
      optionalArgCount++;
      cmdStrictDecks = true;
    }
  }

  if (optionalArgCount + minArgCount < argc) {
    ShowUsage();
    return false;
  }

  // always the last 2 arguments
  deck1 = argv[optionalArgCount + 1];
  deck2 = argv[optionalArgCount + 2];

  args_.debug_mode = cmdDebugMode;
  args_.strict_decks = cmdStrictDecks;
  args_.deck1_name = deck1;
  args_.deck2_name = deck2;

  if (args_.debug_mode) {
    EnableDebugMode();
  }
  if (not args_.strict_decks) {
    DisableStrictDecks();
  }
  SetDeck1(args_.deck1_name);
  SetDeck2(args_.deck2_name);

  return true;
}

void HearthstoneGame::SuppressUsage() { suppress_usage_message_ = true; }

void HearthstoneGame::EnableDebugMode() { debug_mode_ = true; }

void HearthstoneGame::DisableStrictDecks() { strict_dck_mode_ = false; }

void HearthstoneGame::SetDeck1(const std::string deckPath) {
  SetupPlayer(deckPath, &player1_);
}

void HearthstoneGame::SetDeck2(const std::string deckPath) {
  SetupPlayer(deckPath, &player2_);
}

void HearthstoneGame::SetupPlayer(const std::string deckFilePath,
                                  HearthstonePlayer::Player *player) {
  HearthstoneDeck::Deck deck;
  if (debug_mode_) {
    deck.EnableDebugMode();
  }
  if (not strict_dck_mode_) {
    deck.DisableStrictMode();
  }

  deck.LoadDeckFromFile(deckFilePath);

  // player.deck
}

void HearthstoneGame::Start() {
  // make sure there is deck1
  // make sure there is deck2

  std::cout << "Here we go." << std::endl;

  // Start the game
}
}  // namespace HearthstoneCL