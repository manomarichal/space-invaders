// =====================================================================
// @name: ScoreCounter.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 16.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_SCORECOUNTER_H
#define SPACE_INVADERS_SCORECOUNTER_H

#include "../world/World.h"

class ScoreCounter: public entities::Observer
{
private:
    uint score;
    uint enemiesDefeated;
    std::shared_ptr<World> world;
public:
    explicit ScoreCounter(std::shared_ptr<World> world);

    void notify() override;

    [[nodiscard]] uint getScore() const;

    void setWorld(const std::shared_ptr<World> &world);

    ~ScoreCounter() override =default;
};


#endif //SPACE_INVADERS_SCORECOUNTER_H
