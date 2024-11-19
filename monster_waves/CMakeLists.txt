set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS system window graphics audio network)

add_library(${MONSTER_WAVES_LIB}
            Game.cpp
			TimeStep.cpp 
			RandomGenerator.cpp
			Window.cpp)

include_directories(${ROOT_DIR}/${SFML_INCLUDE_DIR})

target_link_libraries(${MONSTER_WAVES_LIB} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)