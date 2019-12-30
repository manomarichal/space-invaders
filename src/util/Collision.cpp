
/** \file Collision.cpp
* project: space_invaders
* author: Mano Marichal
* date: 27.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */


#include "Collision.h"
#include "../entities/enemies/Enemy.h"
#include "../entities/shield/Shield.h"
#include "../entities/playership/PlayerShip.h"
#include "../entities/projectiles/standard/StandardProjectile.h"
#include "../entities/projectiles/standard_enemy/StandardEnemyProjectile.h"


using namespace util;

bool Collision::checkCollision(const entities::Entity &e1, const entities::Entity &e2)
{
    return e1.getX() - e1.getXSize()/2 < e2.getX() + e2.getXSize()/2 &&
           e1.getX() + e1.getXSize()/2 > e2.getX() - e2.getXSize()/2 &&
           e1.getY() + e1.getYSize()/2 > e2.getY() - e2.getYSize()/2 &&
           e1.getY() - e1.getYSize()/2 < e2.getY() + e2.getYSize()/2;
}
bool Collision::shield(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2)
{
    if (std::dynamic_pointer_cast<entities::shield::Shield>(e2) == nullptr) return false;
    return checkCollision(e1, *e2.get());
}
bool Collision::enemy(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2)
{
    if (std::dynamic_pointer_cast<entities::enemies::Enemy>(e2) == nullptr) return false;
    return checkCollision(e1, *e2.get());
}
bool Collision::playership(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2)
{
    if (std::dynamic_pointer_cast<entities::playership::PlayerShip>(e2) == nullptr) return false;
    return checkCollision(e1, *e2.get());
}
bool Collision::standardProjectile(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2)
{
    if (std::dynamic_pointer_cast<entities::projectiles::standard::StandardProjectile>(e2) == nullptr) return false;
    return checkCollision(e1, *e2.get());
}
bool Collision::standardEnemyProjectile(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2)
{
    if (std::dynamic_pointer_cast<entities::projectiles::standard_enemy::StandardEnemyProjectile>(e2) == nullptr) return false;
    return checkCollision(e1, *e2.get());
}