// =====================================================================
// @name: LevelLoader.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "LevelLoader.h"
void LevelLoader::loadLevel(Game &game, std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + filename);
    nlohmann::json root;
    file >> root;

    for (auto enemy:root["Enemies"])
    {
        if (enemy["type"] == "PurpleAlien")
        {
            auto projectile = std::make_shared<entities::enemies::purple_alien::PurpleAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::purple_alien::PurpleAlienView>(projectile);
            auto controller = std::make_shared<entities::enemies::purple_alien::PurpleAlienController>(projectile, view, game);

            game.addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }

        if (enemy["type"] == "GreenAlien")
        {
            auto projectile = std::make_shared<entities::enemies::green_alien::GreenAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::green_alien::GreenAlienView>(projectile);
            auto controller = std::make_shared<entities::enemies::green_alien::GreenAlienController>(projectile, view, game);

            game.addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }

        if (enemy["type"] == "RedAlien")
        {
            auto projectile = std::make_shared<entities::enemies::red_alien::RedAlien>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::red_alien::RedAlienView>(projectile);
            auto controller = std::make_shared<entities::enemies::red_alien::RedAlienController>(projectile, view, game);

            game.addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }
    }
}