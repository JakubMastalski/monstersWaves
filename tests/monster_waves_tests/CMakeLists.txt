# Add include directories for search
include_directories(${MONSTER_WAVES_DIR} ${SFML_INCLUDE_DIR})

# Create executable file
add_executable(MonsterWavesTests main.cpp
                                 test_randomGenerator.cpp
                                 test_window.cpp)

# Link all dependencies for MonsterWavesTests
target_link_libraries(  MonsterWavesTests
                        gtest gtest_main
                        MonsterWavesLib
                        sfml-system sfml-window sfml-graphics sfml-audio sfml-network)