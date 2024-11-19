include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(MonsterWavesTest
        main.cpp
        test_window.cpp
        test_randomGenerator.cpp)

target_link_libraries(MonsterWavesTest gtest gtest_main)
target_link_libraries(MonsterWavesTest monster_waves)