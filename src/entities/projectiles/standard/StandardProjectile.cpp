// =====================================================================
// @name: StandardProjectile.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 02.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardProjectile.h"
bool projectiles::StandardProjectile::move()
{
    y -= vspeed;
    return y < 0;
}
