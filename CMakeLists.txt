cmake_minimum_required(VERSION 3.21)
project(snake_game VERSION 0.1.0 LANGUAGES C)

set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

include(CTest)
enable_testing()

set(FILES ${PROJECT_SOURCE_DIR}/main.c)
add_executable(snake_game ${FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
