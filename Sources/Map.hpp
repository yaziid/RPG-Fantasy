#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class Map
{
public :
    void load(std::string filename, sf::RenderTarget& target);

private :

    sf::Texture mTileTexture;
    sf::Sprite mTiles;
    int m_tilewidth;
    int m_tileheight;
};

#endif // MAP_HPP_INCLUDED
