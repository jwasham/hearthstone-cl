#include "HearthstoneGame.h"
#include "gtest/gtest.h"

namespace {

  class CmdOptionsTest : public ::testing::Test {
    protected:

      CmdOptionsTest() {
        // You can do set-up work for each test here.
      }

      virtual ~CmdOptionsTest() {
        // You can do clean-up work that doesn't throw exceptions here.
      }

//      virtual void SetUp() {
//
//      }
//
//      virtual void TearDown() {
//
//      }

  };

  // Tests that the Foo::Bar() method does Abc.
  TEST_F(CmdOptionsTest, FailsOnNoArgs) {
    HearthstoneCL::HearthstoneGame game;
    game.SuppressUsage();
    int argCount = 1;
    char * args[argCount];
    char cmd[] = "hearthstone_cl";
    args[0] = cmd;
    bool success = game.SetupFromCommandLineOptions(argCount, args);
    EXPECT_EQ(success, false);
  }

  TEST_F(CmdOptionsTest, FailsWithoutDecks) {
    HearthstoneCL::HearthstoneGame game;
    game.SuppressUsage();
    int argCount = 2;
    char * args[argCount];
    char cmd1[] = "hearthstone_cl";
    char cmd2[] = "-D";
    args[0] = cmd1;
    args[1] = cmd2;
    bool success = game.SetupFromCommandLineOptions(argCount, args);
    EXPECT_EQ(success, false);
  }

}
