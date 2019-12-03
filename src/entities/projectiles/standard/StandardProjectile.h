// =====================================================================
// @name: StandardProjectile.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 03.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STANDARDPROJECTILE_H
#define SPACE_INVADERS_STANDARDPROJECTILE_H

#include "../Projectile.h"

namespace entities::projectiles
{
    class StandardProjectile: public Projectile
    {
        int vspeed = 50;
    public:
        StandardProjectile(int x, int y): Projectile(x, y){} ;
        bool move() override ;
    };

    class StandardProjectileView: public ProjectileView
    {
    private:
        sf::Sprite* sprite;
        sf::Texture* texture;
    public:
        explicit StandardProjectileView(StandardProjectile* projectile);
        void draw(sf::RenderWindow &window) const override;
        ~StandardProjectileView() override;
    };
}



#endif //SPACE_INVADERS_STANDARDPROJECTILE_H
