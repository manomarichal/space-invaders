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

namespace entities
{
    class Entity
    {
    protected:
        float x;
        float y;
    public:
        Entity(int x, int y): x(x), y(y) {};
        virtual void update()=0;
        virtual ~Entity()=0;

        [[nodiscard]] float getX() const
        {
            return x;
        }

        [[nodiscard]] float getY() const
        {
            return y;
        }
    };
    inline Entity::~Entity()=default;
}


#endif //SPACE_INVADERS_ENTITY_H
