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
#include "./entities/Entity.h"
#include "./entities/playership/PlayerShip.h"
#include "./entities/Controller.h"

class Game
{
private:
    std::vector<Controller*> controllers;
    bool isInitialized=false;
    sf::RenderWindow * window;
    void updateControllers();
    void handleEvents();
    void drawViews();
public:
    void initializeGame();
    void startGame();
    ~Game();
};


#endif //SPACE_INVADERS_GAME_H
