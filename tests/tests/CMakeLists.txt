include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHearthstoneTests
        fixture_cmd_options.cpp
    )

target_link_libraries(runHearthstoneTests gtest gtest_main)
target_link_libraries(runHearthstoneTests hearthstone_cl)
