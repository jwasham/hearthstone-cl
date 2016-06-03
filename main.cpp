#include <iostream>
#include "HearthstoneGame.h"

int main(int argc, char *argv[]) {
  HearthstoneCL::HearthstoneGame game;
  game.setupFromCommandLineOptions(argc, argv);
  game.start();

  return EXIT_SUCCESS;
}
