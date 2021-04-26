cmake_minimum_required(VERSION 3.0.0)
project(ExamTP C CXX)

include(CTest)
enable_testing()

add_executable(ExamTP src/main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
