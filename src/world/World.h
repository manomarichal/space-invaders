/** \file World.h
* project: space_invaders
* author: Mano Marichal
* date: 01.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_WORLD_H
#define SPACE_INVADERS_WORLD_H

#include "../objects/playership/PlayerShipController.h"
#include "../util/Object.h"
#include "../util/Clock.h"

namespace objects::projectiles
{
    class ProjectileFactory;
}
class World: public objects::Observer
{
private:
    uint enemiesToDefeat;   /*!< the # of enemies we need to defeat to clear the currently loaded level */
    uint score;     /*!< our current score */

    bool levelCompleted;    /*!< true = we cleared the level */
    bool running;   /*!< if the world is currently running a level */

    std::shared_ptr<sf::RenderWindow> window;   /*!< the window the world needs to draw on */
    std::shared_ptr<objects::playership::PlayerShip> player;   /*!< the playership objects */

    std::vector<std::shared_ptr<objects::Controller>> activeControllers;   /*!< all active controllers */
    std::vector<std::shared_ptr<objects::View>> activeViews;   /*!< all active views */
    std::vector<std::shared_ptr<objects::Entity>> activeEntities;  /*!< all active objects */
    std::vector<uint> objectssToDelete;  /*!< buffer where we save all objects that need to be deleted after the current tick */

    /**
     * resets the currently loaded level
     */
    void reset();
    /**
     * deletes an objects
     * @param index: the index of the objects in activeEntities, activeViews and activeControllers
     */
    void deleteObject(uint index);
    /**
     * adds an objects
     * @param objects: the objects to be added
     */
    void addObject(util::Object objects);
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
     * updates all objects in activeEntities
     */
    void updateEntities();
    /**
     * lets all views in activeViews draw their objects
     */
    void drawViews();

    bool isLevelCompleted() const;
    bool isRunning() const;
    friend class objects::projectiles::ProjectileFactory;

    /**
     * Destructor
     */
    ~World() override;
};


#endif //SPACE_INVADERS_WORLD_H
