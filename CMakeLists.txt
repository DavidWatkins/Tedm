cmake_minimum_required(VERSION 3.1)
project(Tedm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    drawable.hpp
    environment.cpp
    environment.hpp
    event.hpp
    game.cpp
    game.hpp
    graphics.cpp
    graphics.hpp
    Makefile
    object.hpp
    player.hpp
    pong.cpp
    README.md
    sprite.hpp
    state.hpp
    test01.cpp)

add_executable(Tedm ${SOURCE_FILES})