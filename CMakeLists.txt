cmake_minimum_required(VERSION 3.28)
project(MonsterWaves)

set(CMAKE_CXX_STANDARD 20)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
set(MONSTER_WAVES_DIR ${ROOT_DIR}/MonsterWaves)
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