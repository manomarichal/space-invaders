// =====================================================================
// @name: World.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_WORLD_H
#define SPACE_INVADERS_WORLD_H

#include <unistd.h>
#include <fstream>
#include <algorithm>

#include "../entities/playership/PlayerShipController.h"
#include "../entities/enemies/green_alien/GreenAlienController.h"
#include "../entities/enemies/purple_alien/PurpleAlienController.h"
#include "../entities/enemies/red_alien/RedAlienController.h"
#include "../json/json.hpp"
#include "../util/Object.h"
#include "../util/Clock.h"

namespace entities::projectiles
{
    class ProjectileFactory;
}
class World: public entities::Observer, public entities::Subject
{
private:
    uint enemiesDefeated;
    uint enemiesToDefeat;
    uint score;
    bool levelCompleted;

    bool running;

    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<entities::playership::PlayerShip> player;

    std::vector<std::shared_ptr<entities::Controller>> activeControllers;
    std::vector<std::shared_ptr<entities::View>> activeViews;
    std::vector<std::shared_ptr<entities::Entity>> activeEntities;
    std::vector<uint> objectsToDelete;

    void reset();
    void deleteObject(uint index);
    void addObject(entities::Object object);
    void drawScore();

public:
    explicit World(std::shared_ptr<sf::RenderWindow> windowPtr);

    bool isLevelCompleted() const;
    bool isRunning() const;

    void loadLevel(const std::string &filename);
    void onNotify() override;
    void handleEvents();
    void updateEntities();
    void drawViews();

    friend class entities::projectiles::ProjectileFactory;

    ~World() override;
};


#endif //SPACE_INVADERS_WORLD_H
