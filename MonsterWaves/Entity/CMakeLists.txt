# Create static library for module Entity
add_library(EntityModule STATIC Player.cpp Enemy.cpp Direction.cpp)

# Add include directories for search
include_directories(${MONSTER_WAVES_DIR} ${SFML_INCLUDE_DIR})

# Link all dependencies for EntityModule
target_link_libraries(EntityModule PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)