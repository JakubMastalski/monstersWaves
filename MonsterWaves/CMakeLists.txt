# Add subdirectories with modules
add_subdirectory(Core)
add_subdirectory(Screen)
add_subdirectory(Utils)
add_subdirectory(Manager)
add_subdirectory(Entity)

# Create library which link all modules
add_library(MonsterWavesLib INTERFACE)

# Link all modules to MonsterWavesLib
target_link_libraries(MonsterWavesLib INTERFACE CoreModule EntityModule ManagerModule ScreenModule UtilsModule)