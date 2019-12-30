
/** \file Clock.cpp
* project: space_invaders
* author: Mano Marichal
* date: 16.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */


#include "./Clock.h"

using namespace util;

std::chrono::time_point<std::chrono::high_resolution_clock> Clock::previous = std::chrono::high_resolution_clock::now();
std::chrono::time_point<std::chrono::high_resolution_clock> Clock::current = std::chrono::high_resolution_clock::now();

double util::Clock::update()
{
    current = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current - previous).count();
    previous = current;
    return elapsed;
}