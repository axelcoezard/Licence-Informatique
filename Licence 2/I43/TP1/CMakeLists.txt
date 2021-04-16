cmake_minimum_required(VERSION 3.0.0)
project(I43-TP1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(I43-TP1 src/vigenere.c)

set(CMAKE_CXX_FLAGS_INIT "-Werror -Wall -Wextra -Wpedantic")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
