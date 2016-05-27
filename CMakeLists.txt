cmake_minimum_required(VERSION 3.5)
project(hearthstone_cl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/HearthstoneGame.cpp src/Player.cpp src/Deck.cpp src/Card.cpp)
add_executable(hearthstone_cl ${SOURCE_FILES})
