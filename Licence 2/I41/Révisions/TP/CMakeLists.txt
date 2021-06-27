cmake_minimum_required(VERSION 3.0.0)
project(Sandbox VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(-Wall -Wextra -Werror)
add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} m)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
