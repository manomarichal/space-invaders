// =====================================================================
// @name: LevelLoader.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "LevelLoader.h"
void LevelLoader::loadLevel(Game *game, std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + filename);
    nlohmann::json root;
    file >> root;

    for (auto enemy:root["Enemies"])
    {
        if (enemy["type"] == "Hexagon")
        {
            auto projectile = std::make_shared<entities::enemies::hexagon::Hexagon>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::hexagon::HexagonView>(projectile);
            auto controller = std::make_shared<entities::enemies::hexagon::HexagonController>(projectile, view, game);

            game->addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }

        if (enemy["type"] == "Pentagon")
        {
            auto projectile = std::make_shared<entities::enemies::pentagon::Pentagon>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::pentagon::PentagonView>(projectile);
            auto controller = std::make_shared<entities::enemies::pentagon::PentagonController>(projectile, view, game);

            game->addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }
    }
}