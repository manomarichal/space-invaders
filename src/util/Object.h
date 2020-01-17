/** \file Object.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 08.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_OBJECT_H
#define SPACE_INVADERS_OBJECT_H

#include "../objects/abstract_classes/Controller.h"
#include "../objects/abstract_classes/Entity.h"
#include "../objects/abstract_classes/View.h"
#include <tuple>

namespace util {
using Object =
    std::tuple<std::shared_ptr<objects::Entity>, std::shared_ptr<objects::View>, std::shared_ptr<objects::Controller>>;
}
#endif // SPACE_INVADERS_OBJECT_H
