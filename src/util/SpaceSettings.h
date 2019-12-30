/** \file SpaceSettings.h
* project: space_invaders
* author: Mano Marichal
* date: 02.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_SPACESETTINGS_H
#define SPACE_INVADERS_SPACESETTINGS_H

#include <cstdlib>
namespace util
{

    class SpaceSettings
    {
    public:
        static float xMax; /*!< max x value of our game logic */
        static float xMin; /*!< min x value of our game logic */
        static float yMax; /*!< max y value of our game logic */
        static float yMin; /*!< min y value of our game logic*/
        static float width; /*!< xMax - xMin */
        static float height; /*!< yMax - yMin */
    private:
        SpaceSettings()=default;
    public:
        SpaceSettings(const SpaceSettings &copy) = delete;
        SpaceSettings& operator=(SpaceSettings) = delete;
    };
}

#endif //SPACE_INVADERS_SPACESETTINGS_H
