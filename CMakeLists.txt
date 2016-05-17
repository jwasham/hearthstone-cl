cmake_minimum_required(VERSION 3.5)
project(hearthstone_cl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp HearthstoneGame.cpp)
add_executable(hearthstone_cl ${SOURCE_FILES})
