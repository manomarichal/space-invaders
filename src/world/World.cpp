// =====================================================================
// @name: World.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "World.h"

World::World(std::shared_ptr<sf::RenderWindow> windowPtr)
{
    enemiesDefeated = 0;
    enemiesToDefeat = 0;
    levelCompleted = false;
    running = false;
    score = 0;
    window = std::move(windowPtr);
}

void World::addObject(entities::Object object)
{
    activeEntities.emplace_back(std::move(std::get<0>(object)));
    activeViews.emplace_back(std::move(std::get<1>(object)));
    activeControllers.emplace_back(std::move(std::get<2>(object)));
}

void World::deleteObject(uint index)
{
    if (std::dynamic_pointer_cast<entities::enemies::Enemy>(activeEntities[index]) != nullptr)
    {
        enemiesDefeated++;
        score += 100;
    }

    if (enemiesDefeated == enemiesToDefeat)
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

void World::drawViews()
{
    window->clear(sf::Color::Black);
    for (auto &view:activeViews)
    {
        view->draw(*window);
    }
    drawScore();
    window->display();

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
    enemiesDefeated = 0;
}

void World::drawScore()
{
    sf::Font font;
    font.loadFromFile("../resources/fonts/pixeled.ttf");

    sf::Text string("Score: " + std::to_string(score), font, 32);
    string.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);
    string.setPosition(util::Transformation::getScreenWidth() - string.getGlobalBounds().width - 10, 10);

    window->draw(string);
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

