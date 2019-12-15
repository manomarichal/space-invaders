// =====================================================================
// @name: Loader.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Loader.h"
void Loader::loadLevel(World &world, std::string filename)
{
    world.activeEntities.reserve(50);
    world.activeViews.reserve(50);
    world.activeControllers.reserve(50);
    world.objectsToDelete.reserve(50);

    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + filename);
    nlohmann::json root;
    file >> root;

    // PLAYERSHIP
    float x  = root["Playership"]["x"];
    float y = root["Playership"]["y"];
    if (x < 0 or x > 1178) throw std::runtime_error("invalid x value for Playership in file: " + filename + "\nx value for playerShip must be bigger than 0 and smaller than 1178");
    if (y < 0 or y > 878) throw std::runtime_error("invalid y value for Playership in file: " + filename + "\nx value for playerShip must be bigger than 0 and smaller than 878");
    auto playership = std::make_shared<entities::playership::PlayerShip>(x,y);
    world.player = playership;
    playership->subscribe(dynamic_cast<entities::Observer*>(&world));
    auto playershipView = std::make_shared<entities::playership::PlayerShipView>(playership);
    auto playershipController = std::make_shared<entities::playership::PlayerShipController>(playership, playershipView, world);
    world.addObject(std::make_tuple(std::move(playership), std::move(playershipView), std::move(playershipController)));


    // ENEMIES
    for (auto enemy:root["Enemies"])
    {
        if (enemy["type"] == "PurpleAlien")
        {
            auto projectile = std::make_shared<entities::enemies::purple_alien::PurpleAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::purple_alien::PurpleAlienView>(projectile);
            auto controller = std::make_shared<entities::enemies::purple_alien::PurpleAlienController>(projectile, view, world);

            world.addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }
        else if (enemy["type"] == "GreenAlien")
        {
            auto projectile = std::make_shared<entities::enemies::green_alien::GreenAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::green_alien::GreenAlienView>(projectile);
            auto controller = std::make_shared<entities::enemies::green_alien::GreenAlienController>(projectile, view, world);

            world.addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }
        else if (enemy["type"] == "RedAlien")
        {
            auto projectile = std::make_shared<entities::enemies::red_alien::RedAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::red_alien::RedAlienView>(projectile);
            auto controller = std::make_shared<entities::enemies::red_alien::RedAlienController>(projectile, view, world);

            world.addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }
        else
        {
            throw std::runtime_error("unknow enemy type: " + std::string(enemy["type"]) + " in file: " + filename);
        }
    }
}