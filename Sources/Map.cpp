#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Map.hpp"

sf::Time const TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() : mWindow(sf::VideoMode(800, 600, 32), "RPG Fantasy")
{

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        processEvents();
        update(TimePerFrame);
        while(timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::handlePlayerInput(sf::Keyboard key, bool isPressed)
{
}

void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed :
            mWindow.close();
            break;

        default :
            break;
        }
    }
}

void Game::update(sf::Time)
{
}

void Game::render()
{
    mWindow.clear();
    mMap.load("Maps/Test_1.txt", mWindow);
    mWindow.display();
}
