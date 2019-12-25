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
#include "../entities/abstract_classes/Observer.h"

namespace entities
{
    class Subject
    {
    protected:
        std::vector<std::weak_ptr<Observer>> observers;
        void onNotifyObservers() const { for (auto &observer:observers) observer.lock()->onNotify(); };
    public:
        void attach(std::weak_ptr<Observer> observer) {observers.emplace_back(std::move(observer));};
        virtual ~Subject()=0;
    };
    inline Subject::~Subject()=default;

}
#endif //SPACE_INVADERS_SUBJECT_H
