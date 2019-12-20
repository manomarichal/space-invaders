// =====================================================================
// @name: Clock.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 16.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_CLOCK_H
#define SPACE_INVADERS_CLOCK_H

#include <chrono>

namespace util
{
    class Clock
    {
    private:
        static std::chrono::time_point<std::chrono::high_resolution_clock> previous;
        static std::chrono::time_point<std::chrono::high_resolution_clock> current;

        Clock() = default;

    public:
        static double update();

    };
}
#endif //SPACE_INVADERS_CLOCK_H
