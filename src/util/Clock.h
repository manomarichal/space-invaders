/** \file Clock.h
* project: space_invaders
* author: Mano Marichal
* date: 16.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_CLOCK_H
#define SPACE_INVADERS_CLOCK_H

#include <chrono>

namespace util
{
    class Clock
    {
    public:
        /**
         * updates the clock to the current time and returns the time elapsed between now and the previous time this function was called
         * @return
         */
        static double update();

    private:
        static std::chrono::time_point<std::chrono::high_resolution_clock> previous; /*!< previous timepoint*/
        static std::chrono::time_point<std::chrono::high_resolution_clock> current; /*!< current timepoint */
        Clock() = default;

    public:
        Clock(const Clock &copy) = delete;
        Clock& operator=(Clock) = delete;
    };
}
#endif //SPACE_INVADERS_CLOCK_H
