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

#include "../entities/playership/PlayerShipController.h"
#include "../json/json.hpp"
#include "../util/Object.h"
#include "../util/Stopwatch.h"
#include "../util/Transformation.h"

class World: public entities::Observer
{
private:
    bool worldIsRunning = true;

    std::unique_ptr<sf::RenderWindow> window;
    std::shared_ptr<entities::playership::PlayerShip> player;
    std::vector<std::shared_ptr<entities::Controller>> activeControllers;
    std::vector<std::shared_ptr<entities::View>> activeViews;
    std::vector<std::shared_ptr<entities::Entity>> activeEntities;
    std::vector<uint> objectsToDelete;

    void handleEvents();
    void updateEntities();
    void drawViews();
    void deleteObject(uint index);
    void addObject(entities::Object object);

public:
    World(const std::string &settings);
    void notify() override;
    void start();
    void reset();
    friend class entities::projectiles::ProjectileFactory;
    friend class Loader;
    ~World();
};


#endif //SPACE_INVADERS_WORLD_H
