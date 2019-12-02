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

#include "View.h"

class Entity
{
public:
    virtual ~Entity()=0;
};
inline Entity::~Entity()=default;


#endif //SPACE_INVADERS_ENTITY_H
