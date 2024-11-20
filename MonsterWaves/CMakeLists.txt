# Add subdirectories with modules
add_subdirectory(Core Screen Utils)

# Create library which link all modules
add_library(MonsterWavesLib INTERFACE)

# Link all modules to MonsterWavesLib
target_link_libraries(MonsterWavesLib INTERFACE CoreModule ScreenModule UtilsModule)