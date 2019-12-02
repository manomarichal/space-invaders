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

class PlayerShip: public Entity
{
private:
    double vx;  // horizontal velocity
    double ax = 3.5;
    const double max_v = 20; // max horizontal velocity
    const double friction = 0.96;
    double x;
    double y;
    unsigned int xSize;
    int ySize;

public:
    PlayerShip();

    void moveLeft();
    void moveRight();
    void move();

    // getters & setters
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    void setXSize(unsigned int xSize);

    void setYSize(int ySize);

    ~PlayerShip() override = default;
};


#endif //SPACE_INVADERS_PLAYERSHIP_H
