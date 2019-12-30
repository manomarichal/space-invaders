/** \file Subject.h
* project: space_invaders
* author: Mano Marichal
* date: 05.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_SUBJECT_H
#define SPACE_INVADERS_SUBJECT_H

#include <vector>
#include "Observer.h"

namespace objects
{
    class Subject
    {
    protected:
        std::vector<std::weak_ptr<Observer>> observers;
        void notify() const { for (auto &observer:observers) observer.lock()->onNotify(); };
    public:
        /**
         * used to attach observers to the subject, meaning the subject object can call their onNotify() function
         * @param observer the observer that wants to attach to the subject
         */
        void attach(std::weak_ptr<Observer> observer) {observers.emplace_back(std::move(observer));};
        virtual ~Subject()=0;
    };
    inline Subject::~Subject()=default;

}
#endif //SPACE_INVADERS_SUBJECT_H
