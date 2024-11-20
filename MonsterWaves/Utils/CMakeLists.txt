# Create static library for module Utils
add_library(UtilsModule STATIC RandomGenerator.cpp
                               TimeStep.cpp)
# Add include directories for search
include_directories(${MONSTER_WAVES_DIR} ${SFML_INCLUDE_DIR})
# Link all dependencies for UtilsModule
target_link_libraries(UtilsModule PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)