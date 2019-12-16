// =====================================================================
// @name: Game.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 15.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

#include "../world/World.h"

class Game
{
private:
    std::shared_ptr<sf::RenderWindow> window;
    std::vector<std::string> levels;
    bool gameOver();
    void newLevel();
    void checkEvents();
public:
    Game(const std::string &settings, std::vector<std::string> levels);
    void play();
};


#endif //SPACE_INVADERS_GAME_H
