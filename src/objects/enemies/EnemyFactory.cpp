// =====================================================================
// @name: EnemyFactory.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.01.20
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description:
// =====================================================================

#include "EnemyFactory.h"

#include "./green_alien/GreenAlienController.h"
#include "./purple_alien/PurpleAlienController.h"
#include "./red_alien/RedAlienController.h"

using namespace objects::enemies;

void EnemyFactory::createEnemy(float x, float y, objects::enemies::EnemyFactory::Type type, World& world)
{
        util::Object object;

        switch (type) {
        case RedAlien:
                object = EnemyFactory::createRedAlien(x, y, world);
                break;
        case GreenAlien:
                object = EnemyFactory::createGreenAlien(x, y, world);
                break;
        case PurpleAlien:
                object = EnemyFactory::createPurpleAlien(x, y, world);
                break;
        default:
                break;
        }

        world.addObject(std::move(object));
}

util::Object EnemyFactory::createGreenAlien(float x, float y, World& world)
{
        auto entity = std::make_shared<objects::enemies::green_alien::GreenAlien>(x, y);
        auto view = std::make_shared<objects::enemies::green_alien::GreenAlienView>(entity);
        auto controller = std::make_shared<objects::enemies::green_alien::GreenAlienController>(entity, view, (world));
        view->init();

        return std::make_tuple(std::move(entity), std::move(view), std::move(controller));
}

util::Object EnemyFactory::createPurpleAlien(float x, float y, World& world)
{
        auto entity = std::make_shared<objects::enemies::purple_alien::PurpleAlien>(x, y);
        auto view = std::make_shared<objects::enemies::purple_alien::PurpleAlienView>(entity);
        auto controller =
            std::make_shared<objects::enemies::purple_alien::PurpleAlienController>(entity, view, (world));
        view->init();

        return std::make_tuple(std::move(entity), std::move(view), std::move(controller));
}

util::Object EnemyFactory::createRedAlien(float x, float y, World& world)
{
        auto entity = std::make_shared<objects::enemies::red_alien::RedAlien>(x, y);
        auto view = std::make_shared<objects::enemies::red_alien::RedAlienView>(entity);
        auto controller = std::make_shared<objects::enemies::red_alien::RedAlienController>(entity, view, (world));
        view->init();

        return std::make_tuple(std::move(entity), std::move(view), std::move(controller));
}