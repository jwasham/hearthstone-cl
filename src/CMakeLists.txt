cmake_minimum_required(VERSION 3.5)
project(hearthstone_cl)

add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_GLIBCXX_DEBUG")

set(HEADER_FILES
        Utilities.h
        HearthstoneGame.h
        Deck.h
        Card.h
        Player.h
        )

set(SOURCE_FILES
        Utilities.cpp
        HearthstoneGame.cpp
        Deck.cpp
        Card.cpp
        Player.cpp
        )

add_library(hearthstone_cl STATIC ${SOURCE_FILES} ${HEADER_FILES})
