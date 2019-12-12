// =====================================================================
// @name: CubeView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 12.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_CUBEVIEW_H
#define SPACE_INVADERS_CUBEVIEW_H

#include "../../abstract_classes/View.h"
#include "../../abstract_classes/Observer.h"
#include "./Cube.h"

namespace entities::enemies::cube
{
    class CubeView: public View
    {
    public:
        explicit CubeView(std::shared_ptr<Cube> Cube): View(std::string("../textures/greensquare.jpg"), Cube) {};
        void notify() override ;
        ~CubeView() override = default;
    };
}


#endif //SPACE_INVADERS_CUBEVIEW_H
