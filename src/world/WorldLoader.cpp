// =====================================================================
// @name: WorldLoader.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 27.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "World.h"
#include "../entities/enemies/green_alien/GreenAlienController.h"
#include "../entities/enemies/purple_alien/PurpleAlienController.h"
#include "../entities/enemies/red_alien/RedAlienController.h"
#include "../entities/shield/ShieldController.h"
#include "../entities/shield/ShieldView.h"
#include "../entities/shield/Shield.h"
#include "../json/json.hpp"

void World::loadLevel(const std::string &filename)
{
    reset();

    activeEntities.reserve(50);
    activeViews.reserve(50);
    activeControllers.reserve(50);
    objectsToDelete.reserve(50);

    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + filename);
    nlohmann::json root;
    file >> root;

    // COORDINATES
    screensize::xMax = root["Space"]["xmax"];
    screensize::xMin = root["Space"]["xmin"];
    screensize::yMax = root["Space"]["ymax"];
    screensize::yMin = root["Space"]["ymin"];
    screensize::width = std::abs(screensize::xMax) + std::abs(screensize::xMin);
    screensize::height = std::abs(screensize::yMax) + std::abs(screensize::yMin);

    // PLAYERSHIP
    float x  = root["Playership"]["x"];
    float y = root["Playership"]["y"];
    auto playership = std::make_shared<entities::playership::PlayerShip>(x,y);
    player = playership;

    playership->attach(shared_from_this());

    auto playershipView = std::make_shared<entities::playership::PlayerShipView>(playership);
    playershipView->init();
    auto playershipController = std::make_shared<entities::playership::PlayerShipController>(playership, playershipView, (*this));
    addObject(std::make_tuple(std::move(playership), std::move(playershipView), std::move(playershipController)));


    // ENEMIES
    enemiesToDefeat = 0;
    for (auto enemy:root["Enemies"])
    {
        enemiesToDefeat++;
        if (enemy["type"] == "PurpleAlien")
        {
            auto entity = std::make_shared<entities::enemies::purple_alien::PurpleAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::purple_alien::PurpleAlienView>(entity);
            auto controller = std::make_shared<entities::enemies::purple_alien::PurpleAlienController>(entity, view, (*this));
            view->init();
            addObject(std::make_tuple(std::move(entity), std::move(view), std::move(controller)));
        }
        else if (enemy["type"] == "GreenAlien")
        {
            auto entity = std::make_shared<entities::enemies::green_alien::GreenAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::green_alien::GreenAlienView>(entity);
            auto controller = std::make_shared<entities::enemies::green_alien::GreenAlienController>(entity, view, (*this));
            view->init();
            addObject(std::make_tuple(std::move(entity), std::move(view), std::move(controller)));
        }
        else if (enemy["type"] == "RedAlien")
        {
            auto entity = std::make_shared<entities::enemies::red_alien::RedAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::red_alien::RedAlienView>(entity);
            auto controller = std::make_shared<entities::enemies::red_alien::RedAlienController>(entity, view, (*this));
            view->init();
            addObject(std::make_tuple(std::move(entity), std::move(view), std::move(controller)));
        }
        else
        {
            throw std::runtime_error("unknow enemy type: " + std::string(enemy["type"]) + " in file: " + filename);
        }
    }

    for (auto shield:root["Shields"])
    {
        auto entity = std::make_shared<entities::shield::Shield>(shield["x"], shield["y"]);
        auto view = std::make_shared<entities::shield::ShieldView>(entity);
        auto controller = std::make_shared<entities::shield::ShieldController>(entity, view, (*this));
        view->init();
        addObject(std::make_tuple(std::move(entity), std::move(view), std::move(controller)));
    }
    running = true;
}