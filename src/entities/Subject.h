// =====================================================================
// @name: Subject.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 05.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_SUBJECT_H
#define SPACE_INVADERS_SUBJECT_H

#include <vector>
#include "Observer.h"

namespace entities
{
    class Subject
    {
    protected:
        std::vector<Observer*> observers;
        void notifyObservers() const { for (auto &observer:observers) observer->notify(); };
    public:
        void subscribe(Observer* observer) {observers.emplace_back(observer);};
        virtual ~Subject()=0;
    };
    inline Subject::~Subject()=default;

}
#endif //SPACE_INVADERS_SUBJECT_H
