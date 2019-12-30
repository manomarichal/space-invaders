/** \file WorldLoader.cpp
* project: space_invaders
* author: Mano Marichal
* date: 27.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "World.h"
#include "../objects/enemies/green_alien/GreenAlienController.h"
#include "../objects/enemies/purple_alien/PurpleAlienController.h"
#include "../objects/enemies/red_alien/RedAlienController.h"
#include "../objects/shield/ShieldController.h"
#include "../objects/shield/ShieldView.h"
#include "../objects/shield/Shield.h"
#include "../json/json.hpp"

#include <fstream>

void World::loadLevel(const std::string &filename)
{
    reset();

    activeEntities.reserve(50);
    activeViews.reserve(50);
    activeControllers.reserve(50);
    objectssToDelete.reserve(50);

    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + filename);
    nlohmann::json root;
    file >> root;

    util::SpaceSettings::xMax = root["Space"]["xmax"];
    util::SpaceSettings::xMin = root["Space"]["xmin"];
    util::SpaceSettings::yMax = root["Space"]["ymax"];
    util::SpaceSettings::yMin = root["Space"]["ymin"];
    util::SpaceSettings::width = std::abs(util::SpaceSettings::xMax) + std::abs(util::SpaceSettings::xMin);
    util::SpaceSettings::height = std::abs(util::SpaceSettings::yMax) + std::abs(util::SpaceSettings::yMin);

    float x  = root["Playership"]["x"];
    float y = root["Playership"]["y"];
    auto playership = std::make_shared<objects::playership::PlayerShip>(x,y);
    player = playership;

    playership->attach(shared_from_this());

    auto playershipView = std::make_shared<objects::playership::PlayerShipView>
(playership);
    playershipView->init();
    auto playershipController = std::make_shared<objects::playership::PlayerShipController>(playership, playershipView, (*this));
    addObject(std::make_tuple(std::move(playership), std::move(playershipView), std::move(playershipController)));


    enemiesToDefeat = 0;
    for (auto enemy:root["Enemies"])
    {
        enemiesToDefeat++;
        if (enemy["type"] == "PurpleAlien")
        {
            auto entity = std::make_shared<objects::enemies::purple_alien::PurpleAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<objects::enemies::purple_alien::PurpleAlienView>(entity);
            auto controller = std::make_shared<objects::enemies::purple_alien::PurpleAlienController>(entity, view, (*this));
            view->init();
            addObject(std::make_tuple(std::move(entity), std::move(view), std::move(controller)));
        }
        else if (enemy["type"] == "GreenAlien")
        {
            auto entity = std::make_shared<objects::enemies::green_alien::GreenAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<objects::enemies::green_alien::GreenAlienView>(entity);
            auto controller = std::make_shared<objects::enemies::green_alien::GreenAlienController>(entity, view, (*this));
            view->init();
            addObject(std::make_tuple(std::move(entity), std::move(view), std::move(controller)));
        }
        else if (enemy["type"] == "RedAlien")
        {
            auto entity = std::make_shared<objects::enemies::red_alien::RedAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<objects::enemies::red_alien::RedAlienView>(entity);
            auto controller = std::make_shared<objects::enemies::red_alien::RedAlienController>(entity, view, (*this));
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
        auto entity = std::make_shared<objects::shield::Shield>(shield["x"], shield["y"]);
        auto view = std::make_shared<objects::shield::ShieldView>(entity);
        auto controller = std::make_shared<objects::shield::ShieldController>(entity, view, (*this));
        view->init();
        addObject(std::make_tuple(std::move(entity), std::move(view), std::move(controller)));
    }
    running = true;
}