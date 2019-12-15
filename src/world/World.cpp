// =====================================================================
// @name: World.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "World.h"

World::World(const std::string &settings)
{
    std::ifstream file(settings);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + settings);
    nlohmann::json root;
    file >> root;

    uint width = root["Screen"]["width"];
    uint height = root["Screen"]["height"];
    entities::Transformation::setScreenWidth(width);
    entities::Transformation::setScreenHeight(height);

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "Space Invaders");
}

void World::addObject(entities::Object object)
{
    activeEntities.emplace_back(std::move(std::get<0>(object)));
    activeViews.emplace_back(std::move(std::get<1>(object)));
    activeControllers.emplace_back(std::move(std::get<2>(object)));
}

void World::deleteObject(uint index)
{
    activeEntities.erase(activeEntities.begin() + index);
    activeViews.erase(activeViews.begin() + index);
    activeControllers.erase(activeControllers.begin() + index);
}

void World::updateEntities()
{
    for (auto &entity:activeEntities)
    {
        entity->update();
    }
}

void World::handleEvents()
{
    sf::Event event{};
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window->close();
                exit(0);
                break;
            default:
                break;
        }
    }

    uint index = 0;

    while (index < activeControllers.size())
    {
        if (!activeControllers[index]->handleEvents(activeEntities)) objectsToDelete.emplace_back(index);
        index++;
    }

    for (auto i:objectsToDelete)
    {
        deleteObject(i);
    }
    objectsToDelete.clear();
}

void World::drawViews()
{
    window->clear(sf::Color::Black);
    for (auto &view:activeViews)
    {
        view->draw(*window);
    }
    window->display();

}

void World::start()
{
    Stopwatch stopwatch(8);
    worldIsRunning = true;
    while (worldIsRunning)
    {
        handleEvents();
        updateEntities();
        drawViews();
        while (!stopwatch.isReady()) {usleep(5000);};
    }
}

void World::notify()
{
    worldIsRunning = player->hitpoints > 0;
}

void World::reset()
{
    activeControllers.clear();
    activeViews.clear();
    activeEntities.clear();
    player.reset();
}

World::~World()=default;

