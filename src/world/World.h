/** \file World.h
* project: space_invaders
* author: Mano Marichal
* date: 01.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_WORLD_H
#define SPACE_INVADERS_WORLD_H

#include "../entities/playership/PlayerShipController.h"
#include "../util/Object.h"
#include "../util/Clock.h"

namespace entities::projectiles
{
    class ProjectileFactory;
}
class World: public entities::Observer, public entities::Subject
{
private:
    uint enemiesToDefeat;   /*!< the # of enemies we need to defeat to clear the currently loaded level */
    uint score;     /*!< our current score */

    bool levelCompleted;    /*!< true = we cleared the level */
    bool running;   /*!< if the world is currently running a level */

    std::shared_ptr<sf::RenderWindow> window;   /*!< the window the world needs to draw on */
    std::shared_ptr<entities::playership::PlayerShip> player;   /*!< the playership object */

    std::vector<std::shared_ptr<entities::Controller>> activeControllers;   /*!< all active controllers */
    std::vector<std::shared_ptr<entities::View>> activeViews;   /*!< all active views */
    std::vector<std::shared_ptr<entities::Entity>> activeEntities;  /*!< all active entities */
    std::vector<uint> objectsToDelete;  /*!< buffer where we save all entities that need to be deleted after the current tick */

    /**
     * resets the currently loaded level
     */
    void reset();
    /**
     * deletes an object
     * @param index: the index of the object in activeEntities, activeViews and activeControllers
     */
    void deleteObject(uint index);
    /**
     * adds an object
     * @param object: the object to be added
     */
    void addObject(util::Object object);
    /**
     * draws the current score on the screen
     */
    void drawScore();

public:
    /**
     * Constructor
     * @param windowPtr: the window where our world draws
     */
    explicit World(std::shared_ptr<sf::RenderWindow> windowPtr);
    /**
     * loads a level from a json file
     * @param filename: the level to be loaded
     */
    void loadLevel(const std::string &filename);
    /**
     * Observer notify functie
     */
    void onNotify() override;
    /**
     * lets all controllers in activeControllers handle events, also handles other sfml events
     */
    void handleEvents();
    /**
     * updates all entities in activeEntities
     */
    void updateEntities();
    /**
     * lets all views in activeViews draw their object
     */
    void drawViews();

    bool isLevelCompleted() const;
    bool isRunning() const;
    friend class entities::projectiles::ProjectileFactory;

    /**
     * Destructor
     */
    ~World() override;
};


#endif //SPACE_INVADERS_WORLD_H
