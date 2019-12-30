
/** \file World.cpp
* project: space_invaders
* author: Mano Marichal
* date: 01.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */


#include "World.h"

#include <fstream>
#include <algorithm>

World::World(std::shared_ptr<sf::RenderWindow> windowPtr)
{
    enemiesToDefeat = -1;
    levelCompleted = false;
    running = false;
    score = 0;
    window = std::move(windowPtr);
}

void World::addObject(util::Object object)
{
    activeEntities.emplace_back(std::move(std::get<0>(object)));
    activeViews.emplace_back(std::move(std::get<1>(object)));
    activeControllers.emplace_back(std::move(std::get<2>(object)));
}

void World::deleteObject(uint index)
{
    if (std::dynamic_pointer_cast<entities::enemies::Enemy>(activeEntities[index]) != nullptr)
    {
        enemiesToDefeat--;
        score += 100;
    }

    if (enemiesToDefeat == 0)
    {
        running = false;
        levelCompleted = true;
    }

    activeEntities.erase(activeEntities.begin() + index);
    activeViews.erase(activeViews.begin() + index);
    activeControllers.erase(activeControllers.begin() + index);

    onNotifyObservers();
}

void World::updateEntities()
{
    for (auto &entity:activeEntities)
    {
        entity->update();
    }

    std::sort(objectsToDelete.begin(), objectsToDelete.end(), std::greater<>());
    for (auto i:objectsToDelete)
    {
        deleteObject(i);
    }

    objectsToDelete.clear();
}

void World::handleEvents()
{
    sf::Event event{};
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) exit(0);
    }

    uint index = 0;
    while (index < activeControllers.size())
    {
        if (!activeControllers[index]->handleEvents(activeEntities)) objectsToDelete.emplace_back(index);
        index++;
    }
}

void World::onNotify()
{
    running = player->hitpoints > 0;
}

void World::reset()
{
    activeEntities.clear();
    activeControllers.clear();
    activeViews.clear();

    running = false;
    levelCompleted = false;
    enemiesToDefeat = -1;
}

bool World::isRunning() const
{
    return running;
}

bool World::isLevelCompleted() const
{
    return levelCompleted;
}

World::~World()=default;

