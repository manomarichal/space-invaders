// =====================================================================
// @name: Object.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_OBJECT_H
#define SPACE_INVADERS_OBJECT_H

#include <tuple>
#include "../entities/abstract_classes/Entity.h"
#include "../entities/abstract_classes/View.h"
#include "../entities/abstract_classes/Controller.h"

namespace entities
{
    using Object = std::tuple<
    std::shared_ptr<entities::Entity>,
    std::shared_ptr<entities::View>,
    std::shared_ptr<entities::Controller>>;
}
#endif //SPACE_INVADERS_OBJECT_H
