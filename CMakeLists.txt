cmake_minimum_required(VERSION 3.15)
project(space_invaders)

set(CMAKE_CXX_STANDARD 14)

add_executable(space_invaders
        README.md src/main.cpp src/Entities/Entity.cpp src/Entities/Entity.h)
