/** \file Collision.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 27.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "Collision.h"
#include "../objects/enemies/Enemy.h"
#include "../objects/playership/PlayerShip.h"
#include "../objects/projectiles/standard/StandardProjectile.h"
#include "../objects/projectiles/standard_enemy/StandardEnemyProjectile.h"
#include "../objects/shield/Shield.h"

using namespace util;

bool Collision::checkCollision(const objects::Entity& e1, const objects::Entity& e2)
{
        return e1.getX() - e1.getXSize() / 2 < e2.getX() + e2.getXSize() / 2 &&
               e1.getX() + e1.getXSize() / 2 > e2.getX() - e2.getXSize() / 2 &&
               e1.getY() + e1.getYSize() / 2 > e2.getY() - e2.getYSize() / 2 &&
               e1.getY() - e1.getYSize() / 2 < e2.getY() + e2.getYSize() / 2;
}
bool Collision::shield(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2)
{
        if (std::dynamic_pointer_cast<objects::shield::Shield>(e2) == nullptr)
                return false;
        return checkCollision(e1, *e2.get());
}
bool Collision::enemy(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2)
{
        if (std::dynamic_pointer_cast<objects::enemies::Enemy>(e2) == nullptr)
                return false;
        return checkCollision(e1, *e2.get());
}
bool Collision::playership(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2)
{
        if (std::dynamic_pointer_cast<objects::playership::PlayerShip>(e2) == nullptr)
                return false;
        return checkCollision(e1, *e2.get());
}
bool Collision::standardProjectile(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2)
{
        if (std::dynamic_pointer_cast<objects::projectiles::standard::StandardProjectile>(e2) == nullptr)
                return false;
        return checkCollision(e1, *e2.get());
}
bool Collision::standardEnemyProjectile(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2)
{
        if (std::dynamic_pointer_cast<objects::projectiles::standard_enemy::StandardEnemyProjectile>(e2) == nullptr)
                return false;
        return checkCollision(e1, *e2.get());
}