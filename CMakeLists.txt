cmake_minimum_required(VERSION 3.21)
project(PEGTemplate C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 23)

include(cmake/FetchPackCC.cmake)

add_peg_target(calc-parser ${CMAKE_CURRENT_SOURCE_DIR}/calc.peg OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/gen/calc)
add_executable(calc calc.cpp calc.configured.c)