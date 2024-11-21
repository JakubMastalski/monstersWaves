cmake_minimum_required(VERSION 3.29)
project(MonsterWaves)

set(CMAKE_CXX_STANDARD 20)

# Create output directory for binary and library compilation
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Set localization of all modules
set(MONSTER_WAVES_DIR ${CMAKE_SOURCE_DIR}/MonsterWaves)

# Check compiler and set localization of SFML lib
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GNU compiler: ${CMAKE_CXX_COMPILER_ID}")
    set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/GCC/SFML-2.6.1/include)
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/libs/GCC/SFML-2.6.1/lib/cmake/SFML)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Using MSVC compiler: ${CMAKE_CXX_COMPILER_ID}")
    set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/MSVC/SFML-2.6.1/include)
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/libs/MSVC/SFML-2.6.1/lib/cmake/SFML)
endif()
# Set SFML static
set(SFML_STATIC_LIBRARIES TRUE)
# Find SFML package
find_package(SFML REQUIRED COMPONENTS system window graphics audio network)

# Add subdirectories for project
add_subdirectory(MonsterWaves)
add_subdirectory(tests)

# Add include directories for search
include_directories(${MONSTER_WAVES_DIR})

# Create executable file
add_executable(MonsterWaves main.cpp)

# Link all dependencies for MonsterWaves
target_link_libraries(MonsterWaves PRIVATE MonsterWavesLib sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
