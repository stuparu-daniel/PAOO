cmake_minimum_required(VERSION 3.29)
project(tema2)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(tema2 ${SOURCE_DIR}/main.cpp
        ${INCLUDE_DIR}/ComplexNumber.h
        ${SOURCE_DIR}/ComplexNumber.cpp
        ${INCLUDE_DIR}/DerivedComplexNumber.h
        ${SOURCE_DIR}/DerivedComplexNumber.cpp
        ${INCLUDE_DIR}/DumbComplexNumber.h
        ${SOURCE_DIR}/DumbComplexNumber.cpp)

target_include_directories(tema2 PUBLIC ${INCLUDE_DIR})
