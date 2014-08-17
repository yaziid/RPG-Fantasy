#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "Map.hpp"

class Game
{
public :

    Game();
    void run();
    void handlePlayerInput(sf::Keyboard key, bool isPressed);

private :

    void processEvents();
    void update(sf::Time);
    void render();

private :

    sf::RenderWindow mWindow;
    Map mMap;

};

#endif // GAME_HPP_INCLUDED
