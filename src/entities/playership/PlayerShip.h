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

#include "../projectiles/ProjectileController.h"

class PlayerShip: public Entity
{
private:
    double vx=0;  // horizontal velocity
    double ax = 6;
    const double max_v = 30; // max horizontal velocity
    const double friction = 0.90;


public:
    PlayerShip();

    double x;
    double y;
    unsigned int xSize = 64;
    int ySize;

    void moveLeft();
    void moveRight();
    void move();

    ~PlayerShip() override = default;
};

class PlayerShipView: public View
{
private:
    sf::Sprite* sprite;
    sf::Texture* texture;
public:
    PlayerShipView();

    PlayerShip* object;

    void draw(sf::RenderWindow &window) override;

    ~PlayerShipView() override;
};

class PlayerShipController: public Controller
{
    PlayerShipView* view;
    projectiles::ProjectileController * projectileController;

public:
    PlayerShipController();

    void update(sf::RenderWindow &window) override ;

    ~PlayerShipController() override;
};
#endif //SPACE_INVADERS_PLAYERSHIP_H
