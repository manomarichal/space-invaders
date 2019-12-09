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
    enum Type {standardprojectile, hexagon, mushroom, playership};

    class Entity
    {
    protected:
        float x;
        float y;
        Type type;
        unsigned int xSize;
        unsigned int ySize;
    public:
        Entity(float x, float y, Type type): x(x), y(y), type(type) {};

        virtual ~Entity()=0;

        [[nodiscard]] float getX() const
        {
            return x;
        }

        [[nodiscard]] float getY() const
        {
            return y;
        }

        [[nodiscard]] unsigned int getXSize() const
        {
            return xSize;
        }

        [[nodiscard]] unsigned int getYSize() const
        {
            return ySize;
        }

        [[nodiscard]] Type getType() const
        {
            return type;
        }
    };
    inline Entity::~Entity()=default;
}


#endif //SPACE_INVADERS_ENTITY_H
