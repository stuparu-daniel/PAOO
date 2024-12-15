cmake_minimum_required(VERSION 3.29)
project(tema4)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(tema4
        ${SOURCE_DIR}/main.cpp
        ${INCLUDE_DIR}/Resource.h
        ${SOURCE_DIR}/Resource.cpp
        ${INCLUDE_DIR}/ResourceManager.h
        ${SOURCE_DIR}/ResourceManager.cpp)

target_include_directories(tema4 PUBLIC ${INCLUDE_DIR})
