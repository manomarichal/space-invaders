// =====================================================================
// @name: Hexagon.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 04.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Hexagon.h"
using namespace entities::enemies;
void Hexagon::move()
{
    y += vspeed;
}
