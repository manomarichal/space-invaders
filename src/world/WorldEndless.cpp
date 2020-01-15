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
    if (spawnLocations.size() == 6) spawnLocations.clear(); // all spawn locations are used
    enemiesToDefeat++;
    uint x = 0;
    while (x < 2 or x > 8 or std::find(spawnLocations.begin(), spawnLocations.end(), x) != spawnLocations.end()) x = rand()%10;
    spawnLocations.emplace_back(x);
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
    objects::enemies::EnemyFactory::createEnemy(util::SpaceSettings::xMin + (util::SpaceSettings::width * (float(x)/10)) , util::SpaceSettings::yMax-(util::SpaceSettings::height/8), eType, *this);
    if (endlessStopwatch->getDuration() > 300)
    {
        endlessStopwatch->setDuration(endlessStopwatch->getDuration()-50);

    }
}