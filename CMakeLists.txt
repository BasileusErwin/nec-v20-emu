cmake_minimum_required(VERSION 3.2)
project(necV20 VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(NEC_V20_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(NEC_V20_INCLUDE_DIR ${NEC_V20_SOURCE_DIR}/include)

include_directories(${NEC_V20_INCLUDE_DIR})

file(GLOB SOURCES ${NEC_V20_SOURCE_DIR}/*.c)

add_executable(n20 ${SOURCES})

install(TARGETS n20 DESTINATION bin)

add_custom_target(clean-all COMMAND ${CMAKE_COMMAND} -P clean-all.cmake)

file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/*)
