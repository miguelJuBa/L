cmake_minimum_required(VERSION 3.5)
project(Ltests)

# Compiler flags

SET( GCC_CUSTOM_CXX_FLAGS "-g -std=c++11 -Wall -pedantic" )
SET( GCC_CUSTOM_LINK_FLAGS "" )
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_CUSTOM_CXX_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

# External dependencies

add_executable(tests tests.cpp)


