#include "HearthstoneGame.h"

int main(int argc, char *argv[]) {
  HearthstoneCL::HearthstoneGame game;
  game.SetupFromCommandLineOptions(argc, argv);
  game.Start();

  return EXIT_SUCCESS;
}
