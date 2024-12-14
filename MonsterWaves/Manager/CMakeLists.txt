# Create static library for module Manager
add_library(ManagerModule STATIC ScreenManager.cpp)
# Add include directories for search
include_directories(${MONSTER_WAVES_DIR} ${SFML_INCLUDE_DIR})
# Link all dependencies for ManagerModule
target_link_libraries(ManagerModule PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)