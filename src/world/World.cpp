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
    reset();
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
    if (dynamic_cast<entities::enemies::Enemy*>(activeEntities[index].get()) != nullptr)
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

    notifyObservers();
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

void World::notify()
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
    font.loadFromFile("../fonts/pixeled.ttf");

    sf::Text string("Score: " + std::to_string(score), font, 32);
    string.setPosition(float(entities::Transformation::getScreenWidth()) - string.getGlobalBounds().width - 10, 10);
    window->draw(string);
}

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

    // PLAYERSHIP
    float x  = root["Playership"]["x"];
    float y = root["Playership"]["y"];
    if (x < 0 or x > 1178) throw std::runtime_error("invalid x value for Playership in file: " + filename + "\nx value for playerShip must be bigger than 0 and smaller than 1178");
    if (y < 0 or y > 878) throw std::runtime_error("invalid y value for Playership in file: " + filename + "\nx value for playerShip must be bigger than 0 and smaller than 878");
    auto playership = std::make_shared<entities::playership::PlayerShip>(x,y);
    player = playership;
    playership->subscribe(dynamic_cast<entities::Observer*>(this));
    auto playershipView = std::make_shared<entities::playership::PlayerShipView>(playership);
    auto playershipController = std::make_shared<entities::playership::PlayerShipController>(playership, playershipView, (*this));
    addObject(std::make_tuple(std::move(playership), std::move(playershipView), std::move(playershipController)));


    // ENEMIES
    enemiesToDefeat = 0;
    for (auto enemy:root["Enemies"])
    {
        enemiesToDefeat++;
        if (enemy["type"] == "PurpleAlien")
        {
            auto projectile = std::make_shared<entities::enemies::purple_alien::PurpleAlien>(enemy["x"], int(enemy["y"]) + 50);
            auto view = std::make_shared<entities::enemies::purple_alien::PurpleAlienView>(projectile);
            auto controller = std::make_shared<entities::enemies::purple_alien::PurpleAlienController>(projectile, view, (*this));

            addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }
        else if (enemy["type"] == "GreenAlien")
        {
            auto projectile = std::make_shared<entities::enemies::green_alien::GreenAlien>(enemy["x"], int(enemy["y"]) + 50);
            auto view = std::make_shared<entities::enemies::green_alien::GreenAlienView>(projectile);
            auto controller = std::make_shared<entities::enemies::green_alien::GreenAlienController>(projectile, view, (*this));

            addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }
        else if (enemy["type"] == "RedAlien")
        {
            auto projectile = std::make_shared<entities::enemies::red_alien::RedAlien>(enemy["x"], int(enemy["y"]) + 50);
            auto view = std::make_shared<entities::enemies::red_alien::RedAlienView>(projectile);
            auto controller = std::make_shared<entities::enemies::red_alien::RedAlienController>(projectile, view, (*this));

            addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }
        else
        {
            throw std::runtime_error("unknow enemy type: " + std::string(enemy["type"]) + " in file: " + filename);
        }
    }
    running = true;
}

bool World::isRunning() const
{
    return running;
}

uint World::getEnemiesDefeated() const
{
    return enemiesDefeated;
}

uint World::getEnemiesToDefeat() const
{
    return enemiesToDefeat;
}

bool World::isLevelCompleted() const
{
    return levelCompleted;
}

World::~World()=default;

