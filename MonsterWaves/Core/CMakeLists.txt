# Create static library for module Core
add_library(CoreModule STATIC Game.cpp)

# Add include directories for search
include_directories(${MONSTER_WAVES_DIR} ${SFML_INCLUDE_DIR})

# Link all dependencies for CoreModule
target_link_libraries(CoreModule PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)