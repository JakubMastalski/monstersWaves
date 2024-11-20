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

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
set(MONSTER_WAVES_DIR ${ROOT_DIR}/monster_waves)
set(MONSTER_WAVES_LIB monster_waves)
set(SFML_INCLUDE_DIR libs/SFML-2.6.1/include)
set(SFML_DIR ${ROOT_DIR}/libs/SFML-2.6.1/lib/cmake/SFML)
set(TESTS_DIR ${ROOT_DIR}/tests)
set(TESTS_LIBS_DIR ${TESTS_DIR}/libs)

add_subdirectory(${MONSTER_WAVES_DIR})
add_subdirectory(${TESTS_DIR})

set(SOURCE_FILES main.cpp)
add_executable(MonsterWaves ${SOURCE_FILES})

include_directories(${MONSTER_WAVES_DIR})
include_directories(${SFML_INCLUDE_DIR})
include_directories(${TESTS_DIR})

target_link_libraries(MonsterWaves ${MONSTER_WAVES_LIB})
