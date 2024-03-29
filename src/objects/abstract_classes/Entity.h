/** \file Entity.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 17.11.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_ENTITY_H
#define SPACE_INVADERS_ENTITY_H

#include <iostream>
#include <memory>
#include <utility>

#include "../../util/SpaceSettings.h"
#include "Subject.h"

namespace objects {
class Entity : public Subject
{
protected:
        float x;
        float y;
        float xSize{};
        float ySize{};

public:
        Entity(float x, float y) : x(x), y(y){};
        /**
         * in this function, we can specify actions entities should undertake regarding of what controller is
         * controlling it the function is called each interval
         */
        virtual void update() = 0;
        ~Entity() override = default;

        [[nodiscard]] float getX() const { return x; }

            [[nodiscard]] float getY() const
        {
                return y;
        }

        [[nodiscard]] float getXSize() const { return xSize; }

            [[nodiscard]] float getYSize() const
        {
                return ySize;
        }
};
} // namespace objects

#endif // SPACE_INVADERS_ENTITY_H
