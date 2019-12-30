/** \file Observer.h
* project: space_invaders
* author: Mano Marichal
* date: 05.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_OBSERVER_H
#define SPACE_INVADERS_OBSERVER_H

namespace objects
{
    class Observer: public std::enable_shared_from_this<Observer>
    {
    public:
        /**
         * this function specifies what an observer should do when a change happened in the subject we are observing
         */
        virtual void onNotify()=0;
        virtual ~Observer()=default;
    };
}

#endif //SPACE_INVADERS_OBSERVER_H
