project(tests)

include_directories(${MONSTER_WAVES_DIR})

add_subdirectory(${TESTS_LIBS_DIR}/googletest)
add_subdirectory(monster_waves_tests)