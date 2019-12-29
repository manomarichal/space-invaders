cmake_minimum_required(VERSION 3.9)
project(space_invaders)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HDRS ${SIZE--_SOURCE_DIR} ./src/*.h  )
file(GLOB_RECURSE SRCS ${SIZE--_SOURCE_DIR} ./src/*.cpp)

add_executable(space_invaders ${HDRS} ${SRCS} src/util/Stopwatch.cpp)

set(CMAKE_CXX_FLAGS " -march=native -Wall -Wextra -Wnon-virtual-dtor -Wold-style-cast -Wunused -Woverloaded-virtual -Wpedantic -Wnull-dereference -Wdouble-promotion -Wformat=2")

target_link_libraries(space_invaders "-lsfml-graphics -lsfml-window -lsfml-system")
