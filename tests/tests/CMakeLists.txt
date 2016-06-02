include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHearthstoneTests
        argument_check.cpp)

target_link_libraries(runHearthstoneTests gtest gtest_main)
target_link_libraries(runHearthstoneTests hearthstone_cl)
