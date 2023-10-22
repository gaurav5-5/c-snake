cmake_minimum_required(VERSION 3.21)
project(snake_game VERSION 0.1.0 LANGUAGES C)

set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(CMAKE_C_STANDARD 11)


include_directories(${PROJECT_SOURCE_DIR})

set(SOURCES ${PROJECT_SOURCE_DIR}/main.c ${PROJECT_SOURCE_DIR}/input.c)
add_executable(snake_game ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
