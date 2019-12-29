
/** \file Game.h
/// project: space_invaders
/// author: Mano Marichal
/// date: 15.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

#include "../world/World.h"

class Game
{
private:
    std::shared_ptr<sf::RenderWindow> window;   /*!< the window that the game draws on */
    std::vector<std::string> levels;    /*!< the file locations of all levels that need to be played */

    /**
     * displays a game over screen, pausing the game
     * @return if the player decided to start over again, or quit
     */
    bool gameOverScreen();
    /**
     * displays a new level screen
     */
    void newLevelScreen();
    /**
     * handle SFML events
     */
    void checkEvents();
    /**
     * runs the current world, which means starting the level that is loaded in our world
     * @param world
     */
    static void runWorld (World &world);

public:
    explicit Game(const std::string &settings);
    /**
     * starts playing all the levels loaded in this->levels
     */
    void play();
};


#endif //SPACE_INVADERS_GAME_H
