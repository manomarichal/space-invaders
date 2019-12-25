// =====================================================================
// @name: Entity.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 17.11.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_ENTITY_H
#define SPACE_INVADERS_ENTITY_H

#include <memory>
#include <utility>
#include <iostream>

#include "../../util/screensize.h"
#include "../../util/Subject.h"
#include "../../util/Subject.h"

namespace entities
{
    class Entity: public Subject
    {
    protected:
        float x;
        float y;
        float xSize{};
        float ySize{};
    public:
        Entity(float x, float y): x(x), y(y) {};
        virtual void update()=0;
        ~Entity() override = default;

        [[nodiscard]] float getX() const
        {
            return x;
        }

        [[nodiscard]] float getY() const
        {
            return y;
        }

        [[nodiscard]] float getXSize() const
        {
            return xSize;
        }

        [[nodiscard]] float getYSize() const
        {
            return ySize;
        }

        void setXSize(float xSize)
        {
            Entity::xSize = xSize;
        }

        void setYSize(float ySize)
        {
            Entity::ySize = ySize;
        }
    };
}


#endif //SPACE_INVADERS_ENTITY_H
