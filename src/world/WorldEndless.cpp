// =====================================================================
// @name: WorldEndless.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 31.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "./World.h"
#include "../objects/enemies/EnemyFactory.h"


void World::enterEndless()
{
    loadLevel("../resources/levels/level_endless_base.json");
    running = true;
    endless = true;
    enemiesToDefeat = 1;
    endlessStopwatch = std::make_unique<util::Stopwatch>(2000);
}

void World::createRandomEnemy()
{
    if (!endless) throw std::runtime_error("world may not create enemies if it is not in endless mode");

    enemiesToDefeat++;
    float x = util::SpaceSettings::width/float(rand()%10);

    int type = rand()%5;
    objects::enemies::EnemyFactory::Type eType;

    switch (type)
    {
        case 0:
            eType = objects::enemies::EnemyFactory::GreenAlien;
            break;
        case 1:
            eType = objects::enemies::EnemyFactory::PurpleAlien;
            break;
        default:
            eType = objects::enemies::EnemyFactory::RedAlien;
    }
    objects::enemies::EnemyFactory::createEnemy(util::SpaceSettings::xMin + util::SpaceSettings::width/x, util::SpaceSettings::yMax-(util::SpaceSettings::height/8), eType, *this);
    long duration = endlessStopwatch->getDuration()-25;
    if (duration < 300) endlessStopwatch->setDuration(300);
}