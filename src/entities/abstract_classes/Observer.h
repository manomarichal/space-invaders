/** \file Observer.h
* project: space_invaders
* author: Mano Marichal
* date: 05.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */#ifndef SPACE_INVADERS_OBSERVER_H
#define SPACE_INVADERS_OBSERVER_H

namespace entities
{
    class Observer: public std::enable_shared_from_this<Observer>
    {
    public:
        virtual void onNotify()=0;
        virtual ~Observer()=default;
    };
}

#endif //SPACE_INVADERS_OBSERVER_H
