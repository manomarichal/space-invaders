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
#include <unistd.h>

#include "../entities/abstract_classes/Controller.h"

#include "../util/Object.h"
#include "../util/Stopwatch.h"
#include "../util/Transformation.h"


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

    void handleEvents();
    void updateEntities();
    void drawViews();
    void deleteObject(uint index);

public:
    Game();
    void addObject(entities::Object object);
    void startGame();

    friend class Loader;
    ~Game();
};


#endif //SPACE_INVADERS_GAME_H
