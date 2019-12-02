// =====================================================================
// @name: PlayerShip.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PLAYERSHIP_H
#define SPACE_INVADERS_PLAYERSHIP_H

#include "../Entity.h"
#include "../Controller.h"
#include "../View.h"
#include "../../util/Position.h"

#include "../projectiles/ProjectileController.h"

namespace entities
{
    class PlayerShip: public Entity
    {
    private:
        double vx=0;  // horizontal velocity
        double ax = 6;
        const double max_v = 30; // max horizontal velocity
        const double friction = 0.90;

    public:
        double x;
        double y;
        unsigned int xSize = 64;
        int ySize;

        void moveLeft();
        void moveRight();
        void move();

        PlayerShip();
        ~PlayerShip() override;
    };

    class PlayerShipView: public View
    {
    public: enum Sprite {left, right, idle};
    private:
        PlayerShip * object;
        sf::Sprite* sprite;
        sf::Texture* texture;
    public:

        Sprite currentSprite = idle;

        PlayerShipView(PlayerShip* ship);

        void draw(sf::RenderWindow &window) override;

        ~PlayerShipView() override;
    };

    class PlayerShipController: public Controller
    {
        PlayerShip * object;
        PlayerShipView* view;
        projectiles::ProjectileController * projectileController;

    public:
        PlayerShipController();

        void update() override ;
        void draw(sf::RenderWindow &window) override ;

        ~PlayerShipController() override;
    };
}

#endif //SPACE_INVADERS_PLAYERSHIP_H
