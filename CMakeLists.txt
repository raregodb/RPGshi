cmake_minimum_required(VERSION 3.25)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp Player.cpp Player.h Navigation.cpp Navigation.h Cell.cpp Cell.h Map.cpp Map.h Position.cpp Position.h)
