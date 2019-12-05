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

#include "./entities/View.h"
#include "./entities/Entity.h"
#include "./entities/Controller.h"


#include "./entities/playership/PlayerShip.h"
#include "./entities/playership/PlayerShipView.h"
#include "./entities/playership/PlayerShipController.h"
namespace entities
{
    class Entity;
}
class Game
{
private:
    std::vector<std::shared_ptr<entities::Controller>> activeControllers;
    std::vector<std::shared_ptr<entities::View>> activeViews;
    std::vector<std::shared_ptr<entities::Entity>> activeEntities;

    bool isInitialized=false;
    sf::RenderWindow* window;
    void updateEntities();
    void handleEvents();
    void drawViews();
public:
    void initializeGame();
    void startGame();
    ~Game();
};


#endif //SPACE_INVADERS_GAME_H
