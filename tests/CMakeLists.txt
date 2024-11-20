project(tests)

# Add external test libraries from the libs directory
add_subdirectory(libs/googletest)

# Add directory with unit tests for MonsterWaves
add_subdirectory(monster_waves_tests)