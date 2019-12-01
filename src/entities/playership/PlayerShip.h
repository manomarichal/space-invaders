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
    double hspeed;
    double vspeed;
    double x;
    double y;
public:

    PlayerShip()= default;

    void moveLeft();
    void moveRight();

    // getters & setters
    double getHspeed() const;

    void setHspeed(double hspeed);

    double getVspeed() const;

    void setVspeed(double vspeed);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);


    ~PlayerShip() override = default;
};


#endif //SPACE_INVADERS_PLAYERSHIP_H
