// =====================================================================
// @name: ScoreCounter.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 16.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "ScoreCounter.h"

ScoreCounter::ScoreCounter(std::shared_ptr<World> world)
{
    dynamic_cast<entities::Subject*>(world.get())->subscribe(dynamic_cast<entities::Observer*>(this));

    score = 0;
    enemiesDefeated = 0;
    this->world = std::move(world);
}

void ScoreCounter::notify()
{
    if (enemiesDefeated < world->getEnemiesDefeated())
    {
        score += 10;
    }
    if (world->isLevelCompleted())
    {
        enemiesDefeated = 0;
        world.reset();
    }
}

uint ScoreCounter::getScore() const
{
    return score;
}

void ScoreCounter::setWorld(const std::shared_ptr<World> &world)
{
    ScoreCounter::world = world;
}
