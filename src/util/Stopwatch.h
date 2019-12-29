// =====================================================================
// @name: Stopwatch.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 10.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: Class used to calculate intervals, which take the same time on all machines
// =====================================================================

#ifndef SPACE_INVADERS_STOPWATCH_H
#define SPACE_INVADERS_STOPWATCH_H


#include <chrono>
namespace util
{
    class Stopwatch
    {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> begin; /*!< the begin of our current interval*/
        long duration; /*!< how long has passed since the begin of the current interval*/
    public:
        /**
         * Constructor
         * @param duration of how long intervals should take for the stopwatch in milliseconds
         */
        explicit Stopwatch(long duration): duration(duration) {begin = std::chrono::high_resolution_clock::now();};
        /**
         * tells if the stopwatch is ready, meaning there has passed more time since the last time this function was called
         * than the duration.
         * @return if the stopwatch is ready, or not
         */
        bool isReady();
    };
}

#endif //SPACE_INVADERS_STOPWATCH_H
