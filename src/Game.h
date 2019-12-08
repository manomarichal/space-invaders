// =====================================================================
// @name: Game.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <cassert>

#include "entities/abstract_classes/View.h"
#include "entities/abstract_classes/Entity.h"
#include "entities/abstract_classes/Controller.h"

#include "./entities/playership/PlayerShip.h"
#include "./entities/playership/PlayerShipView.h"
#include "./entities/playership/PlayerShipController.h"

#include "./entities/util/Object.h"

namespace entities
{
    class Entity;
}
class Game
{
private:
    std::unique_ptr<sf::RenderWindow> window;

    std::vector<std::shared_ptr<entities::Controller>> activeControllers;
    std::vector<std::shared_ptr<entities::View>> activeViews;
    std::vector<std::shared_ptr<entities::Entity>> activeEntities;
    std::vector<uint> objectsToDelete;

    bool isInitialized=false;
    void updateEntities();
    void handleEvents();
    void drawViews();
    void deleteObject(uint index);
public:
    Game();
    void addObject(entities::Object object);
    void startGame();
    ~Game();
};


#endif //SPACE_INVADERS_GAME_H
