/** \file Stopwatch.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 29.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "./Stopwatch.h"

bool util::Stopwatch::isReady()
{
        auto time_passed =
            std::chrono::duration_cast<std::chrono::milliseconds>((std::chrono::high_resolution_clock::now() - begin));

        if (time_passed.count() > duration) {
                begin = std::chrono::high_resolution_clock::now();
                return true;
        }

        return false;
}

long util::Stopwatch::getDuration() const { return duration; }

void util::Stopwatch::setDuration(long duration) { Stopwatch::duration = duration; }
