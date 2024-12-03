# Create static library for module Screen
add_library(ScreenModule STATIC Window.cpp
                                SplashScreen.cpp
                                BaseScreen.cpp  
                                MenuScreen.cpp 
                                GameScreen.cpp)

# Add include directories for search
include_directories(${MONSTER_WAVES_DIR} ${SFML_INCLUDE_DIR})

# Link all dependencies for ScreenModule
target_link_libraries(ScreenModule PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)