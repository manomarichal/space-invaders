// =====================================================================
// @name: Stopwatch.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 10.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STOPWATCH_H
#define SPACE_INVADERS_STOPWATCH_H


#include <chrono>
class Stopwatch
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> begin;
    long duration;
public:
    explicit Stopwatch(long duration): duration(duration) {begin = std::chrono::high_resolution_clock::now();};

    bool isReady()
    {
        auto time_passed = std::chrono::duration_cast< std::chrono::milliseconds >((std::chrono::high_resolution_clock::now() - begin));

        if (time_passed.count() > duration)
        {
            begin = std::chrono::high_resolution_clock::now();
            return true;
        }

        return false;
    }

    void setDuration(long milliseconds)
    {
        Stopwatch::duration = milliseconds;
    }

};
#endif //SPACE_INVADERS_STOPWATCH_H
