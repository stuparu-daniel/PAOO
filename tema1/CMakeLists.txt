cmake_minimum_required(VERSION 3.29)
project(tema1)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(tema1 ${SOURCE_DIR}/main.cpp
        ${INCLUDE_DIR}/ComplexNumber.h
        ${SOURCE_DIR}/ComplexNumber.cpp)

target_include_directories(tema1 PUBLIC ${INCLUDE_DIR})
