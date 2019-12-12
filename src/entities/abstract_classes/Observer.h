// =====================================================================
// @name: Observer.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 05.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_OBSERVER_H
#define SPACE_INVADERS_OBSERVER_H

namespace entities
{
    class Observer
    {
    public:
        virtual void notify()=0;
        virtual ~Observer()=0;
    };
    inline Observer::~Observer()=default;

}

#endif //SPACE_INVADERS_OBSERVER_H
