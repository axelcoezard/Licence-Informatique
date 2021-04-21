cmake_minimum_required(VERSION 3.0.0)
project(TP2 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(TP2 src/main.c)
target_link_libraries(TP2 PRIVATE m)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
